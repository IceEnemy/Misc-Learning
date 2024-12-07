# Perkenalan
# Image Retrieval adalah proses mencari gambar yang paling mirip dengan gambar uji (query image) dalam sebuah koleksi gambar.

# Membuat Program Image Retrieval Sederhana
# adalah ukuran kemiripan antara dua gambar. Semakin rendah nilai similarity index, semakin mirip kedua gambar tersebut.

# 1. Persiapkan library
#   - cv2   => untuk manipulasi gambar
#   - os    => untuk mengakses file dan directory
#   - scipy => untuk menghitung similarity index dengan euclidean distance
import cv2
import os
from scipy.spatial.distance import euclidean

# 2. Membuat flat histogram dari semua image di library kita
#   pertama, ambil semua imagenya 
#   kedua, buatkan histogram dengan ratio RGB agar lebih akurat
#   terakhir, kita perlu flatten histogramnya agar bisa digunakan untuk menghitung similarity indexnya

image_dir = 'image_library'
features = []

for filename in os.listdir(image_dir):
    img_name = filename.split('.')[0]
    img_bgr = cv2.imread(os.path.join(image_dir, filename))
    img_rgb = cv2.cvtColor(img_bgr, cv2.COLOR_BGR2RGB)

    # Histogram adalah representasi grafis yang nunjukin berapa banyak pixel pada tingkan kecerahan / warna tertentu di sebuah gambar
    # Buat histogram 3D dengan 8 bin per channel (R, G, B) untuk dapat informasi warna
    # Paremeters:
    # - img_rgb   : gambar yang akan dihitung histogramnya
    # - [0, 1, 2] : channel yang akan dihitung histogramnya (R, G, B)
    # - None      : mask yang akan digunakan untuk menghitung histogram
    # - [8, 8, 8] : jumlah bin per channel
    # - [0, 256]  : range nilai pixel
    
    hist = cv2.calcHist([img_rgb], [0, 1, 2], None, [8, 8, 8], [0, 256, 0, 256, 0, 256])

    # Normalisasi histogram mastiin rentang nilai konsisten terlepas dari ukuran gambar
    # ini penting agar similarity indexnya lebih akurat dan tidak terganggu oleh cahaya atau warna yang berbeda atau ukuaran gambar yang berbeda
    normalized_hist = cv2.normalize(hist, None)

    flat_hist = normalized_hist.flatten()

    features.append((img_name, flat_hist))

    # print(normalized_hist)

# 3. Membuat flat histogram dari test image
test_image_bgr = cv2.imread('image_test/Mordor-001.png')
test_image_rgb = cv2.cvtColor(test_image_bgr, cv2.COLOR_BGR2RGB)

test_hist = cv2.calcHist([test_image_rgb], [0, 1, 2], None, [8, 8, 8], [0, 256, 0, 256, 0, 256])
test_normalized_hist = cv2.normalize(test_hist, None)
test_flat_hist = test_normalized_hist.flatten()

# 4. Menghitung kemiripan image dan menampilkan hasilnya
results = []
for name, hist in features:
    distance = euclidean(test_flat_hist, hist)
    results.append((name, distance))

# Sprt dari similarity index terkecil (paling mirip) ke terbesar (paling tidak mirip)

sorted_results = sorted(results, key=lambda x: x[1])

for name, distance in sorted_results:
    print(f'{name}: {distance}')
