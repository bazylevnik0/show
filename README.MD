BMP must be uncompressed 8, 24 or 32 BPP and without color space information

gcc -o qdbmp.o -c qdbmp.c
gcc show.c qdbmp.o
./a.out test.bmp
