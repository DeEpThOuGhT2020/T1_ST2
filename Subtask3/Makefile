all: yourcode.out ;

yourcode.out: main.o matrix_and_vector_functions.o inp_oup.o
	g++ -o yourcode.out main.o matrix_and_vector_functions.o inp_oup.o

main.o: main.cpp inp_oup.h matrix_and_vector_functions.h
	g++ -c main.cpp

matrix_and_vector_functions.o: matrix_and_vector_functions.cpp
	g++ -c matrix_and_vector_functions.cpp

inp_oup.o: inp_oup.cpp
	g++ -c inp_oup.cpp

clean:
	rm -f yourcode.out *.o