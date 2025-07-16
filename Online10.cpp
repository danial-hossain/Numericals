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
    double y = (2*(pow(h,4)))-(10*h)-(5*pow((h-1),3));
    int degree = 4;
    double p;

    int arr[degree + 1] = {2, -5, 15, -25,5};
    double hp=horners(arr,degree,h);
    return hp;
    //return y;
}

double root(double x0, double x1)
{
    double y = x1 - ((equation(x1) * (x1 - x0)) / (equation(x1) - equation(x0)));
    return y;
}

int main()
{
    double x0 = 32;
    double x1 = 34.7, x2;
    double absolute_error = 1;
    int steps = 0;

    cout << "***************************************************************************************" << endl;
    cout << "Iteration ||     T0      ||      T1        ||     f(T1)       ||      T2       ||     f(T2)      || Absolute_error" << endl;

    while (0.000001 < absolute_error)
    {
        steps++;

        x2 = root(x0, x1);

        cout << "    " << steps
             << "     ||  " << fixed << setprecision(6) << x0
             << "  ||  " << x1
             << "     ||  " << equation(x1)
             << "     ||  " << x2
             << "     ||  " << equation(x2)
             << "     ||  ";

        if (absolute_error == 1)
        {
            cout << "N/A";
        }
        else
        {
            cout << absolute_error;
        }

        cout << endl;

        absolute_error = fabs((x2 - x1));

        x0 = x1;
        x1 = x2;
    }

    cout << "***************************************************************************************" << endl;
    cout << "Final Temperature (approx): " << x2 << " degree Fahrenheit";
}
