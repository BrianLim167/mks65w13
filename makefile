
all: pipeit.c
	gcc pipeit.c -o pipeit
run: all
	./pipeit
clean:
	rm -f *~
	rm -f *.o
