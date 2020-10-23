#include <iostream>

using namespace std;

const double h = 0.1;
double x0 = .0;

double ui1 = 2.0, ui2 = -1.0;

double ut1 = .0, ut2 = .0;
double u1 = .0, u2 = .0;

double f2(double u, double x);

int main()
{
    
    for (int i = 1; i <= 10; i++) {
        ut1 = ui1 + h * ui2;
        ut2 = ui2 + h * f2(ui2, x0);

        u1 = ui1 + h * (ui2 + ut2) / 2;
        u2 = ui2 + h * (f2(ui2, x0) + f2(ut2, x0 + h)) / 2;

        cout << u1 << "\n" << u2 << "\n\n";

        ui1 = u1;
        ui2 = u2;
        x0 += h;
    }
}

double f2(double u, double x) {
    return pow(u, 3) / (3 * x * u * u - 1);
}