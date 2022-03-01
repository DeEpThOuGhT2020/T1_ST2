# ./yourcode.out in console to compile all files and print their output to console
#all: yourcode.out ;

#yourcode.out: MKL.o Blas.o pthread.o
#g++ -o yourcode.out MKL.o Blas.o pthread.o

all:  MKL Blas pthread

MKL: MKL.cpp
	g++ -o MKL -I/opt/intel/oneapi/mkl/2022.0.0/include MKL.cpp -lblas 

Blas: Blas.cpp
	g++ -o Blas -I/opt/homebrew/Cellar/openblas/0.3.19/include Blas.cpp -lblas 

pthread: pthread.cpp 
	g++ -o pthread pthread.cpp

clean:
	rm -f yourcode.out *.o
