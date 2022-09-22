#include "BoardGame2D.h"
#include "PegSolitaire.h"
#include "EightPuzzle.h"
#include "Klotski.h"

int main()
{
    Ozbelen::PegSolitaire game1(2);
    game1.playAutoAll();
    Ozbelen::EightPuzzle game2(2); //Game might not be ended
    game2.playAutoAll();
    Ozbelen::Klotski game3(2); //Game might not be ended
    game3.playAutoAll();

    /*Ozbelen::PegSolitaire game4(1);
    game4.playUser();
    Ozbelen::EightPuzzle game5(1);
    game5.playUser();
    Ozbelen::Klotski game6(1); 
    game6.playUser();*/

    
    return 0;
}
