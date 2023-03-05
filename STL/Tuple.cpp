#include <iostream>
#include <tuple>

using namespace std;

/*
 * can store elements of different data types
 */

int main()
{
    tuple<int, string, float, bool> t;

    t = make_tuple(19, "saeed", 86.8, true); // notice the order
    cout << get<0>(t) << ' ' << get<1>(t) << endl; // 19 saeed

    // using 'get' to modify the values:
    get<1>(t) = "ahmed";
    cout << get<0>(t) << ' ' << get<1>(t) << endl; // 19 saeed

    cout << tuple_size<decltype(t)>::value << endl; // 4
    // very annoying and verbose :(

    // swap() => swap with different tuple

    int x;
    string name;
    float grade;
    bool b;
    tie(x, name, grade, b) = t; // extract the values in separate variables
    tie(x, name, ignore, b) = t; // to ignore some values => use 'ignore'

    tuple<string, double> t2 = make_tuple("saeed", 18.2);
    auto total = tuple_cat(t, t2); // concatenate them and return the result
    cout << get<4>(total) << endl; // saeed
    cout << get<5>(total) << endl; // 18.2

    return 0;
}