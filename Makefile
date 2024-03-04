all: compile

compile: main.c
	cc main.c -o bsh

clean: bsh
	rm bsh
