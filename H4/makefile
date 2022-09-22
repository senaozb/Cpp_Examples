target:	hw4

dayofyear:	dayofyear.h dayofyear.cpp
			g++ -std=c++11 -c dayofyear.cpp

main:	dayofyear.h main.cpp
			g++ -std=c++11 -c main.cpp


hw4:	main dayofyear
		g++ -std=c++11 dayofyear.o main.o -o hw4

clean:
		rm hw4