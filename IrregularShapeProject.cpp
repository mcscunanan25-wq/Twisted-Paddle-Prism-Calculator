#include <iostream>
#include <cmath>
using namespace std;

// Function for cross-sectional area
double area(double x, double w0, double k, double h) {
    double width = w0 + k * sin(x);
    return width * h;
}

// Simpson's Rule
double simpson(double a, double b, int n, double w0, double k, double h) {
    if (n % 2 != 0) n++; // make n even

    double dx = (b - a) / n;
    double sum = area(a, w0, k, h) + area(b, w0, k, h);

    for (int i = 1; i < n; i++) {
        double x = a + i * dx;

        if (i % 2 == 0)
            sum += 2 * area(x, w0, k, h);
        else
            sum += 4 * area(x, w0, k, h);
    }

    return (dx / 3) * sum;
}

int main() {
    double L, w0, k, h;
    int n;

    cout << "Twisted Paddle Prism Volume Calculator\n";

    cout << "Enter length (L): ";
    cin >> L;

    cout << "Enter base width (w0): ";
    cin >> w0;

    cout << "Enter twist factor (k): ";
    cin >> k;

    cout << "Enter height (h): ";
    cin >> h;

    cout << "Enter number of intervals (even number recommended): ";
    cin >> n;

    double volume = simpson(0, L, n, w0, k, h);

    cout << "\nEstimated Volume: " << volume << endl;

    return 0;
}