#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
// #include "ConvertModel.hpp"
#include <map>
using namespace std;
namespace ariel
{

    class NumberWithUnits
    {
        
    private:
        double a;
        string s;

    public:
        string getString()
        {
            return s;
        }
        double getNumber()
        {
            return a;
        }
        void setA(double b)
        {
            a = b;
        }
        void setString(string b)
        {
            s = b;
        }

        NumberWithUnits(double a, const string  & s);
        static void read_units(ifstream &file);
        friend NumberWithUnits operator+(const NumberWithUnits &a,const NumberWithUnits &b);

        // NumberWithUnits operator+();
        // NumberWithUnits operator++(int);
        // NumberWithUnits operator++();
        // NumberWithUnits operator--();
        // NumberWithUnits operator--(int);
        friend ostream &operator<<(ostream &os, NumberWithUnits sa);
        friend istream &operator>>(istream &sample_input, NumberWithUnits &a);

        // NumberWithUnits &operator-();
        NumberWithUnits  &operator-(NumberWithUnits a);

        friend bool operator<=(const NumberWithUnits a,const NumberWithUnits b);
        friend bool operator>=(NumberWithUnits a, NumberWithUnits b);

        friend bool operator>(const NumberWithUnits a, const NumberWithUnits b );
        friend bool operator<(NumberWithUnits a, NumberWithUnits b);
   
        NumberWithUnits &operator+=(NumberWithUnits a);
        NumberWithUnits operator-=(NumberWithUnits a);
    
        friend bool operator!=(const NumberWithUnits a, const NumberWithUnits b);

        friend  NumberWithUnits &operator*(NumberWithUnits  num , const double  copy);
        friend  NumberWithUnits &operator*(const double  copy, NumberWithUnits  num );
        friend  NumberWithUnits &operator*(const int copy, NumberWithUnits  num );
        friend  NumberWithUnits &operator*(NumberWithUnits  num , const int  copy);
       
        friend bool operator==(const NumberWithUnits a,const NumberWithUnits b);
    };

};
template <typename Out>
void split(const string &s, char delim, Out result);
vector<string> split(const string &s, char delim);