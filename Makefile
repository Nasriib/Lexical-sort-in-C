all: csort.exe

# define a target to link the application
#
csort.exe: csort.o csort_00.o
        g++ -g -lm csort.o csort_00.o -o csort.exe

# define targets to compile the source code
#
csort.o: csort.cc sort.h  Makefile
        g++ -g -c csort.cc -o csort.o

csort_00.o: csort_00.cc  sort.h Makefile
        g++ -g -c csort_00.cc -o csort_00.o

# define a target to clean the directory
#
clean:
        rm -f csort.o csort_00.o csort.exe
