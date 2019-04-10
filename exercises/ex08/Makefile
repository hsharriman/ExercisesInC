ex_compile: ex_compile.c
	gcc -Wall `pkg-config --cflags --libs glib-2.0` -o ex_compile ex_compile.c

word_count: word_count.c
	gcc -Wall `pkg-config --cflags --libs glib-2.0` -o word_count word_count.c
	./word_count pride.txt > prideout.txt

run:
	./ex_compile
