#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#include "Klotski.h"

using std::string;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::cerr;

namespace Ozbelen
{
    Klotski::Klotski(int type) : BoardGame2D(type)
    {
        //Constructor with one parameter
        initialize();
    }
    void Klotski::initialize()
    {
        //Board initialization
        vector <vector <char> > vec = {{'a', 'z', 'z', 'b'},
                                        {'a', 'z', 'z', 'b'},
                                        {'c', 'd', 'd', 'e'},
                                        {'c', 'f', 'g', 'e'},
                                        {'h', ' ', ' ', 'i'}};

        arr = new char[5][4];

        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                arr[i][j] = vec[i][j];
            }
        }
    }
    string Klotski::getUserIn()
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
    void Klotski::getRandomIn()
    {
        //Get input randomly
        bool res;
        int col = 4;
        int row = 5;
        string userIn;
        do
        {
            int random1 = rand()%row + 49;
            int random2 = rand()%col + 49;
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
    bool Klotski::setInput()
    {
        int col = 4, row = 5;
        string inp = getInput();
        //Check the validation of input string digit by digit
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
    bool Klotski::movementValid()
    {
        //Check the validation of the given movement 
        string inp = getInput();
        int row = static_cast <int> (inp[0]) - 49;
        int col = static_cast <int> (inp[1]) - 49;
        char dir = inp[3];
        char type = arr[row][col];

        if(type == ' ')
            return false;

        //This function checks the cells around the block
        switch(dir)
        {
            case 'R':
                if(type == 'a' || type == 'b' || type == 'c' || type == 'e')
                {
                    if(arr[row+1][col] == type && arr[row+1][col+1] != ' ') 
                        return false;
                    if(arr[row-1][col] == type && arr[row-1][col+1] != ' ') 
                        return false;
                }
                else if(type == 'z')
                {
                    if(arr[row][col+1] == type)
                    {
                        if(arr[row+1][col] == type && arr[row+1][col+2] != ' ') 
                            return false;
                        if(arr[row-1][col] == type && arr[row-1][col+2] != ' ') 
                            return false;
                    }
                    else if(arr[row][col-1] == type)
                    {
                        if(arr[row+1][col] == type && arr[row+1][col+1] != ' ') 
                            return false;
                        if(arr[row-1][col] == type && arr[row-1][col+1] != ' ') 
                            return false;
                    }
                }
                if(arr[row][col+1] != type && arr[row][col+1] == ' ') 
                    return true;
                else if(arr[row][col+1] == type && arr[row][col+2] == ' ') 
                    return true;
                break;
            case 'L':
                if(type == 'a' || type == 'b' || type == 'c' || type == 'e')
                {
                    if(arr[row+1][col] == type && arr[row+1][col-1] != ' ')
		                return false;
                    if(arr[row-1][col] == type && arr[row-1][col-1] != ' ')
		                return false;
                }
                else if(type == 'z')
                {
                    if(arr[row][col+1] == type)
                    {
                        if(arr[row+1][col] == type && arr[row+1][col-1] != ' ')
                            return false;
                        if(arr[row-1][col] == type && arr[row-1][col-1] != ' ')
                            return false;
                    }
                    else if(arr[row][col-1] == type)
                    {
                        if(arr[row+1][col] == type && arr[row+1][col-2] != ' ')
                            return false;
                        if(arr[row-1][col] == type && arr[row-1][col-2] != ' ')
		                    return false;
                    }
                }
                if(arr[row][col-1] != type && arr[row][col-1] == ' ') 
                    return true;
                else if(arr[row][col-1] == type && arr[row][col-2] == ' ') 
                    return true;
                break;
            case 'U':
                if(type == 'd')
                {
                    if(arr[row][col+1] == type && arr[row-1][col+1] != ' ')
                        return false;
                    if(arr[row][col-1] == type && arr[row-1][col-1] != ' ')
                        return false;
                }
                else if(type == 'z')
                {
                    if(arr[row+1][col] == type)
                    {
                        if(arr[row][col+1] == type && arr[row-1][col+1] != ' ')
                            return false;
                        if(arr[row][col-1] == type && arr[row-1][col-1] != ' ')
                            return false;
                    }
                    else if(arr[row-1][col] == type)
                    {
                        if(arr[row][col+1] == type && arr[row-2][col+1] != ' ')
                            return false;
                        if(arr[row][col-1] == type && arr[row-2][col-1] != ' ')
                            return false;
                    }
                }
                if(arr[row-1][col] != type && arr[row-1][col] == ' ') 
                    return true;
                else if(arr[row-1][col] == type && arr[row-2][col] == ' ') 
                    return true;
                break;
            case 'D':
                if(type == 'd')
                {
                    if(arr[row][col+1] == type && arr[row+1][col+1] != ' ') 
                        return false;
                    if(arr[row][col-1] == type && arr[row+1][col-1] != ' ') 
                        return false;
                }
                else if(type == 'z')
                {
                    if(arr[row+1][col] == type)
                    {
                        if(arr[row][col+1] == type && arr[row+2][col+1] != ' ') 
                            return false;
                        if(arr[row][col-1] == type && arr[row+2][col-1] != ' ') 
                            return false;
                    }
                    else if(arr[row-1][col] == type)
                    {
                        if(arr[row][col+1] == type && arr[row+1][col+1] != ' ') 
                            return false;
                        if(arr[row][col-1] == type && arr[row+1][col-1] != ' ') 
                            return false;
                    }
                }
                if(arr[row+1][col] != type && arr[row+1][col] == ' ') 
                    return true;
                else if(arr[row+1][col] == type && arr[row+2][col] == ' ')
                    return true;
                break;
        }		
        return false;
    }
    void Klotski::move()
    {
        string inp = getInput();
        int row = static_cast <int> (inp[0]) - 49;
        int col = static_cast <int> (inp[1]) - 49;
        char dir = inp[3];
        char type = arr[row][col];

        //To move the blocks as a whole, this function checks the cells around it and find the locations belonging to the block
        switch(dir)
        {
            case 'R':
                if(type == 'a' || type == 'b' || type == 'c' || type == 'e')
                {
                    if(arr[row+1][col] == type) 
                    {
                        arr[row+1][col+1] = type;
		                arr[row+1][col] = ' ';
                    }
                    else if(arr[row-1][col] == type) 
                    {
                        arr[row-1][col+1] = type;
		                arr[row-1][col] = ' ';
                    }
                    arr[row][col+1] = type;
		            arr[row][col] = ' ';
                }
                else if(type == 'd')
                {
                    if(arr[row][col+1] == type) 
                    {
                        arr[row][col+2] = type;
                        arr[row][col] = ' ';
                    }
                    else if(arr[row][col-1] == type) 
                    {
                        arr[row][col+1] = type;
		                arr[row][col-1] = ' ';
                    }
                }
                else if(type == 'z')
                {
                    if(arr[row][col+1] == type) 
                    {
                        arr[row][col+2] = type;
                        arr[row][col] = ' ';
                        if(arr[row+1][col] == type) 
                        {
                            arr[row+1][col+2] = type;
                            arr[row+1][col] = ' ';
                        }
                        else if(arr[row-1][col] == type) 
                        {
                            arr[row-1][col+2] = type;
                            arr[row-1][col] = ' ';
                        }
                    }
                    else if(arr[row][col-1] == type) 
                    {
                        arr[row][col+1] = type;
		                arr[row][col-1] = ' ';
                        if(arr[row+1][col] == type) 
                        {
                            arr[row+1][col+1] = type;
                            arr[row+1][col-1] = ' ';
                        }
                        else if(arr[row-1][col] == type) 
                        {
                            arr[row-1][col+1] = type;
                            arr[row-1][col-1] = ' ';
                        }
                    }
                }
                else
                {
                    arr[row][col+1] = type;
		            arr[row][col] = ' ';
                }
                break;
            case 'L':
                if(type == 'a' || type == 'b' || type == 'c' || type == 'e')
                {
                    if(arr[row+1][col] == type) 
                    {
                        arr[row+1][col-1] = type;
		                arr[row+1][col] = ' ';
                    }
                    else if(arr[row-1][col] == type) 
                    {
                        arr[row-1][col-1] = type;
		                arr[row-1][col] = ' ';
                    }
                    arr[row][col-1] = type;
		            arr[row][col] = ' ';
                }
                else if(type == 'd')
                {
                    if(arr[row][col+1] == type) 
                    {
                        arr[row][col+1] = ' ';
		                arr[row][col-1] = type;
                    }
                    else if(arr[row][col-1] == type) 
                    {
                        arr[row][col] = ' ';
		                arr[row][col-2] = type;
                    }
                }
                else if(type == 'z')
                {
                    if(arr[row][col+1] == type) 
                    {
                        arr[row][col+1] = ' ';
		                arr[row][col-1] = type;
                        if(arr[row+1][col] == type) 
                        {
                            arr[row+1][col+1] = ' ';
                            arr[row+1][col-1] = type;
                        }
                        else if(arr[row-1][col] == type) 
                        {
                            arr[row-1][col+1] = ' ';
                            arr[row-1][col-1] = type;
                        }
                    }
                    else if(arr[row][col-1] == type) 
                    {
                        arr[row][col] = ' ';
		                arr[row][col-2] = type;
                        if(arr[row+1][col] == type) 
                        {
                            arr[row+1][col-2] = type;
                            arr[row+1][col] = ' ';
                        }
                        else if(arr[row-1][col] == type) 
                        {
                            arr[row-1][col-2] = type;
                            arr[row-1][col] = ' ';
                        }
                    }
                }
                else
                {
                    arr[row][col-1] = type;
		            arr[row][col] = ' ';
                }
                break;
            case 'U':
                if(type == 'a' || type == 'b' || type == 'c' || type == 'e')
                {
                    if(arr[row+1][col] == type) 
                    {
                        arr[row-1][col] = type;
		                arr[row+1][col] = ' ';
                    }
                    else if(arr[row-1][col] == type) 
                    {
                        arr[row-2][col] = type;
		                arr[row][col] = ' ';
                    }
                }
                else if(type == 'd')
                {
                    if(arr[row][col+1] == type) 
                    {
                        arr[row-1][col+1] = type;
		                arr[row][col+1] = ' ';
                    }
                    else if(arr[row][col-1] == type) 
                    {
                        arr[row-1][col-1] = type;
		                arr[row][col-1] = ' ';
                    }
                    arr[row-1][col] = type;
		            arr[row][col] = ' ';
                }
                else if(type == 'z')
                {
                    if(arr[row][col+1] == type) 
                    {
                        if(arr[row+1][col] == type) 
                        {
                            arr[row+1][col+1] = ' ';
                            arr[row+1][col] = ' ';
                            arr[row-1][col+1] = type;
                            arr[row-1][col] = type;
                        }
                        else if(arr[row-1][col] == type) 
                        {
                            arr[row][col+1] = ' ';
                            arr[row][col] = ' ';
                            arr[row-2][col+1] = type;
                            arr[row-2][col] = type;
                        }
                    }
                    else if(arr[row][col-1] == type) 
                    {
                        if(arr[row+1][col] == type) 
                        {
                            arr[row+1][col-1] = ' ';
                            arr[row+1][col] = ' ';
                            arr[row-1][col-1] = type;
                            arr[row-1][col] = type;
                        }
                        else if(arr[row-1][col] == type) 
                        {
                            arr[row][col-1] = ' ';
                            arr[row][col] = ' ';
                            arr[row-2][col-1] = type;
                            arr[row-2][col] = type;
                        }
                    }
                }
                else
                {
                    arr[row-1][col] = type;
		            arr[row][col] = ' ';
                }
                break;
            case 'D':	
                if(type == 'a' || type == 'b' || type == 'c' || type == 'e')
                {
                    if(arr[row+1][col] == type) 
                    {
                        arr[row+2][col] = type;
		                arr[row][col] = ' ';
                    }
                    else if(arr[row-1][col] == type) 
                    {
                        arr[row+1][col] = type;
		                arr[row-1][col] = ' ';
                    }
                }
                else if(type == 'd')
                {
                    if(arr[row][col+1] == type) 
                    {
                        arr[row+1][col+1] = type;
		                arr[row][col+1] = ' ';
                    }
                    else if(arr[row][col-1] == type) 
                    {
                        arr[row+1][col-1] = type;
		                arr[row][col-1] = ' ';
                    }
                    arr[row+1][col] = type;
		            arr[row][col] = ' ';
                }
                else if(type == 'z')
                {
                    if(arr[row][col+1] == type) 
                    {
                        if(arr[row+1][col] == type) 
                        {
                            arr[row][col+1] = ' ';
                            arr[row][col] = ' ';
                            arr[row+2][col+1] = type;
                            arr[row+2][col] = type;
                        }
                        else if(arr[row-1][col] == type) 
                        {
                            arr[row-1][col+1] = ' ';
                            arr[row-1][col] = ' ';
                            arr[row+1][col+1] = type;
                            arr[row+1][col] = type;
                        }
                    }
                    else if(arr[row][col-1] == type) 
                    {
                        if(arr[row+1][col] == type) 
                        {
                            arr[row][col-1] = ' ';
                            arr[row][col] = ' ';
                            arr[row+2][col-1] = type;
                            arr[row+2][col] = type;
                        }
                        else if(arr[row-1][col] == type) 
                        {
                            arr[row-1][col-1] = ' ';
                            arr[row-1][col] = ' ';
                            arr[row+1][col-1] = type;
                            arr[row+1][col] = type;
                        }
                    }
                }
                else
                {
                    arr[row+1][col] = type;
		            arr[row][col] = ' ';
                }
                break;
        }		
        ++score;
    }
    bool Klotski::endGame()
    {
        int check = 0;
        //Check if the red square's location is true
        for(int i = 4; i < 5; i++) 
        {
            for(int j = 1; j < 3; j++)
            {
                if(arr[i][j] == 'z')
                    check++;
            }
        }	

        if(check == 2)
            return true;
        return false;
    }
    void Klotski::print()
    {
        cout << "\x1b[2J"; 
        cout << "\033[0;0H"; // move cursor to 0,0
        cout << endl << endl;

        cout << endl;
        int k = 0, l = 0;
        for(int i = -1; i <= 2*5 - 1; i++)
        {
            for(int j = -1; j <= 2*4 - 1; j++)
            {
                //Print the borders with *'s 
                if(i == -1 || i % 2 == 1) 
                    cout << "*  ";
                else if(j == -1 || j % 2 == 1)
                    cout << "* ";	
                else
                {
                    if(arr[k][l] == ' ')
                        cout << "    "; 
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
    ostream& operator<<(ostream &out, const Klotski &obj)
    {
        cout << "\x1b[2J"; 
        cout << "\033[0;0H"; // move cursor to 0,0
        cout << endl << endl;

        out << endl;
        int k = 0, l = 0;
        for(int i = -1; i <= 2*5 - 1; i++)
        {
            for(int j = -1; j <= 2*4 - 1; j++)
            {
                //Print the borders with *'s 
                if(i == -1 || i % 2 == 1) 
                    out << "*  ";
                else if(j == -1 || j % 2 == 1)
                    out << "* ";	
                else
                {
                    if(obj.arr[k][l] == ' ')
                        out << "    "; 
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
    Klotski::~Klotski()
    {
        //Destructor
        delete [] arr;
    }
}
