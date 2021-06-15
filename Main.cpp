#include "NumberWithUnits.hpp"
// #include <stdio.h>
using namespace std;
int main()
{
    ifstream units_file{"units1.txt"};
    ariel::NumberWithUnits::read_units(units_file);

    ariel::NumberWithUnits hour1{1, "hour"};
    ariel::NumberWithUnits min2{2, "min"};
    ariel::NumberWithUnits min3{1.03333, "hour"};
    // ariel::NumberWithUnits day1{12, "day"};
    // ariel::NumberWithUnits min4{24 * 60 * 12 + 2, "min"};
    ariel::NumberWithUnits a(0,"hour");
    cout<<hour1<<endl;
    // cout<<min2+day1<<endl;
    //   cout<<day1+min2<<endl;
    cout<<min2+hour1<<endl;
    // if ( (min2 + day1) == min4)
    // {
    //     cout << "True" << endl;
    // }

    // cout<<min2+hour1<<endl;
    // cout<<hour1+min2<<endl;
    // cout<<day1+hour1<<endl;
    // cout<<hour1+day1<<endl;
    // if((hour1+min2) == min3)
    // {
    //     cout<<"True"<<endl;
    // }else
    // {
    //    cout<<"False"<<endl;
    // }
    // cout<<min3<<endl;
    // cout<< hour1+min2 <<endl;

    // cout<<(hour1+min2)==NumberWithUnits{1.033333,"hour"}<<endl;
    // ariel::NumberWithUnits a{2, "km"}; // 2 kilometers
    // cout << a << endl;                 // Prints "2[km]".
    // cout << (-a) << endl;              // Prints "-2[km]"
    // cout << (3 * a) << endl;           // Prints "6[km]"

    // ariel::NumberWithUnits b{300, "m"}; // 300 meters
    // cout << (a + b) << endl;            // Prints "2.3[km]". Note: units are determined by first number (a).
    // cout << (b - a) << endl;            // Prints "-1700[m]". Note: units are determined by first number (b).

    // cout << boolalpha;                                        // print booleans as strings from now on:
    // cout << (a > b) << endl;                                  // Prints "true"
    // cout << (a <= b) << endl;                                 // Prints "false"
    // cout << (a == ariel::NumberWithUnits{2000, "m"}) << endl; // Prints "true"
    // cout << (a != a) << endl;

    // istringstream sample_input{"700 [ kg ]"};
    // sample_input >> a;
    // cout << a << endl;   // Prints "700[kg]"
    // cout << (a += ariel::NumberWithUnits{1, "ton"}) << endl;  // prints "1700[kg]"
    // cout << a << endl;   // Prints "1700[kg]". Note that a has changed.
}