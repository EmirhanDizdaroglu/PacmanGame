# Pacman Oyunu (Basit Sürüm)

Bu proje, klasik bir Pacman tarzı oyununun temel işleyişini C dilinde simüle eden bir oyundur. Pacman karakterini bir matris üzerinde yönlendirerek puan toplamak ve duvarlardan kaçmak amacını taşır.

## Özellikler

- **Dinamik Oyun Alanı**: Oyunun oyun alanı, rastgele sayılarla doldurulmuş bir matris üzerinde temsil edilir.
- **Pacman'ın Hareketi**: Pacman, yukarı, aşağı, sola ve sağa hareket edebilir.
- **Duvarlar ve Yiyecekler**: 
  - Duvarlar, matrisin değerleri 5'ten küçük olan hücrelerde bulunur ve Pacman bu hücrelere hareket edemez.
  - Yiyecekler, matrisin değerleri 5 veya daha büyük olan hücrelerde bulunur ve Pacman bu hücrelere hareket ettiğinde puan kazanır.
- **Oyun Sonu**: Pacman'ın hareket edebileceği geçerli bir yer kalmazsa oyun sona erer ve toplam puan ekranda görüntülenir.

## Kurulum

Bu proje C dilinde yazılmıştır ve herhangi bir C derleyicisi ile çalıştırılabilir. Aşağıdaki adımları izleyerek projeyi derleyip çalıştırabilirsiniz:

1. **Kodun İndirilmesi**:
    ```bash
    git clone https://github.com/kullaniciadi/pacman-game.git
    cd pacman-game
    ```

2. **Derleme**:
    ```bash
    gcc -o pacman game.c
    ```

3. **Çalıştırma**:
    ```bash
    ./pacman
    ```

## Kullanım

- Oyuna başladıktan sonra, Pacman'ı yönlendirmek için `W` (yukarı), `S` (aşağı), `A` (sol) veya `D` (sağ) tuşlarına basabilirsiniz.
- Pacman'ı hareket ettirerek matris üzerinde yiyecekleri toplayın ve puan kazanın.
- Duvarlar (W) Pacman'ın geçemeyeceği engellerdir.
- Oyun, hareket edebileceğiniz geçerli bir yer kalmadığında sona erer ve toplam puan ekranda gösterilir.

## Kodun İşleyişi

- **`initializeMatrix`**: Matrisi rastgele değerlerle doldurur.
- **`printMatrix`**: Matrisin ve Pacman'ın mevcut konumunun ekranda görüntülenmesini sağlar.
- **`getUserInput`**: Kullanıcının hareket yönünü alır.
- **`hasValidMove`**: Pacman'ın geçerli bir hareket yapıp yapamayacağını kontrol eder.
- **`main`**: Oyunun ana işleyişini kontrol eder, kullanıcı girişlerini işler ve oyunun bitiş koşullarını kontrol eder.

