.ONESHELL:
all:
	gcc -o tinyserver *.c -lpthread
	gcc -o cgi-bin/calc csapp.c cgi-bin/calc.c -lpthread
clean: 
	rm -f tinyserver
	rm -f cgi-bin/calc
run: all
	./tinyserver 8000 &
kill:
	killall tinyserver