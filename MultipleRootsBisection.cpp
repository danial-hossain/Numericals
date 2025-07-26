#include <bits/stdc++.h>
using namespace std;
float equation(float x)
{
    float y = (x * x * x * x) - (1156 * x * x) + 244036;
    return y;
}
float root(float x, float y)
{
    float r = (x + y) / 2;
    return r;
}
int main()
{
    float a = -100;
    float b = 100;
    float del = 0.00001;
    float x = a;
    float y = a + del;
    while (y < b)
    {
        float tolerance = 0.00001;
        float relative_error = 1;
        float root_prev = root(x, y);
        if (equation(x) * equation(y)<0)
        {
            while (tolerance < relative_error)
            {
                // cout<<x<<"   "<<equation(x)<<"   "<<y<<"   "<<equation(y)<<"   "<<root(x,y)<<"   "<<equation(root(x,y))<<"    "<<relative_error<<"   ";
                if (equation(x) * equation(root(x, y)) < 0)
                {
                    y = root(x, y);
                    // cout<<"b-->x"<<endl;
                }
                else if (equation(x) * equation(root(x, y)) > 0)
                {
                    x = root(x, y);
                    //  cout<<"a-->x"<<endl;
                }
                relative_error = (abs(root(x, y) - root_prev));
                root_prev = root(x, y);
            }
            cout << root(x, y) << endl;
            x = y;
            y = y + del;
        }
        else{
            x = y;
            y = y + del;
        }
    }
}