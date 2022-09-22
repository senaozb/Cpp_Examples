#ifndef KLOTSKI_H
#define KLOTSKI_H

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
    class Klotski : public BoardGame2D
    {
        public:
            Klotski(int type);
            void initialize();
            bool endGame();
            void move();
            string getUserIn();
            void getRandomIn();
            bool setInput();
            bool movementValid();
            void print();
            friend ostream& operator <<(ostream& out, const Klotski &obj);
            ~Klotski();
        private:
            char (*arr) [4];
    };
}

#endif
