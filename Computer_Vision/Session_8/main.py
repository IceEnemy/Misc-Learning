import cv2
import numpy as np
import matplotlib.pyplot as plt
import os
from scipy.cluster.vq import *
from sklearn.preprocessing import StandardScaler
from sklearn.svm import LinearSVC

#Training
train_path = "Dataset/Train"
train_path_list = os.listdir(train_path)
labels = train_path_list

image_list = []
image_class_id = []

for index, class_path in enumerate(train_path_list):
    image_path_list = os.listdir(train_path + "/" + class_path)
    for image_path in image_path_list:
        image_list.append(os.path.join(train_path, class_path, image_path))
        image_class_id.append(index)

# print(image_list)
# print(image_class_id)

# Extract Features
sift = cv2.SIFT_create()
descriptor_list = []
for image in image_list:
    _, descriptor = sift.detectAndCompute(cv2.imread(image), None)
    descriptor_list.append(descriptor)

# Preprocessing
# All descriptors in the vstack becomes 1 huge array
# This is done to prepare for clustering kmeans
stacked_descriptor = descriptor_list[0]
for descriptor in descriptor_list[1:]:
    stacked_descriptor = np.vstack((stacked_descriptor, descriptor))

stacked_descriptor = np.float32(stacked_descriptor)


# Clustering
# K-means
# make clusters from all descriptors
# find the centroid of each cluster
# parameters -> descriptors, number of clusters, number of iterations
centroids, _ = kmeans(stacked_descriptor, 15, 30)

# Vector Quantization
# Prepare a histogram table the amount of visual words in each image
image_features = np.zeros((len(image_list), len(centroids)), "float32")
# VQ -> match each descriptor to the nearest centroid
for i in range(len(image_list)):
    words, _ = vq(descriptor_list[i], centroids)
    for word in words:
        image_features[i][word] += 1

# Scaling
# StandardScaler : Normalize the histograms
# remove the mean and scale to unit variance
# This makes data more suitable for the SVM classifier
std_scaler = StandardScaler().fit(image_features)
image_features = std_scaler.transform(image_features)

# Classifying and training
svc = LinearSVC()

svc.fit(image_features, np.array(image_class_id))


# Testing
test_path = "Dataset/Test"
test_path_list = os.listdir(test_path)
test_image_list = []

for image_path in test_path_list:
    test_image_list.append(os.path.join(test_path, image_path))

# Extract Features
test_descriptor_list = []
for image in test_image_list:
    _, descriptor = sift.detectAndCompute(cv2.imread(image), None)
    test_descriptor_list.append(descriptor)

test_feature = np.zeros((len(test_image_list), len(centroids)), "float32")

for i in range(len(test_image_list)):
    words, _ = vq(test_descriptor_list[i], centroids)
    for word in words:
        test_feature[i][word] += 1

std_scaler = StandardScaler().fit(test_feature)
test_feature = std_scaler.transform(test_feature)

result = svc.predict(test_feature)

for idx, (class_id, image) in enumerate(zip(result, test_image_list)):
    plt.subplot(2, 3, idx + 1)
    plt.title(labels[class_id])
    plt.imshow(cv2.cvtColor(cv2.imread(image), cv2.COLOR_BGR2RGB))
    plt.xticks([])
    plt.yticks([])

plt.show()