scanner: main.c scan.c
	cc -o parser -g main.c scan.c tree.c expr.c interp.c

clean:
	rm -f parser *.o

run:
	./parser test/input