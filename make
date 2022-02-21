# ./yourcode.out in console to compile all files and print their output to console
#all: yourcode.out ;

#yourcode.out: MKL.o Blas.o pthread.o
#g++ -o yourcode.out MKL.o Blas.o pthread.o

all: File_IOs MKL Blas pthread

File_IOs.o: File_IOs.cpp
	g++ -c File_IOs.cpp

MKL: MKL.cpp
	g++ -I/opt/intel/oneapi/mkl/2022.0.2/include MKL.cpp -lblas

Blas: Blas.cpp
	g++ -I/home/user/Downloads/OpenBLAS-develop Blas.cpp -lblas

pthread: pthread.cpp
	g++ pthread.cpp ./a.out

clean:
	rm -f yourcode.out *.o