#include <bits/stdc++.h>
using namespace std;
float equation(float x)
{
    float y = sin(pow(x,2))-(x/2);
    return y;
}
float root(float x, float y)
{
    float r = (x + y) / 2;
    return r;
}
int main()
{
    float x = 1.5;
    float y = 2.0;
    float tolerance = 0.00001;
    float relative_error = 1;
    float root_prev=root(x,y);
    while (tolerance < relative_error)
    {
        cout<<x<<"   "<<equation(x)<<"   "<<y<<"   "<<equation(y)<<"   "<<root(x,y)<<"   "<<equation(root(x,y))<<"    "<<relative_error<<"   ";
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