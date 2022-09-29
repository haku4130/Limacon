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
    Curve(double, double);
    void set_koefs(double, double);
    void get_polar_equation() const;
    double radius(double) const;
    void get_type() const;
    double get_area() const;
    unsigned long long special_number() const;
    void get_cartesian_equation(char *res_char) const;
};

void menu(Curve limacon);

#endif
