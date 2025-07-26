#include <bits/stdc++.h>
using namespace std;
float equation(float x)
{
    float y = cos(x);
    return y;
}
float modequation(float x)
{
    
   float y = cos(x);
    return y;
}
float differentiation(float x)
{
     float diff = -sin(x);
    return diff;
}

int main()
{
    float x=80;
    float tolerance = 0.00001;
    float relative_error = 1;
    float root_prev = x;
    if (abs(differentiation(x)) < 1)
    {
        cout << "Initial Guess is Okay"<<endl;
    }
    else
    {
        cout << "Change the Initial Guess"<<endl;
    }
    while (tolerance < relative_error)
    {
        x =modequation(root_prev);
        relative_error = (abs(x - root_prev));
        root_prev = x;
    }
    // cout<<relative_error;
    cout << x;
}