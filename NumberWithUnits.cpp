#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "NumberWithUnits.hpp"
#include <iterator>

using namespace ariel;
// vector<ConvertModel> NumberWithUnits::units;
const double Eps = 0.00001;
static map<string, map<string, double>> units;

NumberWithUnits::NumberWithUnits(double a, const string  & s)
{
    units.at(s);
    this->a = a;
    this->s = s;
}

NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits &first,const NumberWithUnits &second)
{
    double res = convert(second.getNumber() , second.getString() , first.getString());
    NumberWithUnits temp(res+first.getNumber(),first.getString());
    return temp;

    // string type = "";
    // NumberWithUnits *res = new NumberWithUnits{0, s};
    // if (getString() == other.getString())
    // {
    //     NumberWithUnits *res = new NumberWithUnits{a + other.getNumber(), s};
    //     return *res;
    // }
    // for (unsigned long i = 0; i < NumberWithUnits::units.size(); i++)
    // {
    //     ConvertModel curr = units[i];
    //     if (curr.getType() == s && curr.getTypeConverted() == other.getString())
    //     {
    //         quantity = curr.getQuantityConverted();
    //         type = curr.getTypeConverted();
    //     }
    // }
    // if (quantity == -1 || type != other.getString())
    // {
    //     cout << "Exception!!!!" << endl;
    //     return *res;
    // }
    // else
    // {
    //     NumberWithUnits *res = new NumberWithUnits{a + (other.getNumber() / quantity), s};
    //     return *res;
    // }
}

NumberWithUnits NumberWithUnits::operator+()
{
    NumberWithUnits b{a, s};
    return b;
}

NumberWithUnits NumberWithUnits::operator++(int)
{
    NumberWithUnits b{a, s};
    return b;
}

NumberWithUnits NumberWithUnits::operator++()
{

    return *this;
}

NumberWithUnits &NumberWithUnits::operator-(NumberWithUnits other)
{
    double quantity = -1;
    string type = "";
    bool flag = false;
    NumberWithUnits *res = new NumberWithUnits{0, s};
    return *res;
    if (getString() == other.getString())
    {
        NumberWithUnits *res = new NumberWithUnits{a - other.getNumber(), s};
        return *res;
    }
    for (unsigned long i = 0; i < NumberWithUnits::units.size(); i++)
    {
        ConvertModel curr = units[i];
        if (curr.getType() == s && curr.getTypeConverted() == other.getString())
        {
            quantity = curr.getQuantityConverted();
            type = curr.getTypeConverted();
        }
    }
    if (quantity == -1 || type != other.getString())
    {
        cout << "Exception" << endl;
        return *res;
    }
    else
    {
        NumberWithUnits *res = new NumberWithUnits{a - (other.getNumber() / quantity), s};
        return *res;
    }
}

NumberWithUnits &NumberWithUnits::operator-()
{
    NumberWithUnits *res = new NumberWithUnits{a * -1, s};
    return *res;
}

NumberWithUnits NumberWithUnits::operator--(int)
{
    return *this;
}

NumberWithUnits NumberWithUnits::operator--()
{
    return *this;
}

NumberWithUnits &NumberWithUnits::operator+=(NumberWithUnits other)
{
    double quantity = -1;
    string type = "";
    NumberWithUnits *res = new NumberWithUnits{0, s};
    return *res;
    if (getString() == other.getString())
    {
        NumberWithUnits *res = new NumberWithUnits{a + other.getNumber(), s};
        return *res;
    }
    for (unsigned long i = 0; i < NumberWithUnits::units.size(); i++)
    {
        ConvertModel curr = NumberWithUnits::units[i];
        if (curr.getType() == s && curr.getTypeConverted() == other.getString())
        {
            quantity = curr.getQuantityConverted();
            type = curr.getTypeConverted();
        }
    }
    if (quantity == -1 || type != other.getString())
    {
        cout << "Exception" << endl;
        return *res;
    }
    else
    {
        NumberWithUnits *res = new NumberWithUnits{a + (other.getNumber() / quantity), s};
        return *res;
    }
}

NumberWithUnits NumberWithUnits::operator-=(NumberWithUnits a)
{
    return a;
}

bool ariel::operator>(const NumberWithUnits a, const NumberWithUnits other)
{
    double quantity = -1;
    string type = "";
    if (a.getString() == other.getString())
    {
        return a.getNumber() > other.getNumber();
    }
    for (unsigned long i = 0; i < NumberWithUnits::units.size(); i++)
    {
        ConvertModel curr = NumberWithUnits::units[i];
        if (curr.getType() == a.getString() && curr.getTypeConverted() == other.getString())
        {
            quantity = curr.getQuantityConverted();
            type = curr.getTypeConverted();
        }
    }
    if (a.getNumber() > other.getNumber() / quantity)
    {
        return true;
    }
    return false;
}

bool ariel::operator<(NumberWithUnits a, NumberWithUnits b)
{
    return true;
}

