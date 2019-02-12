all: run

run: phanson_prog1.c phanson_argtok.c
	gcc phanson_prog1.c phanson_argtok.c -o prac
