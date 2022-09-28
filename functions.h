#ifndef LAB2_CPP_FUNCTIONS_H
#define LAB2_CPP_FUNCTIONS_H

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

double get_double(const char message[]);
int get_int(const char message[]);
void print_menu();
int get_menu_item(int min, int max);
int comp (double a, double b);

class Curve {
private:
    double koef_a, koef_b;
public:
    Curve(double a, double b){
        koef_a = a;
        koef_b = b;
    }
    void set_koefs(double a, double b){
        koef_a = a;
        koef_b = b;
    }
    void get_polar_equation() const{
        cout << "r = " << koef_b << " + " << koef_a << " * cos(theta)\n";
    }
    double radius(double theta) const{
        return (koef_b + koef_a * cos(theta));
    }
    void get_type() const{
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
        else if (i == 2) cout << "Oval.\n";
    }
    double get_area() const{
        if (koef_b < koef_a) return (pow(koef_b, 2) + (pow(koef_a, 2) / 2)) * (acos(-koef_b / koef_a) + acos(koef_b / koef_a));
        return (pow(koef_b, 2) + (pow(koef_a, 2) / 2)) * M_PI;
    }
    unsigned long long special_number() const {
        string s1 = to_string(koef_a);
        string s2 = to_string(pow(koef_b, 2));
        return s1.length() + s2.length();
    }
    void get_cartesian_equation(char *res_char) const {
        string s1 = "(x^2 + y^2 - ";
        string s2 = to_string(koef_a);
        string s3 = " * x)^2 = ";
        string s4 = to_string(pow(koef_b, 2));
        string s5 = " * (x^2 + y^2)";
        string res = s1 + s2 + s3 + s4 + s5;
        strcpy(res_char, res.c_str());
    }
};

void menu(Curve limacon);

#endif