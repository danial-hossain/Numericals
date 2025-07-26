#include <bits/stdc++.h>
using namespace std;

float equation(float x, const vector<float>& arr, int size)
{
    float sum = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        sum += arr[i] * pow(x, i);
    }
    return sum;
}

float differentiation(float x, const vector<float>& arr, int size)
{
    float sum = 0;
    for (int i = size - 1; i >= 1; i--)
    {
        sum += i * arr[i] * pow(x, i - 1);
    }
    return sum;
}
vector<float> syntheticDivision(const vector<float>& arr, float root)
{
    int size = arr.size();
    vector<float> newArr(size - 1);
    float carry = arr[size - 1];

    for (int i = size - 2; i >= 0; i--)
    {
        newArr[i] = carry;
        carry = arr[i] + carry * root;
    }

    return newArr;
}


float root(float x, vector<float> arr, int size)
{
    float r = x - (equation(x, arr, size) / differentiation(x, arr, size));
    return r;
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

        coef = syntheticDivision(coef, r);

        initial_guess = r + 0.1f;
    }



    return 0;
}
