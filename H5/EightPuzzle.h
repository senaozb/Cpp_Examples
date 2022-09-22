#ifndef EIGHTPUZZLE_H
#define EIGHTPUZZLE_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#include "BoardGame2D.h"

using std::string;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::cerr;

namespace Ozbelen
{
    class EightPuzzle : public BoardGame2D
    {
        public:
            EightPuzzle(int type);
            void initialize();
            string getUserIn();
            void getRandomIn();
            bool setInput();
            bool movementValid();
            void move();
            bool endGame();
            void print();
            friend ostream& operator <<(ostream &out, const EightPuzzle &obj);
            ~EightPuzzle();
        private:
            int (*arr)[3];
    };
}

#endif