bool ariel::operator<=(const NumberWithUnits a, const NumberWithUnits other)
{
    double quantity = -1;
    string type = "";
    if (a.getString() == other.getString())
    {
        return a.getNumber() <= other.getNumber();
    }
    for (unsigned long i = 0; i < NumberWithUnits::units.size(); i++)
    {
        ConvertModel curr = NumberWithUnits::units[i];
        if (curr.getType() == a.getString() && curr.getTypeConverted() == other.getString())
        {
            quantity = curr.getQuantityConverted();
            type = curr.getTypeConverted();
        }
    }
    if (a.getNumber() <= other.getNumber() / quantity)
    {
        return true;
    }
    return false;
}

bool ariel::operator==(const NumberWithUnits a, const NumberWithUnits b)
{
    double quantity = -1;
    string type = "";
    if (a.getString() == b.getString())
    {
        return (std::abs(a.getNumber() - b.getNumber()) <= 0.0001);
    }
    for (unsigned long i = 0; i < NumberWithUnits::units.size(); i++)
    {
        ConvertModel curr = NumberWithUnits::units[i];
        if (curr.getType() == a.getString() && curr.getTypeConverted() == b.getString())
        {

            quantity = curr.getQuantityConverted();
            type = curr.getTypeConverted();
        }
    }
    double eps = b.getNumber() / quantity;
    if (std::abs(a.getNumber() - eps) <= 0.0001)
    {
        return true;
    }
    return false;
}

bool ariel::operator!=(const NumberWithUnits a, const NumberWithUnits other)
{
    double quantity = -1;
    string type = "";
    if (a.getString() == other.getString())
    {
        return a.getNumber() != other.getNumber();
    }
    for (unsigned long i = 0; i < NumberWithUnits::units.size(); i++)
    {
        ConvertModel curr = NumberWithUnits::units[i];
        if (curr.getType() == a.getString() && curr.getTypeConverted() == other.getString())
        {
            quantity = curr.getQuantityConverted();
            type = curr.getTypeConverted();
        }
    }
    if (a.getNumber() != other.getNumber() / quantity)
    {
        return true;
    }
    return false;
}

bool ariel::operator>=(NumberWithUnits a, NumberWithUnits b)
{
    return true;
}

NumberWithUnits &ariel::operator*(NumberWithUnits num, const double copy)
{
    NumberWithUnits *c = new NumberWithUnits{num.getNumber() * copy, num.getString()};
    return *c;
}
NumberWithUnits &ariel::operator*(const double copy, NumberWithUnits num)
{
    NumberWithUnits *c = new NumberWithUnits{num.getNumber() * copy, num.getString()};
    return *c;
}
NumberWithUnits &ariel::operator*(NumberWithUnits num, const int copy)
{
    NumberWithUnits *c = new NumberWithUnits{num.getNumber() * copy, num.getString()};
    return *c;
}
NumberWithUnits &ariel::operator*(const int copy, NumberWithUnits num)
{
    NumberWithUnits *c = new NumberWithUnits{num.getNumber() * copy, num.getString()};
    return *c;
}

std::ostream &ariel::operator<<(std::ostream &os, NumberWithUnits a)
{
    os << a.getNumber() << "[" << a.getString() << "]";
    return os;
}
istream &ariel::operator>>(istream &stream, NumberWithUnits &num)
{
    char c;
    char d;
    stream >> num.a >> c >> num.s >> d;
    return stream;
}

static double convert(double val, const string &first_unit, const string &second_unit)
{
    if (units[first_unit].count(second_unit) == 0)
    {
        throw("dont same !!");
    }
    if (first_unit == second_unit)
    {
        return val;
    }
    return val * units[first_unit][second_unit];
}

void NumberWithUnits::read_units(ifstream &file)
{
    string line;
    vector<string> vec;

    while (getline(file, line))
    {
        vec.push_back(line);
    }
    file.close();

    vector<string> temp;
    map<string, double> tempMap;
    for (unsigned i = 0; i < vec.size(); i++)
    {
        temp = split(vec[i], ' ');
        double quantity = stod(temp[0]);
        string type = temp[1];
        double quantityConverted = stod(temp[3]);
        string typeConverted = temp[4];
        if (units[type].empty())
        {
            units[type][typeConverted] = quantityConverted;
        }
    }

    for (unsigned i = 0; i < vec.size(); i++)
    {
        temp = split(vec[i], ' ');
        double quantity = stod(temp[0]);
        string type = temp[1];
        double quantityConverted = stod(temp[3]);
        string typeConverted = temp[4];
        if (units[typeConverted].empty())
        {
            units[typeConverted][type] = quantity / quantityConverted;
        }
    }

    // for (unsigned long i = 0; i < vec.size(); i++)
    // {
    //     temp = split(vec[i], ' ');
    //     double quantity = stod(temp[0]);
    //     string type = temp[1];
    //     double quantityConverted = stod(temp[3]);
    //     string typeConverted = temp[4];
    //     ConvertModel convertModel(quantity, type, quantityConverted, typeConverted);
    //     ConvertModel convertModelR(quantityConverted / quantity, typeConverted, quantity / quantityConverted, type);
    //     NumberWithUnits::units.push_back(convertModel);
    //     NumberWithUnits::units.push_back(convertModelR);
    // }
}

template <typename Out>
void split(const string &s, char delim, Out result)
{
    istringstream iss(s);
    string item;
    while (getline(iss, item, delim))
    {
        *result++ = item;
    }
}

vector<string> split(const string &s, char delim)
{
    vector<string> elems;
    split(s, delim, back_inserter(elems));
    return elems;
}
