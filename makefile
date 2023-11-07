all: stacktest stacktest_dbg stacktest2

stacktest: stacktest.o stack.o
	gcc -g stacktest.o stack.o -o stacktest

stacktest_dbg: stacktest_dbg.o stack.o
	gcc -g stacktest_dbg.o stack.o -o stacktest_dbg

stacktest.o: stacktest.c stack.h
	gcc -g -c stacktest.c


stacktest2: stacktest2.o stack.o
	gcc -g stacktest2.o stack.o -o stacktest2

stacktest_dbg2: stacktest_dbg2.o stack.o
	gcc -g stacktest_dbg2.o stack.o -o stacktest_dbg2

stacktest2.o: stacktest2.c stack.h
	gcc -g -c stacktest2.c

stacktest_dbg.o: stacktest.c stack.h
	gcc -g -c -DDEBUG_TEST stacktest.c -o stacktest_dbg.o

stack.o: stack.c stack.h
	gcc -g -c stack.c

docs:
	doxygen
	cp -p html/* ~/public_html/cs2303_hw05

clean:
	rm -f *.o stacktest stacktest_dbg stacktest2
