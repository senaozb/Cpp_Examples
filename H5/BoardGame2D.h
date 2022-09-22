#ifndef BOARDGAME2D_H
#define BOARDGAME2D_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <thread>

using std::string;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

namespace Ozbelen
{
    class BoardGame2D
    {
        public:
            BoardGame2D(int type);
            virtual void initialize() = 0;
            void playUser(string inp);
            void playUser();
            void playAuto();
            void playAutoAll();
            virtual string getUserIn() = 0;
            virtual void getRandomIn() = 0;
            virtual bool setInput() = 0;
            virtual bool movementValid() = 0;
            virtual void move() = 0;
            virtual bool endGame() = 0;
            virtual void print() = 0;
            int getType() const {return gameType;} 
            string getInput() const {return input;}
            int boardScore() const {return score;}
            ~BoardGame2D();
        protected:
            int gameType;
            int score;
            string input;
    };
}

#endif
