# Tic Tac Toe
Dalam artikel ini, kita akan belajar bagaimana mengembangkan permainan tic-tac-toe dalam C++. Tic-tac-toe adalah permainan yang dimainkan antara dua pemain biasanya dengan kertas dan pensil, tetapi di sini, kita akan membuat program C++ yang akan menampilkan permainan di layar konsol dan pemain dapat menggunakan tombol yang berbeda dari keyboard untuk memainkannya.

**Permainan Tic-Tac-Toe dalam C++**  
Sebelum kita mulai, mari kita pahami beberapa aturan untuk bermain permainan ini:

### Aturan Tic-Tac-Toe  
Berikut adalah aturan yang mendefinisikan bagaimana cara bermain permainan tic-tac-toe:

1. Seorang pemain hanya dapat menempatkan satu huruf X atau O di dalam grid 3x3 pada setiap giliran.
2. Kedua pemain akan bergiliran, satu setelah yang lain, sampai ada yang menang atau permainan berakhir seri.  
3. Untuk memenangkan permainan ini, pemain harus membuat sebuah garis horizontal, vertikal, atau diagonal yang terdiri dari tiga huruf yang sama.
4. Permainan berakhir seri, jika semua kotak terisi dengan huruf X atau O tetapi tidak ada garis yang terbentuk.

### Fitur Tic-Tac-Toe dalam C++  
Permainan ini memiliki fitur-fitur berikut:

1. Permainan ini dikembangkan pada grid 3x3.
2. Permainan ini dirancang untuk dua pemain.
3. Setiap pemain dapat memilih huruf antara X dan O.
4. Kedua pemain akan mendapatkan giliran secara bergantian.

### Komponen Permainan  
Permainan ini terdiri dari komponen-komponen berikut yang mencakup fungsi dan struktur data untuk memberikan operasi dasar permainan.

1. **Papan Permainan**  
Papan permainan dikelola oleh kelas `Board` yang berisi:

   - Sebuah grid karakter 3x3 untuk mewakili papan.
   - Sebuah penghitung untuk melacak sel yang terisi.

2. **Manajemen Pemain**  
Pemain diwakili oleh kelas `Player` yang menyimpan:

   - Simbol pemain (X atau O)
   - Nama pemain

3. **Gerakan Pemain**  
Kelas `Board` mencakup metode untuk menangani gerakan pemain:

   - `drawBoard()` untuk menampilkan keadaan papan saat ini
   - `isValidMove()` untuk memeriksa apakah gerakan valid
   - `makeMove()` untuk memperbarui papan dengan gerakan pemain

**Bagaimana cara memeriksa apakah input valid atau tidak?**

- Input valid: Jika sel kosong dan berada dalam batasan (0-2 untuk pelacakan internal, 1-3 untuk input pengguna)
- Input tidak valid: Jika sel sudah terisi dengan huruf lain atau berada di luar batas

4. **Logika Permainan**  
Kelas `TicTacToe` mengelola logika permainan secara keseluruhan:

   - Menangani giliran pemain
   - Memproses input pengguna
   - Memeriksa kondisi menang/seri

5. **Menang, Kalah, atau Seri**  
Kelas `Board` mencakup metode untuk memeriksa status permainan:

   - `checkWin()` untuk menentukan apakah pemain telah menang
   - `isFull()` untuk memeriksa apakah papan sudah penuh (seri)

Kondisi seri diperiksa dalam metode `play()` dari kelas `TicTacToe` ketika papan sudah penuh dan tidak ada pemain yang menang.

### Program C++ untuk Permainan Tic-Tac-Toe  
Berikut adalah kode lengkap untuk permainan Tic-Tac-Toe berbasis konsol yang sederhana dalam C++: