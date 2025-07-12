#include <bits/stdc++.h>
using namespace std;
float equation(float x)
{
    float y = (x * x) - (3 * x) + 2;
    return y;
}
float root(float x1, float x2)
{
    float x3 = x2 - ((equation(x2) * (x2 - x1)) / (equation(x2) - equation(x1)));
    return x3;
}
int main()
{
    float x1 = 0;
    float x2 = 4;

    float tolerance = 0.00001;
    float relative_error = 1;
    float x3;
    while (tolerance < relative_error)
    {
        x3=root(x1,x2);
         relative_error=(abs(x3-x2));
        x1=x2;
        x2=x3;
    
    }
    // cout<<relative_error;
    cout << x3;
}