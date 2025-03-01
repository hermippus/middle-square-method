all:
	gcc -std=c99 src/main.c -o main

clean:
	rm -f main
