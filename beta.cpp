#include <bits/stdc++.h>
using namespace std;

float equation(float x, vector<float> arr, int size)
{
    float sum = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        sum += arr[i] * pow(x, i);
    }
    return sum;
}

float differentiation(float x, vector<float> arr, int size)
{
    float sum = 0;
    for (int i = size - 1; i >= 1; i--)
    {
        sum += i * arr[i] * pow(x, i - 1);
    }
    return sum;
}

float root(float x, vector<float> arr, int size)
{
    float r = x - (equation(x, arr, size) / differentiation(x, arr, size));
    return r;
}

vector<float> syntheticDivision(vector<float> arr, int size, float root)
{
    for (int i = size - 2; i >= 0; i--)
    {
        arr[i] = arr[i + 1] * root + arr[i];
    }
    arr.pop_back(); 
    return arr;
}

float newton(float x, vector<float> arr, int size)
{
    float tolerance = 0.00001;
    float relative_error = 1;
    float root_prev = x;

    while (relative_error > tolerance)
    {
        x = root(root_prev, arr, size);
        relative_error = fabs(x - root_prev);
        root_prev = x;
    }

    return x;
}


int main()
{
    int degree;
    cout << "Enter the highest degree of the polynomial: ";
    cin >> degree;

    vector<float> coef(degree + 1); 

    cout << "Enter the coefficients from highest degree to constant term:\n";
    for (int i = degree; i >= 0; i--)
    {
        cin >> coef[i]; 
    }

    float initial_guess;
    cout << "Enter initial guess for Newton-Raphson: ";
    cin >> initial_guess;

    while (coef.size() > 1)
    {
        float r = newton(initial_guess, coef, coef.size());
        cout << "Root found: " << r << endl;

        coef = syntheticDivision(coef, coef.size(), r);

        // Update initial_guess for next root finding iteration
        initial_guess = r;
    }

    cout << "Remaining constant: " << coef[0] << endl;

    return 0;
}
