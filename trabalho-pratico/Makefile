all: programa-principal


programa-principal: obj/programa-principal.o obj/common.o obj/user.o obj/driver.o obj/ride.o obj/cat_users.o
		gcc -g obj/programa-principal.o obj/common.o obj/user.o obj/driver.o obj/ride.o obj/cat_users.o -lglib-2.0 -o programa-principal



obj/common.o: src/common.c src/common.h
		gcc -Wall -g -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -c src/common.c -o obj/common.o

obj/user.o: src/user.c src/user.h obj/common.o
		gcc -Wall -g -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -c src/user.c -o obj/user.o

obj/ride.o: src/ride.c src/ride.h obj/common.o
		gcc -Wall -g -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -c src/ride.c -o obj/ride.o

obj/driver.o: src/driver.c src/driver.h obj/common.o
		gcc -Wall -g -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -c src/driver.c -o obj/driver.o

obj/cat_users.o: src/cat_users.c src/cat_users.h obj/common.o
		gcc -Wall -g -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -c src/cat_users.c -o obj/cat_users.o

obj/programa-principal.o: src/main.c
		gcc -Wall -g -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -c src/main.c -o obj/programa-principal.o

clean:
		rm obj/* programa-principal