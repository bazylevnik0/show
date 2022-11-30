make: qdbmp.c rust.c mold.c
	gcc -o qdbmp.o -c qdbmp.c
	gcc -o rust.out rust.c qdbmp.o
	gcc -o mold.out mold.c qdbmp.o
	sudo apt install ffmpeg