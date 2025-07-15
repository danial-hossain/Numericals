#include <bits/stdc++.h>
using namespace std;

double horners(int arr[], int degree, double x) {
    double sum = arr[0];
    for (int i = 1; i <= degree; i++) {
        sum = sum * x + arr[i];
    }
    return sum;
}

double equation(double h) {
    int degree = 3;
    int arr[degree + 1] = {2, -7, 4, 1}; // Correct: 2h³ - 7h² + 4h + 1
    return horners(arr, degree, h);
}

double root(double x0, double x1) {
    if (fabs(equation(x1) - equation(x0)) < 1e-12)
        return x1;
    return x1 - ((equation(x1) * (x1 - x0)) / (equation(x1) - equation(x0)));
}

int main() {
    double x0 = 1.5;
    double x1 = 2.5, x2;
    double relative_error = 1.0;
    int steps = 0;

    cout << fixed << setprecision(6);
    cout << "************************************************************************************************" << endl;
    cout << "Iteration ||     h0      ||     h1      ||    f(h1)    ||     h2      || Relative Error" << endl;

    while (relative_error > 0.000001) {
        x2 = root(x0, x1); // New approximation
        steps++;

        double fx1 = equation(x1);

        cout << "    " << steps << "     ||  "
             << x0 << "  ||  "
             << x1 << "  ||  "
             << fx1 << "  ||  "
             << x2 << "  ||  ";

        if (steps == 1)
            cout << "N/A";
        else
            cout << fabs((x2 - x1) / x2);

        cout << endl;

        relative_error = fabs((x2 - x1) / x2);

        x0 = x1;
        x1 = x2;
    }

    cout << "************************************************************************************************" << endl;
    cout << "Final depth (approx): " << x1 << " meters" << endl;

    return 0;
}
