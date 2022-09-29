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

Curve::Curve(double a, double b){
    koef_a = a;
    koef_b = b;
}

void Curve::set_koefs(double a, double b){
    koef_a = a;
    koef_b = b;
}

void Curve::get_polar_equation() const{
    cout << "r = " << koef_b << " + " << koef_a << " * cos(theta)\n";
}

double Curve::radius(double theta) const {
    return (koef_b + koef_a * cos(theta));
}

void Curve::get_type() const{
    if (koef_a == 0){
        cout << "Circle.\n";
        return;
    }
    if (koef_a == 2 * koef_b){
        cout << "Trisectrix.\n";
        return;
    }
    int i = comp(koef_a, koef_b);
    if (i == 0) cout << "Cardioid.\n";
    else if (i == 1) cout << "With loop.\n";
    else cout << "Oval.\n";
}

double Curve::get_area() const{
    if (koef_b < koef_a) return (pow(koef_b, 2) + (pow(koef_a, 2) / 2)) * (acos(-koef_b / koef_a) + acos(koef_b / koef_a));
    return (pow(koef_b, 2) + (pow(koef_a, 2) / 2)) * M_PI;
}

unsigned long long Curve::special_number() const {
    string s1 = to_string(koef_a);
    string s2 = to_string(pow(koef_b, 2));
    return s1.length() + s2.length();
}

void Curve::get_cartesian_equation(char *res_char) const {
    string s1 = "(x^2 + y^2 - ";
    string s2 = to_string(koef_a);
    string s3 = " * x)^2 = ";
    string s4 = to_string(pow(koef_b, 2));
    string s5 = " * (x^2 + y^2)";
    string res = s1 + s2 + s3 + s4 + s5;
    strcpy(res_char, res.c_str());
}
