#include <bits/stdc++.h>
using namespace std;
float equation(float x)
{
    float y = (x * x * x) - (0.165 * x * x) + (3.993e-4);

    return y;
}

float root(float x, float y)
{
    float r = x - ((equation(x) * (y - x)) / (equation(y) - equation(x)));
    return r;
}
int main()
{
    cout << fixed << setprecision(6);
  //  float x = -0.1, y = 1;-->nnegative root 
 //    float x = 0.1, y = 1.2; -->0.142 root
 float x = 0.05, y = 0.07;
    float tolerance = 0.00001;
    float root_prev=root(x,y) ;
    float relative_error = 1.0;
    int p = 0, q = 0;
    string r, s;
    if (equation(x) * equation(y) < 0)
    {
        cout << "Inputs are okay" << endl;
        p = 1;
    }
    else
    {
        r = "Can't be Determined";
        s = "None";
        q = 1;
    }
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << "No|| " << " lower_limit  ||" << " upper_limit   ||" << " Approx Root ||" << " Prev Approx Root ||" << " Abs. Relative Error " << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    int step = 1;
    while (tolerance < relative_error)
    {
        if (p)
        {
             cout << step << "||" << "      " << x << "||" << "       " << y ;
           
            if (equation(x) * equation(root(x, y)) < 0)
            {
                y = root(x, y);
               
            }
            else if (equation(x) * equation(root(x, y)) > 0)
            {
                x = root(x, y);
            
            }
            relative_error = abs((root(x, y) - root_prev) / (root(x, y)));
             cout<< "||" << "         " << root(x, y) << "||" << "       " << root_prev << "||" << "      " << relative_error << endl;
            root_prev = root(x, y);
            step++;
          
        }
        if (q)
        {
            cout << step << "||" << "      " << x << "||" << "     " << y << "||" << "       " << root(x, y) << "||" << "            " << s<< "||" << "      " << r<< endl;
            break;
            
        }
    }
    cout <<endl<<endl<< "Final Root (approx): " << root(x, y)<<endl;
    cout<<equation(root(x,y));
}