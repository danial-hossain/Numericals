#include <bits/stdc++.h>
using namespace std;

double f(double *a, double x, int n) {
    double res = 0;
    for (int i = 0; i <= n; i++) {
        res = res * x + a[i];
    }
    return res;
}

double f_der(double *a, double x, int n) {
    double res = 0;
    for (int i = 0; i < n; i++) {
        res = res * x + (n - i) * a[i];
    }
    return res;
}

int main() {
    double a[10] = {1, -7, 15, -9};  // Coefficients of the polynomial
    double x0 = 2.5, x1, error, tol = 0.000001;
    int degree = 3;

    cout << fixed << setprecision(10);

    while (degree > 1) {
        error = 100;

        while (error >= tol) {
            double fval = f(a, x0, degree);
            double dval = f_der(a, x0, degree);

            x1 = x0 - fval / dval;
            error = fabs(x1 - x0);
            x0 = x1;
        }

        cout << "\nRoot = " << x1 << endl;

        // Polynomial deflation using synthetic division
        double b[10] = {0};
        b[0] = a[0];

        for (int i = 1; i <= degree; i++) {
            b[i] = b[i - 1] * x1 + a[i];
        }

        degree--;
        cout << "Polynomial coefficients for degree = " << degree << endl;
        for (int i = 0; i <= degree; i++) {
            cout << b[i] << "\t";
            a[i] = b[i];  // Update coefficients for next iteration
        }
        cout << endl;
    }

    // Final root when degree becomes 1
    cout << "\nRoot = " << -a[1] / a[0] << endl;

    return 0;
}
