target:	hw5

BoardGame2D:	BoardGame2D.h BoardGame2D.cpp
			g++ -std=c++11 -c BoardGame2D.cpp

PegSolitaire:	PegSolitaire.h PegSolitaire.cpp
			g++ -std=c++11 -c PegSolitaire.cpp

EightPuzzle:	EightPuzzle.h EightPuzzle.cpp
			g++ -std=c++11 -c EightPuzzle.cpp

Klotski:		Klotski.h Klotski.cpp
			g++ -std=c++11 -c Klotski.cpp


main:	BoardGame2D.h PegSolitaire.h EightPuzzle.h Klotski.h main.cpp
			g++ -std=c++11 -c main.cpp


hw5:	main BoardGame2D PegSolitaire EightPuzzle Klotski
		g++ -std=c++11 BoardGame2D.o PegSolitaire.o EightPuzzle.o Klotski.o main.o -o hw5

clean:
		rm hw5