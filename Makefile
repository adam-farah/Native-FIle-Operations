all: tester.o
	cc -o tester tester.o
tester.o: tester.c
	cc -c tester.c
clean:
	rm -f *.o *~ core *~ tester
