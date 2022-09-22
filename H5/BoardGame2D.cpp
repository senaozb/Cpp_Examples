#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <thread>

#include "BoardGame2D.h"

using std::string;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;
using std::vector; 

namespace Ozbelen
{
    BoardGame2D::BoardGame2D(int type)
                    : gameType(type), score(0), input("")
    {
        /*Intentionally empty*/
    }
    void BoardGame2D::playUser(string inp)
    {
        //One step playing
        move();
    }
    void BoardGame2D::playUser()
    {
        //Full game playing
        bool flag;
        print();
        do
        {
            string s = getUserIn();
            playUser(s);
            print();
            flag = endGame();
        }while(flag == false);

        cout << "Score: " << boardScore() << endl;;
    }
    void BoardGame2D::playAuto()
    {
        //One step playing automatically
        getRandomIn();
        move();
    }
    void BoardGame2D::playAutoAll()
    {
        //Full game playing automatically
        bool flag;
        do
        {
            playAuto();
            print();    
            flag = endGame();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }while(flag == false);

        cout << "Score: " << boardScore() << endl;;
    }
    BoardGame2D::~BoardGame2D()
    {
        /*Intentionally empty*/
    }
}
