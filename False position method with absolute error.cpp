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
    float abs_error = 1.0;
    float tolerance = 0.000001;

    if (f(a) * f(b) > 0)
    {
        cout << "Wrong guess! f(a) and f(b) should have opposite signs." << endl;
    }
    else
    {
        f1 = f(a);
        f2 = f(b);

        root = a - (f(a) * (b-a))/(f(b)-f(a));

        f0 = f(root);

        prev_root = root;

        while (abs_error > tolerance)
        {
            if (f1 * f0 < 0)
            {
                b = root;
            }
            else
            {
                a = root;
            }

            root = a - (f(a) * (b-a))/(f(b)-f(a));

            f0 = f(root);

            abs_error = fabs(root - prev_root);

            /// try with relative error.

            /// Formula for relative_error = fabs((root - prev_root)/root);

            cout << "Step " << step << ": Root = " << root << ", Absolute Error = " << abs_error << endl;

            prev_root = root;

            step++;
        }
    }

    cout << "Final Root (approx): " << root << endl;

    return 0;
}

