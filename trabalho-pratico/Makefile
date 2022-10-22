all: programa-principal


programa-principal: obj/programa-principal.o
		gcc -g obj/programa-principal.o -o programa-principal

obj/programa-principal.o: src/main.c
		gcc -Wall -g -c src/main.c -o obj/programa-principal.o

clean:
		rm obj/* tmp/* bin/{aurras,aurrasd}
