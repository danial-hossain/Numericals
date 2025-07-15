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
    double y = (2 * h * h * h) - (7 * h * h) + (4 * h) + 1;
    int degree = 3;
    double p;

    for (int i = 0; i < degree + 1; i++)
    {
        // cin>>arr[i];-->manually coefficient input dite;
    }
    int arr[degree + 1] = {2, -7, 4, -3};
    return horners(arr, degree, h);
    // return y;
}


double differentiation(double h)
{
    double y = (3 * 2 * h * h) - (7 * 2 * h) + 4;
    return y;
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

    cout << "***************************************************************************************" << endl;
    cout << "Iteration ||     prev_h     ||        h        ||      f(h)      ||     f'(h)     || Relative_error" << endl;

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

    cout << "***************************************************************************************" << endl;
    cout << "Final depth (approx): " << x1 << " meters";
}
