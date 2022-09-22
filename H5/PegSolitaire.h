#ifndef PEGSOLITAIRE_H
#define PEGSOLITAIRE_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#include "BoardGame2D.h"

enum class cell {empty, peg, out};

using std::string;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::cerr;

namespace Ozbelen
{
    class PegSolitaire : public BoardGame2D
    {
        public:
            class Cell
            {
                public:
                    Cell();
                    Cell(int a, int b, cell t);
            	    int coorR;
            	    int coorC;
                    cell ctype;
            };
            PegSolitaire(int type);
            void initialize();
            string getUserIn();
            void getRandomIn();
            bool setInput();
            bool movementValid();
            void move();
            bool endGame();
            int helpercheck(int indR, int indC, int locType);
            void print();
            friend ostream& operator <<(ostream &out, const PegSolitaire &obj);
            ~PegSolitaire();
        private:
            Cell (*arr)[9]; 
    };
}

#endif
