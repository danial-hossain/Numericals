#include <bits/stdc++.h>
using namespace std;
float equation(float x)
{
    float y = (x * x * x * x) - (1156 * x * x) + 244036;
    return y;
}
float root(float x, float y)
{
    float r = x-((equation(x)*(y-x))/(equation(y)-equation(x)));
    return r;
}
int main()
{
    float x = 15.000000;
    float y = 17.000000;
    float tolerance = 0.00001;
    float relative_error = 1;
    float root_prev=root(x,y);
    while (tolerance < relative_error)
    {
        cout<<x<<" ||  "<<equation(x)<<" ||  "<<y<<"  || "<<equation(y)<<" ||  "<<root(x,y)<<" ||  "<<equation(root(x,y))<<"  ||  "<<relative_error<<" ||  ";
        if (equation(x) * equation(root(x, y)) < 0)
        {
            y = root(x, y);
            cout<<"b-->x"<<endl;
        }
        else if (equation(x) * equation(root(x, y)) > 0)
        {
            x = root(x, y);
             cout<<"a-->x"<<endl;
        }
        relative_error=(abs(root(x,y)-root_prev));
        root_prev=root(x,y);
    }
   // cout<<relative_error;
    cout<<root(x,y);
}