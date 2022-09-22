#include <iostream>
#include <vector>
#include <fstream>
using std::ostream;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::ofstream;

#include "dayofyear.h"

namespace Ozbelen
{
    DayofYearSet::DayofYear::DayofYear(int d, int m)
    {
        //Constructor with 2 parameters
        day = d;
        month = m;
        auto res = inputValid();
        
        //Warning for invalid date
        if(res == false)
            cerr << "Invalid date!" <<endl;
    }
    DayofYearSet::DayofYear::DayofYear()
    {
        //No parameter constructor
        day = 1;
        month = 1;
        ++countObj;
    }
    DayofYearSet::DayofYearSet(const vector <DayofYear> &vec)
    {
        //Constructor with an vector parameter
        size = vec.size();
        used = size;
        arr = new DayofYear[size];

        for(int i = 0; i < size; i++)
            arr[i] = vec[i];
    }
    DayofYearSet::DayofYearSet(int capacity)
    {
        //Constructor with 1 parameter(capacity)
        size = capacity;
        used = 0;
        arr = new DayofYear[size];
    }
    DayofYearSet::DayofYearSet(const DayofYearSet &obj)
    {
        //Copy Constructor
        size = obj.getSize();
        used = obj.getUsed();
        arr = new DayofYear[size];

        for(int i = 0; i < size; i++)
            arr[i] = obj[i];
    }
    DayofYearSet& DayofYearSet::operator=(const DayofYearSet &obj)
    {
        //Assignment Operator
        if(size != obj.getSize())
        {
            delete [] arr;
            arr = new DayofYear[size];
        }

        size = obj.getSize();
        used = obj.getUsed();

        for(int i = 0; i < size; i++)
            arr[i] = obj[i];

        return *this;
    }
    ostream& operator<<(ostream &out, const DayofYearSet &obj)
    {
        //Stream insertion operator
        out << "Days in the set: " << endl;
        for(int i = 0; i < obj.getSize(); i++)
        {
            int month = obj[i].getMonth();
            switch (month)
            {
                case 1:
                    out << "January "; 
                    break;
                case 2:
                    out << "February "; 
                    break;
                case 3:
                    out << "March "; 
                    break;
                case 4:
                    out << "April "; 
                    break;
                case 5:
                    out << "May "; 
                    break;
                case 6:
                    out << "June ";
                    break;
                case 7:
                    out << "July "; 
                    break;
                case 8:
                    out << "August "; 
                    break;
                case 9:
                    out << "September "; 
                    break;
                case 10:
                    out << "October "; 
                    break;
                case 11:
                    out << "November "; 
                    break;
                case 12:
                    out << "December "; 
                    break;
            }
            out << obj[i].getDay();
            out << endl;
        } 
        return out;
    }
    bool operator==(const DayofYearSet &obj1, const DayofYearSet &obj2) 
    {
        //Overloaded comparison function
        int size1 = obj1.getSize();
        int size2 = obj2.getSize();
        int flag = 1;
        
        if(size1 != size2)
            return false;
        
        for(int i = 0; i < size2; i++)
        {
            if(obj1.doesExist(obj2[i].getMonth(), obj2[i].getDay()) == false)
            {
                flag = 0;
                break;
            }
        }
        if(flag == 0)
            return false;

        return true;
    }
    bool operator!=(const DayofYearSet &obj1, const DayofYearSet &obj2) 
    {
        return !(operator==(obj1, obj2));
    }
    void DayofYearSet::add(const DayofYear &obj)
    {
        if(getSize() == getUsed())
        {
            //If there is not an empty space then create new array with new capacity
            int s = getSize();
            DayofYear *temp = new DayofYear[s+1];

            for(int i = 0; i < s; i++)
                temp[i] = arr[i];
            temp[s] = obj;

            delete [] arr;
            arr = temp;
            ++size;
            ++used;
            countObj -= s;
        }
        else
        {
            //If there is an empty space then add new object
            arr[used] = obj;
            ++used;
            ++countObj;
        }
    }
    void DayofYearSet::remove(const DayofYear &obj)
    {
        //Create new array with new capacity and remove the object
        int s = getSize();
        DayofYear *temp = new DayofYear[s-1];
        
        int index = 0;
        for(int i = 0; i < s; i++)
        {
            if(!(arr[i].getMonth() == obj.getMonth() && arr[i].getDay() == obj.getDay()))
            {
                temp[index] = arr[i];
                ++index;
            }
        }

        delete [] arr;
        arr = temp;
        --size;

        countObj -= s;
    }
    DayofYearSet operator+(const DayofYearSet &obj1, const DayofYearSet &obj2)
    {
        //Overloaded fucntion returning union set
        int size1 = obj1.getSize();
        int size2 = obj2.getSize();
        int counter = size1;
        int index = size1;

        for(int i = 0; i < size2; i++)
        {
            if(obj1.doesExist(obj2[i].getMonth(), obj2[i].getDay()) == false)
                ++counter;
        }

        DayofYearSet n(counter);
        n.setUsed(counter);
        
        for(int j = 0; j < size1; j++)
        {
            n.arr[j] = obj1[j];
        }
        for(int k = 0; k < size2; k++)
        {
            if(obj1.doesExist(obj2[k].getMonth(), obj2[k].getDay()) == false)
            {
                n.arr[index] = obj2[k];
                ++index;
            }
        }

        return n;
    }
    DayofYearSet operator-(const DayofYearSet &obj1, const DayofYearSet &obj2)
    {
        //Overloaded fucntion returning difference of the sets
        int size1 = obj1.getSize();
        int index = 0;
        int counter = 0;

        for(int i = 0; i < size1; i++)
        {
            if(obj2.doesExist(obj1[i].getMonth(), obj1[i].getDay()) == true)
                ++counter;
        }

        DayofYearSet n(size1-counter);
        n.setUsed(size1-counter);
        
        for(int j = 0; j < size1; j++)
        {
            if(obj2.doesExist(obj1[j].getMonth(), obj1[j].getDay()) == false)
            {
                n.arr[index] = obj1[j];
                ++index;
            }
        }
        return n;
    }
    DayofYearSet operator^(const DayofYearSet &obj1, const DayofYearSet &obj2)
    {
        //Overloaded fucntion returning intersection of the sets
        int size1 = obj1.getSize();
        int index = 0;
        decltype(index) counter = 0;

        for(int i = 0; i < size1; i++)
        {
            if(obj2.doesExist(obj1[i].getMonth(), obj1[i].getDay()) == true)
                ++counter;
        }

        DayofYearSet n(counter);
        n.setUsed(counter);
        
        for(int j = 0; j < size1; j++)
        {
            if(obj2.doesExist(obj1[j].getMonth(), obj1[j].getDay()) == true)
            {
                n.arr[index] = obj1[j];
                ++index;
            }
        }
        return n;
    }
    DayofYearSet operator!(const DayofYearSet &obj)
    { 
        //Overloaded fucntion returning complement of the set
        DayofYearSet n(365-obj.getSize());
        for(int i = 1; i <= 12; i++)
        {
            if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
            {
                for(int j = 1; j <= 31; j++)
                {
                    if(obj.doesExist(i, j) == false)
                    {
                        DayofYearSet::DayofYear newd(j, i);
                        n.add(newd);
                    }
                }
            }
            else if(i == 4 || i == 6 || i == 9 || i == 11)
            {
                for(int j = 1; j <= 30; j++)
                {
                    if(obj.doesExist(i, j) == false)
                    {
                        DayofYearSet::DayofYear newd(j, i);
                        n.add(newd);
                    }
                }
            }
            else
            {
                for(int j = 1; j <= 28; j++)
                {
                    if(obj.doesExist(i, j) == false)
                    {
                        DayofYearSet::DayofYear newd(j, i);
                        n.add(newd);
                    }
                }
            }
        }
        return n;
    }
    const DayofYearSet::DayofYear DayofYearSet::operator[](int index) const 
    {
        return arr[index];
    }
    bool DayofYearSet::doesExist(int m, int d) const
    {
        //Order : Month, Day
        //Find out if the given date is in the set
        for(int i = 0; i < size; i++)
        {
            if(arr[i].getMonth() == m && arr[i].getDay() == d)
                return true;
        }
        return false;
    }
    bool DayofYearSet::DayofYear::inputValid() const
    {
        //Input validation for dates
        if(getMonth() > 12 || getMonth() < 1)
            return false;
        if((getMonth() == 1 || getMonth() == 3 || getMonth() == 5 || getMonth() == 7 ||
        getMonth() == 8 || getMonth() == 10 || getMonth() == 12) && (getDay() > 31 || getDay() < 1))
            return false;
        if((getMonth() == 4 || getMonth() == 6 || getMonth() == 9 || 
        getMonth() == 11) && (getDay() > 30 || getDay() < 1))
            return false;
        if(getMonth() == 2 && (getDay() > 28 || getDay() < 1))
            return false;
        return true;
    }
    void DayofYearSet::fileop()
    {
        //Write sets on a text file
        ofstream fileio;
        fileio.open("sets.txt", std::ios_base::app);
        fileio << "Set:" << endl;
        for(int i = 0; i < getSize(); i++)
            fileio << arr[i].getDay() << "." << arr[i].getMonth() << endl;

        fileio.close();

        cout << "File operation done" << endl;
    }
    DayofYearSet::~DayofYearSet()
    {
        //Destructor
        delete [] arr;
    }
}
