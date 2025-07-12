#include <bits/stdc++.h>
using namespace std;
float equation(float x)
{
    float y = (x * x) - (3 * x) + 2;
    return y;
}
float root(float x1, float x2)
{
    float r = x2 - ((equation(x2) * (x2 - x1)) / (equation(x2) - equation(x1)));
    return r;
}
int main()
{
    float x1 = 4;
    float x2 = 2;

    float tolerance = 0.00001;
    float relative_error = 1;
    float root_prev = root(x1, x2);
    while (tolerance < relative_error)
    {
        x1=x2;
        x2=root(x1,x2);
         relative_error=(abs(root(x1,x2)-root_prev));
        root_prev=root(x1,x2);
    }
    // cout<<relative_error;
    cout << root(x1, x2);
}