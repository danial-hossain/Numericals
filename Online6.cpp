#include <bits/stdc++.h>
using namespace std;
double equation(double x)
{
    double y = pow(x, 4) + (1.33 * pow(10, cos(x * x))) - (1.6 * x * exp(x));
    return y;
}
double root(double x, double y)
{
    double r = (x + y) / 2;
    return r;
}
int main()
{
        cout << fixed << setprecision(10);
    //  cout << fixed << setprecision(6);
    //  double x = -0.1, y = 1;-->nnegative root
    //    double x = 0.1, y = 1.2; -->0.142 root
    double x = 0.1, y = 1.2;
    double mid;
    double tolerance = 0.00001;
    double root_prev = root(x, y);
    double relative_error = 1.0;
    int p = 0, q = 0, c = 0, t = 0;
    string r, s;
    if (equation(x) * equation(y) < 0)
    {
        cout << "Inputs are okay" << endl;
        p = 1;
    }
    else
    {
        r = "Can't be Determined";
        cout << equation(x) << endl
             << equation(y);
        cout << endl;
        s = "None";
        q = 1;
    }
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << "No|| " << " lower_limit  ||" << " upper_limit   ||" << " Approx Root ||" << " Prev Approx Root ||" << " Abs. Relative Error || " << "Update " << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    int step = 1;
    while (relative_error > tolerance || abs(equation(mid)) > tolerance)

    {
        if (p)
        {
            mid = root(x, y);
              cout << step << "||" << "      " << x << "||" << "       " << y;

            if (equation(x) * equation(mid) < 0)
            {
                y = mid;
              
                c = 1;
            }
            else if (equation(x) * equation(mid) > 0)
            {
                x = mid;
         
                t = 1;
            }
            relative_error = abs((mid - root_prev) / mid);
            cout << "||" << "         " << root(x, y) << "||" << "       " << root_prev << "||" << "      " << relative_error << "               ";
            if (c)
            {
                cout << "mid ->upper_limit";
                c = 0;
            }
            if (t)
            {
                cout << "mid->lower_limit";
                t = 0;
            }
            root_prev = mid;
            step++;
        }
        else if (q)
        {
            cout << step << "||" << "      " << x << "||" << "     " << y << "||" << "       " << root(x, y) << "||" << "            " << s << "||" << "      " << r << endl;
            break;
        }
    }
    cout << endl
         << endl
         << "Final Root (approx): " << root(x, y) << endl;

    cout << equation(mid);
}