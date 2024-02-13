myprog.exe: main.o assist_functions.o
	g++ main.o assist_functions.o -o myprog.exe

main.o: main.cpp assist_functions.h
	g++ -Wall -c main.cpp

assist_functions.o: assist_functions.cpp assist_functions.h
	g++ -Wall -c assist_functions.cpp

runapp: myprog.exe
	./myprog.exe

clean:
	rm -f *.o myprog.exe
