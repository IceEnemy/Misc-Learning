import cv2
import numpy as np
from matplotlib import pyplot as plt

# Image Read

img = cv2.imread('lena.jpg')

# Image Convert to Gray

img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

# 1. Canny Edge Detection
# Uses 2 threshold values to detect edges
# 100 for weak edges and 200 for strong edges

img_canny = cv2.Canny(img_gray, 100, 200)

# 2. Sobel Edge Detection
# Sobel X detects vertical edges, Sobel Y detects horizontal edges

sobel_x = cv2.Sobel(img_gray, cv2.CV_64F, 1, 0, ksize=3) # 1 for x-axis (vertical) and 0 for y-axis (horizontal)
sobel_y = cv2.Sobel(img_gray, cv2.CV_64F, 0, 1, ksize=3) # 0 for x-axis (vertical) and 1 for y-axis (horizontal)

# 3. Laplace Edge Detection
# Calculates the second derivative of the image to detect the difference of intensity between pixels

laplace = cv2.Laplacian(img_gray, cv2.CV_64F)

# Display the images

plt.figure(figsize=(12,8))

# Original Image
plt.subplot(2, 2, 1) # 2 rows, 2 columns, 1st position
plt.imshow(cv2.cvtColor(img, cv2.COLOR_BGR2RGB))
plt.title('Original Image')
# plt.axis('off')

# Canny Edge Detection Image
plt.subplot(2, 2, 2) # 2 rows, 2 columns, 2nd position
plt.imshow(img_canny, cmap='gray')
plt.title('Canny Edge Detection')
# plt.axis('off')

# Sobel Image
plt.subplot(2, 2, 3) # 2 rows, 2 columns, 3rd position
plt.imshow(sobel_x + sobel_y, cmap='gray')
plt.title('Sobel Edge Detection')
# plt.axis('off')

# Laplace Image
plt.subplot(2, 2, 4) # 2 rows, 2 columns, 4th position
plt.imshow(laplace, cmap='gray')
plt.title('Laplace Edge Detection')
# plt.axis('off')

plt.show()