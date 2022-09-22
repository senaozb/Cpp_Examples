#include "dayofyear.h"
using Ozbelen::DayofYearSet;

int DayofYearSet::countObj = 0;

int main()
{
    //Order : Day, Month
    cout << "--------------------------------------" << endl;
    vector <Ozbelen::DayofYearSet::DayofYear> vec1 = {{14,1}, {22,12}, {3,2}};
    DayofYearSet obj1(vec1);
    vector <Ozbelen::DayofYearSet::DayofYear> vec2 = {{1,12}, {2,12}, {3,2}};
    DayofYearSet obj2(vec2);
    
    //File operation
    obj1.fileop();
    obj2.fileop();
    cout << "--------------------------------------" << endl;

    //Overloaded stream insertion operator
    cout << "Overloaded stream insertion operator" << endl;
    cout << "Set 1:" << endl;
    cout << obj1;
    cout << endl;
    cout << "Set 2:" << endl;
    cout << obj2;
    cout << "--------------------------------------" << endl;
    

    //Overloaded binary operator+
    cout << "Overloaded binary operator+" << endl;
    cout << endl;
    cout << "The result of obj1 + obj2:" << endl;
    DayofYearSet obj3 = obj1+obj2;
    cout << obj3;
    cout << "--------------------------------------" << endl;

    //Overloaded binary operator-
    cout << "Overloaded binary operator-" << endl;
    cout << endl;
    cout << "The result of obj1 - obj2:" << endl;
    DayofYearSet obj4 = obj1-obj2;
    cout << obj4;
    cout << "--------------------------------------" << endl;
    
    //Overloaded binary operator^
    cout << "Overloaded binary operator^" << endl;
    cout << endl;
    cout << "The result of obj1 ^ obj2:" << endl;
    DayofYearSet obj5 = obj1^obj2;
    cout << obj5;
    cout << "--------------------------------------" << endl;

    //Overloaded operator== and operator!=
    cout << "Overloaded operator== and operator!=" << endl;
    vector <Ozbelen::DayofYearSet::DayofYear> vec6 = {{14,1}, {22,12}, {3,2}};
    DayofYearSet obj6(vec6);

    cout << endl;
    cout << "Set 1:" << endl;
    cout << obj1;
    cout << endl;
    cout << "Set 6:" << endl;
    cout << obj6;

    cout << endl;
    cout << "The result of obj1 == obj6: ";
   
    bool res = (obj1 == obj6);
    if(res == true)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "The result of obj1 != obj6: ";
    res = (obj1 != obj6);
    if(res == true)
        cout << "True" << endl;
    else 
        cout << "False" << endl;
    cout << "--------------------------------------" << endl;

    //Member function add 
    cout << "Member function 'add' " << endl;
    cout << "Set 2:" << endl;
    cout << obj2;
    cout << endl;

    Ozbelen::DayofYearSet::DayofYear newdate(30,6);
    obj2.add(newdate);
    cout << "The result of obj2 + 30.6: " << endl;
    cout << obj2;
    cout << "--------------------------------------" << endl;

    //Member function remove
    cout << "Member function 'remove' " << endl;
    cout << endl;
    Ozbelen::DayofYearSet::DayofYear rmdate(1,12);
    obj2.remove(rmdate);
    cout << "The result of obj2 - 1.12: " << endl;
    cout << obj2;
    cout << "--------------------------------------" << endl;

    //Static total object counter function
    cout << "Number of total objects: " << obj1.NumberofObjects() << endl;
    cout << "--------------------------------------" << endl;


    //Overloaded unary operator!
    cout << "Overloaded unary operator!" << endl;
    cout << endl;
    vector <Ozbelen::DayofYearSet::DayofYear> vec7 = {{1,1}, {2,1}, {3,1}, {4,1}, {5,1}, {6,1}, {7,1}, {8,1}, {9,1}, {10,1},
                                                    {1,2}, {2,2}, {3,2}, {4,2}, {5,2}, {6,2}, {7,2}, {8,2}, {9,2}, {10,2},
                                                    {1,3}, {2,3}, {3,3}, {4,3}, {5,3}, {6,3}, {7,3}, {8,3}, {9,3}, {10,3},
                                                    {1,4}, {2,4}, {3,4}, {4,4}, {5,4}, {6,4}, {7,4}, {8,4}, {9,4}, {10,4},
                                                    {1,5}, {2,5}, {3,5}, {4,5}, {5,5}, {6,5}, {7,5}, {8,5}, {9,5}, {10,5},
                                                    {1,6}, {2,6}, {3,6}, {4,6}, {5,6}, {6,6}, {7,6}, {8,6}, {9,6}, {10,6},
                                                    {1,7}, {2,7}, {3,7}, {4,7}, {5,7}, {6,7}, {7,7}, {8,7}, {9,7}, {10,7},
                                                    {1,8}, {2,8}, {3,8}, {4,8}, {5,8}, {6,8}, {7,8}, {8,8}, {9,8}, {10,8},
                                                    {1,9}, {2,9}, {3,9}, {4,9}, {5,9}, {6,9}, {7,9}, {8,9}, {9,9}, {10,9},
                                                    {1,10}, {2,10}, {3,10}, {4,10}, {5,10}, {6,10}, {7,10}, {8,10}, {9,10}, {10,10},
                                                    {1,11}, {2,11}, {3,11}, {4,11}, {5,11}, {6,11}, {7,11}, {8,11}, {9,11}, {10,11},
                                                    {1,12}, {2,12}, {3,12}, {4,12}, {5,12}, {6,12}, {7,12}, {8,12}, {9,12}, {10,12}};
    DayofYearSet obj7(vec7);
    cout << "Set 7:" << endl;
    cout << obj7;
    cout << endl;
    cout << "The result of !obj7:" << endl;
    DayofYearSet obj8 = !obj7;
    cout << obj8;
    cout << "--------------------------------------" << endl;

    //De Morgan Rule
    cout << "De Morgan Rule" << endl;
    cout << endl;
    cout << "Set 1:" << endl;
    cout << obj1;
    cout << endl;
    cout << "Set 7:" << endl;
    cout << obj7;
    cout << endl;
    DayofYearSet obj9 = !(obj1 + obj7);
    cout << "The result of !(obj1 + obj7):" << endl;
    cout << obj9;
    cout << endl;
    DayofYearSet obj10 = !obj1 ^ !obj7;
    cout << "The result of !obj1 ^ !obj7:" << endl;
    cout << obj10;
    cout << endl;

    cout << "The result of !(obj1 + obj7) == !obj1 ^ !obj7 : ";
   
    res = (obj9 == obj10);
    if(res == true)
        cout << "True" << endl;
    else
        cout << "False" << endl;
    cout << "--------------------------------------" << endl;

    
    return 0;
}
