#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H

#include <iostream>
#include <vector>
#include <fstream>
using std::ostream;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::ofstream;

namespace Ozbelen
{
    class DayofYearSet
    {
        public:
            class DayofYear
            {
                public:
                    DayofYear(int d, int m);
                    DayofYear();
                    bool inputValid() const;
                    int getDay() const {return day;}
                    int getMonth() const {return month;}
                private:
                    int day;
                    int month;
            };
            DayofYearSet(const vector <DayofYear> &vec);
            DayofYearSet(int capacity);
            DayofYearSet(const DayofYearSet &obj);
            DayofYearSet& operator=(const DayofYearSet &obj);
            friend ostream& operator<<(ostream &out, const DayofYearSet &obj);
            friend bool operator==(const DayofYearSet &obj1, const DayofYearSet &obj2);
            friend bool operator!=(const DayofYearSet &obj1, const DayofYearSet &obj2);
            void add(const DayofYear &obj);
            void remove(const DayofYear &obj);
            int getSize() const {return size;}
            int getUsed() const {return used;}
            void setUsed(int u) {used = u;}
            friend DayofYearSet operator+(const DayofYearSet &obj1, const DayofYearSet &obj2);
            friend DayofYearSet operator-(const DayofYearSet &obj1, const DayofYearSet &obj2);
            friend DayofYearSet operator^(const DayofYearSet &obj1, const DayofYearSet &obj2);
            friend DayofYearSet operator!(const DayofYearSet &obj);
            const DayofYearSet::DayofYear operator[](int index) const;
            bool doesExist(int m, int d) const;
            void fileop();
            static int NumberofObjects(){return countObj;}
            static int countObj;
            ~DayofYearSet();
        private:
            DayofYear *arr;
            int size;
            int used;
    };
}

#endif 
