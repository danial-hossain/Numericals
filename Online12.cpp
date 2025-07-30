#include <bits/stdc++.h>
using namespace std;
double equation(double *arr, double x, double degree)
{
    double result = 0;
    for (int i = 0; i <= degree; i++)
    {
        result = result * x + arr[i];
    }
    return result;
}
double derivative(double *arr, double x, double degree)
{
    double result = 0;
    for (int i = 0; i < degree; i++)
    {
        result = result * x + (degree - i) * arr[i];
    }
    return result;
}
int main()
{
    double arr[] = {1, -15, 85, -225, 274, -120};
    double x1, x0 = -1, error, tol = 0.000001, degree = 5;
    int c=0;
    cout << fixed << setprecision(5);
    while (degree > 1)
    {
        c++;
        error = 100;
        cout<<"Converging to Root : "<< c<<endl;
        cout<<"Iter       "<<"  x0         "<<"f(x0)               "<<"f'(x0)           "<<"error             "<<endl;
        int n=0;
        while (error >= tol)
        {
            
            double fq = equation(arr, x0, degree);
            double d_fq = derivative(arr, x0, degree);
            x1 = x0 - (fq / d_fq);
            error=fabs(x1-x0);
             cout<<++n<<"          "<<x0<<"       "<<fq<<"             "  << d_fq<< "              " <<error<< "               " <<endl;
            x0=x1;
           
        }
        cout << "Root : " << x1<<endl;
        double brr[10] = {0};
        brr[0] = arr[0];
        for (int i = 1; i <= degree; i++)
        {
            brr[i] = (brr[i - 1] * x1) + arr[i];
        }
        degree--;
        for (int i = 0; i <= degree; i++)
        {
            arr[i] = brr[i];
        }
    }
    cout << "last remaining root: ";
    x1 = -arr[1] / arr[0];
    cout << x1;
}