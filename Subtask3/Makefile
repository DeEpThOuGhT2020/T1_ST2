all: yourcode.out ;

yourcode.out: main.o matrix_and_vector_functions.o inp_oup.o libaudio.o
	g++ -o yourcode.out main.o matrix_and_vector_functions.o inp_oup.o libaudio.o

main.o: main.cpp inp_oup.h libaudio.so
	g++ -L/home/anaadk/IITD/Commits/T1_ST2/Subtask3 -Wl,-rpath=/home/anaadk/IITD/Commits/T1_ST2/Subtask3 -Wall -c main.cpp -llibaudio

libaudio.so: libaudio.o
	g++ -shared -o libaudio.so libaudio.o

matrix_and_vector_functions.o: matrix_and_vector_functions.cpp
	g++ -c matrix_and_vector_functions.cpp

inp_oup.o: inp_oup.cpp libaudio.h
	g++ -c inp_oup.cpp

libaudio.o: libaudio.cpp libaudio.h inp_oup.h matrix_and_vector_functions.h
	g++ -c -Wall -Werror -fpic libaudio.cpp

clean:
	rm -f yourcode.out *.o