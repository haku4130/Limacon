#include "functions.h"
#include <iostream>

using namespace std;

double get_double(const char message[]){
    double n;
    cout << message;
    while (!(cin >> n).good()) {
        cout << "Incorrect number!\n";
        cout << message;
        cin.clear();
        cin.ignore(100, '\n');
    }
    cin.clear();
    cin.ignore(100, '\n');
    return n;
}

int get_int(const char message[]){
    int n;
    cout << message;
    while (!(cin >> n).good()) {
        cout << "Incorrect number!\n";
        cout << message;
        cin.clear();
        cin.ignore(100, '\n');
    }
    cin.clear();
    cin.ignore(100, '\n');
    return n;
}

void print_menu(){
    cout << "\n1. Radius depending on the angle.\n"
            "2. Radius of curvature at special points.\n"
            "3. Form type.\n"
            "4. Figure area.\n"
            "5. Equation in Cartesian coordinate system.\n"
            "6. Equation in Polar coordinate system.\n"
            "7. Set new coefficients.\n"
            "0. Exit.\n\n";
}

int get_menu_item(int min, int max) {
    int res = get_int("Select menu item: ");
    while (res < min || res > max){
        cout << "Invalid menu item.\n";
        res = get_int("Select menu item: ");
    }
    return res;
}

void menu(Curve limacon){
    print_menu();
    int choice;
    do {
        choice = get_menu_item(0, 7);
        char str [38 + limacon.special_number()];
        switch (choice) {
            case 1:
                cout << "Radius is: " << limacon.radius(get_double("Input \"theta\": ")) << endl;
                break;
            case 2:
                break;
            case 3:
                limacon.get_type();
                break;
            case 4:
                cout << "The area enclosed by the limacon is: " << limacon.get_area() << endl;
                break;
            case 5:
                limacon.get_cartesian_equation(str);
                cout << str << endl;
                break;
            case 6:
                limacon.get_polar_equation();
                break;
            case 7:
                limacon.set_koefs(get_double("Input \"a\": "), get_double("Input \"b\": "));
                break;
            default:
                break;
        }
    } while (choice);
}

int comp (double a, double b) {
    if (a == b) return 0;
    if (a > b) return 1;
    return 2;
}