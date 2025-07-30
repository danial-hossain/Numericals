#include <bits/stdc++.h>
using namespace std;
float equation(float x)
{
    float y = (x * x * x * x * x) - (15 * x * x * x * x) + (85 * x * x * x) - (225 * x * x) + (274 * x) - 120;
    return y;
}
float root(float x, float y)
{
    float r = (x + y) / 2;
    return r;
}
int main()
{
    float a = -6;
    float b = 6;
    float del = 0.1;
    float x = a;
    float y = a + del;
    int c=0;
    while (y < b)
    {
        c++;
        float tolerance = 0.00001;
        float relative_error = 1;
        float root_prev = root(x, y);
        cout << "Converging to Root : " << c << endl;
        cout << "Iter       " << "  x         " << "    f(x)               " << "y          "<<"f(y)             "<<"        root           " <<"f(root)       "<< "error             " << endl;
        int n = 0;
        if (equation(x) * equation(y) < 0)
        {
            while (tolerance < relative_error)
            {
                n++;    
                cout<<n<<"            "<<x<<"       "<<equation(x)<<"        "<<y<<"        "<<equation(y)<<"         "<<root(x,y)<<"          "<<equation(root(x,y))<<"    "<<relative_error<<"   "<<endl;
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
            cout<< endl<< endl<< endl<< endl<< endl<< endl<< endl;
            cout << root(x, y) << endl<<endl<< endl<< endl<< endl<< endl<< endl;
            x = y;
            y = y + del;
        }
        else
        {
            x = y;
            y = y + del;
        }
    }
}