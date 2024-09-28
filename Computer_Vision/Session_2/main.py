import cv2
import numpy as np
from matplotlib import pyplot as plt
# imread = image read
img = cv2.imread('mountain.jpg')

# Check if the image was loaded correctly
if img is None:
    print("Error: Image not found or cannot be loaded.")
else:
    # Optional --> resize image
    scale_percent = 20 / 100  # percent of original size

    # index 0 is for height, index 1 is for width
    width = int(img.shape[1] * scale_percent)
    height = int(img.shape[0] * scale_percent)

    # dim = dimension
    dim = (width, height)
    img = cv2.resize(img, dim, cv2.INTER_AREA)


    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    # image show
    # cv2.imshow('Original', img)
    # cv2.imshow('Gray', gray)
    # cv2.waitKey(0)
    # cv2.destroyAllWindows()


# count pixels for each intensity value

h = img.shape[0]
w = img.shape[1]

intensity_counter = np.zeros(256, dtype=int)

# loop through each pixel in the image
for i in range(h):
    for j in range(w):
        intensity_counter[gray[i, j]] += 1

# plotting
# plt.figure(1)
# plt.plot(intensity_counter, 'r', label='Mountain')
# plt.xlabel('Intensity Value')
# plt.ylabel('Pixels')
# plt.title('Intensity Histogram')
# plt.legend(loc = 'upper right')
# plt.show()

# equalization histogram
equ = cv2.equalizeHist(gray)
equ_intensity_counter = np.zeros(256, dtype=int)

# loop through each pixel in the image
for i in range(h):
    for j in range(w):
        equ_intensity_counter[equ[i, j]] += 1

# plotting
plt.figure(1, figsize=(16, 8))
# plot before equalization
# 1 line, 2 columns, 1st plot
plt.subplot(1,2,1)
plt.plot(intensity_counter, 'r', label='Mountain')
plt.xlabel('Intensity Value')
plt.ylabel('Pixels')
plt.title('Intensity Histogram')
plt.legend(loc = 'upper right')

# plot after equalization

plt.subplot(1,2,2)
plt.plot(equ_intensity_counter, 'b', label='After')
plt.xlabel('Intensity Value')
plt.ylabel('Pixels')
plt.title('Equalized Histogram')
plt.legend(loc = 'upper right')

plt.show()

res = np.hstack((gray, equ))  # stacking images side-by-side
cv2.imshow('Equalized Image', res)
cv2.waitKey(0)
cv2.destroyAllWindows()

