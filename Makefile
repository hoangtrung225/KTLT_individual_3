all: StudentList.o
	gcc -std=c99 -g PointerToArray.c StudentList.o -o PointerToArray
StudentList.o: StudentList.c
	gcc -std=c99 -g -c StudentList.c
clean:
	rm *.o PointerToArray
