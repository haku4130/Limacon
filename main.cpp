#include <iostream>
#include "functions.h"

using namespace std;

int main() {
    cout << "The equation of a limacon in polar coordinates has the form: r = b + a * cos(theta)\n";
    Curve limacon(get_double("Input \"a\": "), get_double("Input \"b\": "));
    menu(limacon);
    return 0;
}
