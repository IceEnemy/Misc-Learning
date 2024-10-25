### for import and image preprocessing

import cv2 # Functions for computer vision
import os # Functions for interacting with files and directories
import numpy as np # Functions for numerical operations
import matplotlib.pyplot as plt # Functions for plotting

### Import Object.jpg
PATH = "dataset/"
obj = cv2.imread(PATH + "Object.jpg")
obj = cv2.cvtColor(obj, cv2.COLOR_BGR2RGB)

### Import all the data that we will be matching with
DATA_PATH = PATH + "Data/"
data = []
for file in os.listdir(DATA_PATH):
    print(file)
    img = cv2.imread(DATA_PATH + file)
    img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    data.append(img)

### Image Preprocessing
# THere are 3 Processes
# 1. Grayscale
# 2. Median Blur (reducing noise)
# 3. Equalize Histogram (increasing contrast and easier to read)

gray_obj = cv2.cvtColor(obj, cv2.COLOR_RGB2GRAY)
gray_obj = cv2.medianBlur(gray_obj, 3)
gray_obj = cv2.equalizeHist(gray_obj)

### Feature Matching 
# this will target keypoint and descriptor and will do matching with the image keypoint and descriptor
# 1. SIFT - ScaleInvariant Feature Transform
sift = cv2.SIFT_create()
# 2. ORB - Oriented FAST and Rotated BRIEF
orb = cv2.ORB_create()
# 3. AKAZE - Accelerated KAZE
akaze = cv2.AKAZE_create()

# Keypoints and descriptors of the tennis ball
target_keypoints, target_descriptors = orb.detectAndCompute(gray_obj, None)
target_descriptors = np.float32(target_descriptors)


# gray_data = [cv2.cvtColor(dat, cv2.COLOR_RGB2GRAY) for dat in data] 
# gray_data = [cv2.medianBlur(dat, 3) for dat in gray_data]
# gray_data = [cv2.equalizeHist(dat) for dat in gray_data]

# data_keypoints, data_descriptors = [sift.detectAndCompute(dat, None) for dat in gray_data]
# data_descriptors = [np.float32(dat) for dat in data_descriptors]

best_matches = 0


for dat in data:
    gray_data = cv2.cvtColor(dat, cv2.COLOR_RGB2GRAY)
    gray_data = cv2.medianBlur(gray_data, 3)
    gray_data = cv2.equalizeHist(gray_data)
    # data[i] = gray_data

    data_keypoints, data_descriptors = orb.detectAndCompute(gray_data, None)
    data_descriptors = np.float32(data_descriptors)

    # Feature Matching with 2 algorithms (Flann, KNN)
    flann = cv2.FlannBasedMatcher(dict(algorithm=1), dict(checks=50))
    match = flann.knnMatch(target_descriptors, data_descriptors, k=2)

    # Match Masking
    # This match has a lot of redundancies, because 1 imae can be very similar with other images, hence the lower accuracy
    # The algorithm is the Lowe's Ratio Test

    # Make a 2D array that consists of 0,0 along the length of the matches
    matchesMask = [[0,0] for i in range(0, len(match))]

    current_matches = 0

    # store the matches that are valid

    ### Lowe's Ratio Test
    # fm - first match
    # sm - second match
    for i, (fm, sm) in enumerate(match):
        if fm.distance < 0.7 * sm.distance:
            matchesMask[i] = [1, 0]
            current_matches += 1

    # Determing the best match, needs to compare a lot of valid matches

    if best_matches < current_matches:
        best_matches = current_matches
        best_matches_data = {
            'image_data': dat,
            'keypoints': data_keypoints,
            'descriptors': data_descriptors,
            'matches': match,
            'matchesMask': matchesMask
        }

# Plotting the best match
result = cv2.drawMatchesKnn(
    obj,
    target_keypoints,
    best_matches_data['image_data'],
    best_matches_data['keypoints'],
    best_matches_data['matches'],
    None,
    matchesMask=best_matches_data['matchesMask'],
    matchColor=(255, 0, 0),
    singlePointColor=(0, 0, 255)
)
plt.figure()
plt.imshow(result)
plt.title("Best Match")
plt.show()