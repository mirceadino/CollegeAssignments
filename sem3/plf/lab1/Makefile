lista.o: lista.cpp lista.h
	g++ -std=c++11 lista.cpp -c -o lista.o

main.o: main.cpp
	g++ -std=c++11 main.cpp -c -o main.o

main: lista.o main.o
	g++ -std=c++11 main.o lista.o -o main

clean:
	rm *.o
	rm main
