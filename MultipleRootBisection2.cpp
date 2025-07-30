#include <bits/stdc++.h>
using namespace std;

// Suppose equation: x^3 - 2x^2 - 5x + 6, roots are -2, 1, 3
// Tolerable absolute error between two successive roots is 0.00001
vector<double> coeff = {1, -2, -5, 6};

double f(double x) {
    double result = 0;
    for (int i = 0; i < coeff.size(); i++) {
        result = result * x + coeff[i];
    }
    return result;
}

int main() {
    double a = -4, b = 4, x0, x1, x2, error, tolerable = 0.00001, prev_root, dx = 0.1;

    x1 = a + dx;
    x2 = x1 + dx;

    while (x2 <= b) {
        error = 100;
        prev_root = x1;

        if (f(x1) * f(x2) < 0) {
            while (error >= tolerable) {
                x0 = (x1 + x2) / 2;
                error = fabs(x0 - prev_root);

                if (f(x0) == 0) {
                    break;
                } else if (f(x0) * f(x1) < 0) {
                    x2 = x0;
                } else {
                    x1 = x0;
                }

                prev_root = x0;
            }

            cout << "Value of root = " << x0 << endl;
        }

        x1 = x2;
        x2 = x1 + dx;
    }

    return 0;
}
