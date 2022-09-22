#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#include "EightPuzzle.h"

using std::string;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::cerr;

namespace Ozbelen
{
    EightPuzzle::EightPuzzle(int type) : BoardGame2D(type)
    {
        //Constructor with one parameter
        initialize();
    }
    void EightPuzzle::initialize()
    {
        //Board initialization
        int random_num;
        int checkArr[9] = {0};
        arr = new int[3][3];

        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                do
                {
                    random_num = rand()%(3*3);
                }
                while(checkArr[random_num] != 0);
                //Create unique random number array by checking whether this number is already taken
                    
                checkArr[random_num] = 1; 
                //Change the flag of number to indicate that this number is taken
                
                arr[i][j] = random_num;
            }
        }	
    }
    string EightPuzzle::getUserIn()
    {
        //Get input from the user
        bool flag = false;
        string inp;
        do
        {
            do
            {
                cout << "Please enter row, column and direction (as RC-D, e.g. 12-R):";
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
    void EightPuzzle::getRandomIn()
    {
        //Get input randomly
        bool res;
        int col = 3;
        int row = 3;
        string userIn;
        do
        {
            int random1 = rand()%col + 49;
            int random2 = rand()%row + 49;
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
    bool EightPuzzle::setInput()
    {
        int col = 3, row = 3;
        string inp = getInput();
        //Checks the validation of input string digit by digit
        if (inp.size() != 4)
            return false;
        if (!(static_cast <int> (inp[0]) >= 49 && static_cast <int> (inp[0]) < row+49))
            return false;
        if (!(static_cast <int> (inp[1]) >= 49 && static_cast <int> (inp[1]) < col+49))
            return false;
        if (inp[2] != '-')
            return false;
        if (!(inp[3] == 'R' || inp[3] == 'L' || inp[3] == 'U' || inp[3] == 'D'))
            return false;
        
        return true;
    }
    bool EightPuzzle::movementValid()
    {
        //Check the validation of the given movement 
        string inp = getInput();
        int row = static_cast <int> (inp[0]) - 49;
        int col = static_cast <int> (inp[1]) - 49;
        char dir = inp[3];
        int emptyx, emptyy;

        for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
            {
				if(arr[i][j] == 0)
				{
					emptyx = i;
					emptyy = j;
				}
			}
		}	

        //This function checks the cells around the block
        switch(dir)
        {
            case 'R':
                if(emptyx == row && col != 3 - 1 && col < emptyy) 
                    return true;
                break;
            case 'L':
                if(emptyx == row && col != 0 && col > emptyy) 
		            return true;
                break;
            case 'U':
                if(emptyy == col && row != 0 && row > emptyx) 
                    return true;
                break;
            case 'D':	
                if(emptyy == col && row != 3 - 1 && row < emptyx) 
                    return true;
                break;
        }		
        return false;
    }
    void EightPuzzle::move()
    {
        string inp = getInput();
        int row = static_cast <int> (inp[0]) - 49;
        int col = static_cast <int> (inp[1]) - 49;
        char dir = inp[3];
        int emptyx, emptyy;

        for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
            {
				if(arr[i][j] == 0)
				{
					emptyx = i;
					emptyy = j;
				}
			}
		}	

        switch(dir)
        {
            case 'R':
                for(int i = emptyy; i > col; i--)
			        arr[emptyx][i] = arr[emptyx][i-1];
		        arr[row][col] = 0;
                break;
            case 'L':
                for(int i = emptyy; i < col; i++)
                    arr[emptyx][i] = arr[emptyx][i+1];
                arr[row][col] = 0;
                break;
            case 'U':
                for(int i = emptyx; i < row; i++)
			        arr[i][emptyy] = arr[i+1][emptyy];
		        arr[row][col] = 0;
                break;
            case 'D':	
                for(int i = emptyx; i > row; i--)
			        arr[i][emptyy] = arr[i-1][emptyy];
		        arr[row][col] = 0;
                break;
        }		
        ++score;
    }
    bool EightPuzzle::endGame()
    {
        int checkArr[3][3];
        int count = 1, check = 0;
        //Create a solved puzzle
        for(int i = 0; i < 3; i++) 
        {
            for(int j = 0; j < 3; j++)
            {
                if(count != 9)
                    checkArr[i][j] = count;
                else
                    checkArr[i][j] = 0;
                count++;
            }
        }	
        
        /*Compare all numbers in the puzzle*/
        for(int i = 0; i < 3; i++) 
        {
            for(int j = 0; j < 3; j++)
            {
                if(checkArr[i][j] == arr[i][j])
                    check++;
            }
        }	
        
        if(check == 9)
            return true;
            
        return false;		
    }
    void EightPuzzle::print()
    {
        cout << "\x1b[2J"; 
        cout << "\033[0;0H"; // move cursor to 0,0
        cout << endl << endl;

        cout << endl;
        int k = 0, l = 0;
        for(int i = -1; i <= 2*3 - 1; i++)
        {
            for(int j = -1; j <= 2*3 - 1; j++)
            {
                //Print the borders with *'s 
                if(i == -1 || i % 2 == 1) 
                    cout << "*  ";
                else if(j == -1 || j % 2 == 1)
                    cout << "* ";	
                else
                {
                    if(arr[k][l] == 0)
                        cout << "    "; //Not to print start location number which is 0
                    else
                        cout << " " << arr[k][l]<< "  ";
                    l++;	
                }
            }
            cout << endl;
            if(i % 2 == 0)
            {
                k++;
                l = 0;
            }
	    }
        if(getType() == 2)
        {
            cout << endl;
            cout << getInput() << " is the movement done randomly." << endl;
            cout << endl;
        }
    }
    ostream& operator<<(ostream &out, const EightPuzzle &obj)
    {
        cout << "\x1b[2J"; 
        cout << "\033[0;0H"; // move cursor to 0,0
        cout << endl << endl;

        out << endl;
        int k = 0, l = 0;
        for(int i = -1; i <= 2*3 - 1; i++)
        {
            for(int j = -1; j <= 2*3 - 1; j++)
            {
                //Print the borders with *'s 
                if(i == -1 || i % 2 == 1) 
                    out << "*  ";
                else if(j == -1 || j % 2 == 1)
                    out << "* ";	
                else
                {
                    if(obj.arr[k][l] == 0)
                        out << "    "; //Not to print start location number which is 0
                    else
                        out << " " << obj.arr[k][l]<< "  ";
                    l++;	
                }
            }
            out << endl;
            if(i % 2 == 0)
            {
                k++;
                l = 0;
            }
	    }
        if(obj.getType() == 2)
        {
            out << endl;
            out << obj.getInput() << " is the movement done randomly." << endl;
            out << endl;
        }
        return out;
    }
    EightPuzzle::~EightPuzzle()
    {
        //Destructor
        delete [] arr;
    }
}