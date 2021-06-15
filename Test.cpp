#include "doctest.h"
#include "NumberWithUnits.hpp"

#include <iostream>

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace ariel;

TEST_CASE("Good NumberWithUnits code")
{
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);

    NumberWithUnits weight0{80, "kg"};
    NumberWithUnits weight1{7, "kg"};
    NumberWithUnits sumOfWeight0{87, "kg"};
    NumberWithUnits sum0 = weight0 + weight1;
    NumberWithUnits sum1 = weight0 - weight1;
    NumberWithUnits sumOfWeight1{73, "kg"};
    CHECK(sum0 == sumOfWeight0);
    CHECK(weight1 != weight0);
    CHECK(sum1 == sumOfWeight1);

    NumberWithUnits a{2, "km"};
    NumberWithUnits b{2, "cm"};
    NumberWithUnits c{2.2, "km"};
    NumberWithUnits ans = a + b;
    CHECK(ans == c);
    CHECK(ans > a);
    CHECK(a != b);

    NumberWithUnits f{200000, "cm"};
    NumberWithUnits t{2, "km"};
    ans = b + a;
    CHECK(f == ans);
    ans = b - a;
    CHECK(f != ans);

    NumberWithUnits d{-2, "km"};
    a = -a;
    CHECK(a == d);

    d = -f;
    NumberWithUnits g{-200000, "cm"};
    CHECK(d == g);
    CHECK(d > g);

    b = 3 * a;
    NumberWithUnits e{6, "km"};
    CHECK(b == e);

    NumberWithUnits dis0{6, "km"};
    NumberWithUnits dis1{4, "km"};
    NumberWithUnits dis2{10, "km"};
    ans = dis0 + dis1;
    CHECK(ans > c);
    CHECK(ans != c);
    CHECK(dis2 == ans);
    CHECK(ans <= c);
    CHECK(dis0 != dis1);
 

    NumberWithUnits dis4{5, "km"};
    CHECK(dis1== dis4);
    CHECK(dis0 != dis0);
    CHECK(dis1 <=dis2);
}