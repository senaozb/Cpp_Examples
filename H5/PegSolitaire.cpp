#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#include "PegSolitaire.h"

using std::string;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::cerr;

namespace Ozbelen
{
    PegSolitaire::Cell::Cell()
            : coorR(-1), coorC(-1), ctype(cell::out)
    {
        /*Intentionally empty*/
    }
    PegSolitaire::Cell::Cell(int r, int c, cell t)
            : coorR(r), coorC(c), ctype(t)
    {
        /*Intentionally empty*/
    }
    PegSolitaire::PegSolitaire(int type) : BoardGame2D(type)
    {
        //Constructor with one parameter
        initialize();
    }
    void PegSolitaire::initialize()
    {
        //Board initialization
        vector <vector <PegSolitaire::Cell> > vec = {{Cell(0, 0, cell::out), Cell(0, 1, cell::out), Cell(0, 2, cell::out), Cell(0, 3, cell::peg), Cell(0, 4, cell::peg), Cell(0, 5, cell::peg), Cell(0, 6, cell::out), Cell(0, 7, cell::out), Cell(0, 8, cell::out)},
                                                {Cell(1, 0, cell::out), Cell(1, 1, cell::out), Cell(1, 2, cell::out), Cell(1, 3, cell::peg), Cell(1, 4, cell::peg), Cell(1, 5, cell::peg), Cell(1, 6, cell::out), Cell(1, 7, cell::out), Cell(1, 8, cell::out)},
                                                {Cell(2, 0, cell::out), Cell(2, 1, cell::out), Cell(2, 2, cell::out), Cell(2, 3, cell::peg), Cell(2, 4, cell::peg), Cell(2, 5, cell::peg), Cell(2, 6, cell::out), Cell(2, 7, cell::out), Cell(2, 8, cell::out)},
                                                {Cell(3, 0, cell::peg), Cell(3, 1, cell::peg), Cell(3, 2, cell::peg), Cell(3, 3, cell::peg), Cell(3, 4, cell::peg), Cell(3, 5, cell::peg), Cell(3, 6, cell::peg), Cell(3, 7, cell::peg), Cell(3, 8, cell::peg)},
                                                {Cell(4, 0, cell::peg), Cell(4, 1, cell::peg), Cell(4, 2, cell::peg), Cell(4, 3, cell::peg), Cell(4, 4, cell::empty), Cell(4, 5, cell::peg), Cell(4, 6, cell::peg), Cell(4, 7, cell::peg), Cell(4, 8, cell::peg)},
                                                {Cell(5, 0, cell::peg), Cell(5, 1, cell::peg), Cell(5, 2, cell::peg), Cell(5, 3, cell::peg), Cell(5, 4, cell::peg), Cell(5, 5, cell::peg), Cell(5, 6, cell::peg), Cell(5, 7, cell::peg), Cell(5, 8, cell::peg)},
                                                {Cell(6, 0, cell::out), Cell(6, 1, cell::out), Cell(6, 2, cell::out), Cell(6, 3, cell::peg), Cell(6, 4, cell::peg), Cell(6, 5, cell::peg), Cell(6, 6, cell::out), Cell(6, 7, cell::out), Cell(6, 8, cell::out)},
                                                {Cell(7, 0, cell::out), Cell(7, 1, cell::out), Cell(7, 2, cell::out), Cell(7, 3, cell::peg), Cell(7, 4, cell::peg), Cell(7, 5, cell::peg), Cell(7, 6, cell::out), Cell(7, 7, cell::out), Cell(7, 8, cell::out)},
                                                {Cell(8, 0, cell::out), Cell(8, 1, cell::out), Cell(8, 2, cell::out), Cell(8, 3, cell::peg), Cell(8, 4, cell::peg), Cell(8, 5, cell::peg), Cell(8, 6, cell::out), Cell(8, 7, cell::out), Cell(8, 8, cell::out)}};

        arr = new Cell[9][9];

        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                arr[i][j] = vec[i][j];
            }
        }
    }
    string PegSolitaire::getUserIn()
    {
        //Get input from the user
        bool flag = false;
        string inp;
        do
        {
            do
            {
                cout << "Please enter row, column and direction (as RC-D, e.g. 4B-R):";
                cin >> inp;
                input = inp;
                flag = setInput();
                if(flag == false)
                    cerr << "Invalid Input" << endl;
            }
            while(flag == false);

            flag = movementValid();
            if(flag == false)
                cerr << "Invalid Movement" << endl;

        }while(flag == false);
        return inp;
    }
    void PegSolitaire::getRandomIn()
    {
        //Get input randomly
        bool res;
        int col = 9;
        int row = 9;
        string userIn;
        do
        {
            int random1 = rand()%col + 49;
            int random2 = rand()%row + 65;
            int ranFlag = rand()%4;
            char random;  

            switch(ranFlag)
            {
                case 0:
                    random = 'R';
                    break;
                case 1:
                    random = 'L';
                    break;
                case 2:
                    random = 'U';
                    break;
                case 3:
                    random = 'D';
                    break;
            }
                
            userIn = static_cast <char> (random1);
            userIn += static_cast <char> (random2);
            userIn += '-';
            userIn += random;
            
            input = userIn;                    
            res = movementValid();
        }while(res == false);
    }
    bool PegSolitaire::setInput()
    {
        int col = 9, row = 9;
        string inp = getInput();
        //Checks the validation of input string digit by digit
        if (inp.size() != 4)
            return false;
        if (!(static_cast <int> (inp[0]) >= 49 && static_cast <int> (inp[0]) < row+49))
            return false;
        if (!(static_cast <int> (inp[1]) >= 65 && static_cast <int> (inp[1]) < col+65))
            return false;
        if (inp[2] != '-')
            return false;
        if (!(inp[3] == 'R' || inp[3] == 'L' || inp[3] == 'U' || inp[3] == 'D'))
            return false;
        
        return true;
    }
    bool PegSolitaire::movementValid()
    {
        //Check the validation of given movement looking at the game board
        string inp = getInput();
        int row = static_cast <int> (inp[0]) - 49;
        int col = static_cast <int> (inp[1]) - 65;
        char dir = inp[3];
        int max_r = 8;
        int max_c = 8;
        
        if (arr[row][col].ctype == cell::out || arr[row][col].ctype == cell::empty)
            return false;
        
        //If there is no peg and empty cell after the chosen peg then return false
        if (dir == 'R')
        {
            if (max_c - col < 2)
                return false;
            if (!(arr[row][col+1].ctype == cell::peg && arr[row][col+2].ctype == cell::empty))
                return false;
        }
        else if (dir == 'L')
        {
            if (col < 2)
                return false;
            if (!(arr[row][col-1].ctype == cell::peg && arr[row][col-2].ctype == cell::empty))
                return false;
        }
        else if (dir == 'U')
        {
            if (row < 2)
                return false;
            if (!(arr[row-1][col].ctype == cell::peg && arr[row-2][col].ctype == cell::empty))
                return false;
        }
        else if (dir == 'D')
        {
            if (max_r - row < 2)
                return false;
            if (!(arr[row+1][col].ctype == cell::peg && arr[row+2][col].ctype == cell::empty))
                return false;
        }
        
        return true;
    }
    void PegSolitaire::move()
    {
        string inp = getInput();
        int row = static_cast <int> (inp[0]) - 49;
        int col = static_cast <int> (inp[1]) - 65;
        char dir = inp[3];

        //Change the position of the peg and remove one peg
        switch (dir)
        {
            case 'R':
                arr[row][col].ctype = cell::empty;
                arr[row][col+1].ctype = cell::empty;
                arr[row][col+2].ctype = cell::peg;
                break;
            case 'L':
                arr[row][col].ctype = cell::empty;
                arr[row][col-1].ctype = cell::empty;
                arr[row][col-2].ctype = cell::peg;
                break;
            case 'U':
                arr[row][col].ctype = cell::empty;
                arr[row-1][col].ctype = cell::empty;
                arr[row-2][col].ctype = cell::peg;
                break;
            case 'D':
                arr[row][col].ctype = cell::empty;
                arr[row+1][col].ctype = cell::empty;
                arr[row+2][col].ctype = cell::peg;
                break;
        }
    }
    bool PegSolitaire::endGame()
    {
        //Check if the game is finished or not
        int count = 0;
        int col = 9;
        int row = 9;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (arr[i][j].ctype == cell::peg) //Check around the peg if there are other pegs
                {   
                    if (i != 0 && j != 0 && i != row-1 && j != col-1)
                    {
                        if (!(arr[i][j+1].ctype != cell::peg && arr[i][j-1].ctype != cell::peg 
                            && arr[i+1][j].ctype != cell::peg && arr[i-1][j].ctype != cell::peg))
                        {
                            if (helpercheck(i, j, 0) == 0)
                                return false;
                            else
                                ++count;
                        }
                        else    
                            ++count;
                    }
                    else if (i == 0)
                    {
                        if (!(arr[i][j+1].ctype != cell::peg && arr[i][j-1].ctype != cell::peg 
                            && arr[i+1][j].ctype != cell::peg))
                        {
                            if (helpercheck(i, j, 1) == 0)
                                return false;
                            else
                                ++count;
                        }
                        else    
                            ++count;
                    }
                    else if (i == row-1)
                    {
                        if (!(arr[i][j+1].ctype != cell::peg && arr[i][j-1].ctype != cell::peg 
                            && arr[i-1][j].ctype != cell::peg))
                        {
                            if (helpercheck(i, j, 2) == 0)
                                return false;
                            else
                                ++count;
                        }
                        else    
                            ++count;
                    }
                    else if (j == 0)
                    {
                        if (!(arr[i][j+1].ctype != cell::peg && arr[i+1][j].ctype != cell::peg 
                            && arr[i-1][j].ctype != cell::peg))
                        {
                            if (helpercheck(i, j, 3) == 0)
                                return false;
                            else
                                ++count;
                        }
                        else    
                            ++count;
                    }
                    else if (j == col-1)
                    {
                        if (!(arr[i][j-1].ctype != cell::peg && arr[i+1][j].ctype != cell::peg 
                            && arr[i-1][j].ctype != cell::peg))
                        {
                            if (helpercheck(i, j, 4) == 0)
                                return false;
                            else
                                ++count;
                        }
                        else    
                            ++count;
                    }
                }
            }  
        }
        score = count;
        return true;
    }
    int PegSolitaire::helpercheck(int indR, int indC, int locType)
    {
        //This function checks the immovable situations for being stuck
        //locType indicates the location of peg to prevent the memory errors(e.g. 1.column or the last row)
        int count = 0, fl = 0;
        int col = 9;
        int row = 9;

        for (int j = 0; j < col; j++) //Full row control
        {
            if(arr[indR][j].ctype == cell::peg)
                ++count;
            else if(arr[indR][j].ctype == cell::empty) //If there is an empty area then reset counter
            {
                count = 0;
                fl = 1;
                break;
            }
        }
            
        if(fl == 0)
        {
            //Checks if up and down rows are empty, if not so returns 0
            for (int k = 0; k < col; k++)
            {
                if(locType == 0 || locType == 3 || locType == 4)
                {
                    if(arr[indR][k].ctype == cell::peg && (arr[indR-1][k].ctype == cell::peg || arr[indR+1][k].ctype == cell::peg))
                        return 0;  
                }
                else if(locType == 1)
                {
                    if(arr[indR][k].ctype == cell::peg && arr[indR+1][k].ctype == cell::peg)
                        return 0;  
                }
                else if(locType == 2)
                {
                    if(arr[indR][k].ctype == cell::peg && arr[indR-1][k].ctype == cell::peg)
                        return 0;  
                }
            }
            return count;
        }
            
        count = 0;
        for (int i = 0; i < row; i++) //Full column control
        {
            if(arr[i][indC].ctype == cell::peg)
                ++count;
            else if(arr[i][indC].ctype == cell::empty)
                return 0;
        }
        for (int l = 0; l < row; l++) //Checks if the right and left columns are empty
        {
            if(locType == 0 || locType == 1 || locType == 2)
            {
                if(arr[l][indC].ctype == cell::peg && (arr[l][indC-1].ctype == cell::peg || arr[l][indC+1].ctype == cell::peg))
                    return 0;  
            } 
            else if(locType == 3)
            {
                if(arr[l][indC].ctype == cell::peg && arr[l][indC+1].ctype == cell::peg)
                    return 0;  
            }
            else if(locType == 4)
            {
                if(arr[l][indC].ctype == cell::peg && arr[l][indC-1].ctype == cell::peg)
                    return 0;  
            }
        }
        return count;
    }
    void PegSolitaire::print()
    {
        cout << "\x1b[2J"; 
        cout << "\033[0;0H"; // move cursor to 0,0
        cout << endl << endl;

        int col = 9;
        int row = 9;
        //Print the letters for the first row
        for (int k = 0; k < col+2; k++)
        {
            if (k == 0 || k == 1)
                cout << " ";
            else 
                cout << static_cast <char> (95+k);
        }
        cout << endl;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (j == 0) //Print the numbers to order for each row
                    cout << i+1 << " ";
                if (arr[i][j].ctype == cell::empty)
                    cout << ".";
                else if (arr[i][j].ctype == cell::peg)
                    cout << "P";
                else if (arr[i][j].ctype == cell::out)
                    cout << " ";
            }
            cout << endl;    
        }

        if(getType() == 2)
        {
            cout << getInput() << " is the movement done randomly." << endl;
            cout << endl;
        }

    }
    ostream& operator<<(ostream &out, const PegSolitaire &obj)
    {
        cout << "\x1b[2J"; 
        cout << "\033[0;0H"; // move cursor to 0,0
        cout << endl << endl;

        int col = 9;
        int row = 9;
        //Print the letters for the first row
        for (int k = 0; k < col+2; k++)
        {
            if (k == 0 || k == 1)
                out << " ";
            else 
                out << static_cast <char> (95+k);
        }
        out << endl;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (j == 0) //Print the numbers to order for each row
                    out << i+1 << " ";
                if (obj.arr[i][j].ctype == cell::empty)
                    out << ".";
                else if (obj.arr[i][j].ctype == cell::peg)
                    out << "P";
                else if (obj.arr[i][j].ctype == cell::out)
                    out << " ";
            }
            out << endl;    
        }

        if(obj.getType() == 2)
        {
            out << obj.getInput() << " is the movement done randomly." << endl;
            out << endl;
        }
        return out;
    }
    PegSolitaire::~PegSolitaire()
    {
        //Destructor
        delete [] arr;
    }
}