#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>

using namespace std;

class ConvertModel
{
private:
    double quantity;
    string type;
    double quantity_converted;
    string type_converted;

public:
    ConvertModel(double q, string t, double q_c, string t_c) : quantity(q), type(t), quantity_converted(q_c), type_converted(t_c){};
    double getQuantity()
    {
        return quantity;
    }
    string getType()
    {
        return type;
    }
    double getQuantityConverted()
    {
        return quantity_converted;
    }
    string getTypeConverted()
    {
        return type_converted;
    }
};