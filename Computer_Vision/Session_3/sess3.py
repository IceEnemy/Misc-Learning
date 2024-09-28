#Thresholding:
# Seperating foreground and background
# grayscale image is required
# checks the grayness of the pixel
# compares to our determined threshold value
# based on that value, it will decide the pixel's value

import cv2
import matplotlib.pyplot as plt


# Thresholding
# Algorithms: 
# 1. Binary
# 2. Binary Inverse
# 3. To Zero
# 4. To Zero Inverse
# 5. Trunc
# 6. Otsu

img_gray = cv2.imread('img.jpg', 0)
# cv2.imshow('Gray Image', img_gray)
# cv2.waitKey(0)
# cv2.destroyAllWindows()

# par 1: source image
# par 2: threshold value (1/2 max value of a pixel)
# par 3: max value of a pixel
# par 4: type of thresholding
# retval = same as thresholding (only used in Otsu)
_, img_binary = cv2.threshold(img_gray, 127, 255, cv2.THRESH_BINARY)
_, img_binary_inv = cv2.threshold(img_gray, 127, 255, cv2.THRESH_BINARY_INV)
_, img_tozero = cv2.threshold(img_gray, 127, 255, cv2.THRESH_TOZERO)
_, img_tozero_inv = cv2.threshold(img_gray, 127, 255, cv2.THRESH_TOZERO_INV)
_, img_trunc = cv2.threshold(img_gray, 127, 255, cv2.THRESH_TRUNC)
retval, img_otsu = cv2.threshold(img_gray, 127, 255, cv2.THRESH_OTSU)



# show all 6 images in a single window
# plt.figure(figsize=(10, 10))
# plt.subplot(2, 3, 1)
# plt.imshow(img_binary, cmap='gray')
# plt.subplot(2, 3, 2)
# plt.imshow(img_binary_inv, cmap='gray')
# plt.subplot(2, 3, 3)
# plt.imshow(img_tozero, cmap='gray')
# plt.subplot(2, 3, 4)
# plt.imshow(img_tozero_inv, cmap='gray')
# plt.subplot(2, 3, 5)
# plt.imshow(img_trunc, cmap='gray')
# plt.subplot(2, 3, 6)
# plt.imshow(img_otsu, cmap='gray')

# plt.show()

result_img = [img_binary, img_binary_inv, img_tozero, img_tozero_inv, img_trunc, img_otsu]
result_titles = ['Binary', 'Binary Inverse', 'To Zero', 'To Zero Inverse', 'Trunc', 'Otsu']

for idx, (img, title) in enumerate(zip(result_img, result_titles)):
    plt.subplot(2, 3, idx+1)
    plt.imshow(img, cmap='gray')
    plt.title(title)
    plt.axis('off')

plt.show()
cv2.waitKey(0)
cv2.destroyAllWindows()

# Filtering / Blurring
# - done to reduce noise in an image
# - it analyzes each pixel in the image
# - for each pixel, it analyzes the neighboring pixels
# - changes the value of the pixel based on the neighboring pixels

# Algorithms:
# 1. Mean
# 2. Median
# 3. Gaussian
# 4. Bilateral

img = cv2.imread('img.jpg')

# 11 x 11 kernel (has to be odd number and positive)
mean_img = cv2.blur(img, (11, 11))

# Median - square kernel size, so its only 1 number
median_img = cv2.medianBlur(img, 11)

# Gaussian - has standard deviation as a parameter
gaussian_img = cv2.GaussianBlur(img, (11, 11), 0)

# Bilateral - an extended version of Gaussian (check the color and kernel size)
# Bilateral has 2 extra parameters: sigmaColor and sigmaSpace
bilateral_img = cv2.bilateralFilter(img, 11, 120, 120)

result_blur = [mean_img, median_img, gaussian_img, bilateral_img]
blur_titles = ['Mean', 'Median', 'Gaussian', 'Bilateral']

for idx, (img, title) in enumerate(zip(result_blur, blur_titles)):
    plt.subplot(2, 2, idx+1)
    plt.imshow(cv2.cvtColor(img, cv2.COLOR_BGR2RGB))
    plt.title(title)
    plt.axis('off')

plt.show()
cv2.waitKey(0)
cv2.destroyAllWindows()