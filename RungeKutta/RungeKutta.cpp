#include <iostream>
using namespace std;

double f(double x, double y) {
    return x + y; 
}

void RungeKutta(double x0, double y0, double h, double x_end) {
    double x = x0;
    double y = y0;

    cout << "x: " << x << ", y: " << y << endl;
    while (x < x_end) {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h / 2, y + k1 / 2);
        double k3 = h * f(x + h / 2, y + k2 / 2);
        double k4 = h * f(x + h, y + k3);

        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6; 
        x += h; 

        cout << "x: " << x << ", y: " << y << endl;
    }
}

int main() {
    double x0 = 0.0;   
    double y0 = 1.0;   
    double h = 0.1;    
    double x_end = 1.0; 
    RungeKutta(x0, y0, h, x_end);

    return 0;
}