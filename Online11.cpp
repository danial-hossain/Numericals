#include <bits/stdc++.h>
using namespace std;

double horners(int arr[], int degree, double x)
{
    double sum = arr[0];
    for (int i = 1; i <= degree; i++)
    {
        sum = sum * x + arr[i];
    }
    return sum;
}

double equation(double h)
{
    // Polynomial: 2x⁴ - 5x³ + 15x² - 25x + 5
    int degree = 4;
    int arr[degree + 1] = {2, -5, 15, -25, 5};
    return horners(arr, degree, h);
}

double differentiation(double h)
{
    // Derivative: 8x³ - 15x² + 30x - 25
    return 8 * h * h * h - 15 * h * h + 30 * h - 25;
}

double root(double x)
{
    double y = x - (equation(x) / differentiation(x));
    return y;
}

int main()
{
    double x0 = 3.5;
    double x1;
    double relative_error = 1;
    int steps = 0;

    cout << "************************************************************************************************" << endl;
    cout << "Iteration ||     prev_T     ||        T        ||      f(T)      ||     f'(T)     || Relative_error" << endl;

    while (0.000001 < relative_error)
    {
        steps++;

        double ex = equation(x0);
        double xe = differentiation(x0);

        cout << "    " << steps << "     ||  "
             << x0 << "     ||  ";

        x1 = root(x0);

        cout << x1 << "     ||  "
             << ex << "     ||  "
             << xe << "     ||  ";

        if (relative_error == 1)
        {
            cout << "N/A";
        }
        else
        {
            cout << relative_error;
        }

        relative_error = fabs((x1 - x0) / x1);
        cout << endl;

        x0 = x1;
    }

    cout << "************************************************************************************************" << endl;
    cout << "Final Temperature (approx): " << x1 << " degree Fahrenheit";
}
