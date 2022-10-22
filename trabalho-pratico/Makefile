all: programa-principal


programa-principal: obj/programa-principal.o
		gcc -g obj/programa-principal.o -lglib-2.0 -o programa-principal

obj/programa-principal.o: src/main.c
		gcc -Wall -g -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -c src/main.c -o obj/programa-principal.o

clean:
		rm obj/* tmp/* bin/{aurras,aurrasd}
