#include <bits/stdc++.h>
using namespace std;

double f(float x)
{
    return (x * x - 4 * x - 10);
}

int main()
{
    float a = -2, b = -1;
    int step = 1;
    float root, prev_root;
    float f0, f1, f2;


    if (f(a) * f(b) > 0)
    {
        cout << "Wrong guess! f(a) and f(b) should have opposite signs." << endl;
    }
    else
    {
        for(int step = 1; step <= 100;step++)
        {


            root = (a + b) / 2;


            if (f(a) * f(root) < 0)
            {
                b = root;
            }
            else
            {
                a = root;
            }


            cout << "Step " << step << ": Root = " << root <<endl;

        }
    }

    cout << "Final Root (approx): " << root << endl;

    return 0;
}

