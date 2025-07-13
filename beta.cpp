#include <bits/stdc++.h>
using namespace std;

double equation(double x) {
    return pow(x, 4) + (1.33 * pow(10, cos(x * x))) - (1.6 * x * exp(x));
}

double midpoint(double a, double b) {
    return (a + b) / 2;
}

int main() {
    double x = 0.1, y = 1.2; // Initial interval
    double tolerance = 0.00001;
    double mid, root_prev;
    double relative_error = 1.0;
    int step = 1;

    if (equation(x) * equation(y) >= 0) {
        cout << "No root exists in the given interval." << endl;
        return 0;
    }

    cout << "Inputs are okay. Root exists in [" << x << ", " << y << "]" << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;
    cout << "Step | Lower Limit | Upper Limit | Approx Root | Prev Root | Relative Error | Update" << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;

    root_prev = midpoint(x, y); // Initialize previous root

    while (relative_error > tolerance &&   abs(equation(mid)) > tolerance) { // Prevent infinite loop
        mid = midpoint(x, y);

        cout << step << " | " << x << " | " << y << " | " << mid << " | " << root_prev << " | " << relative_error << " | ";

        if (equation(x) * equation(mid) < 0) {
            y = mid;
            cout << "mid -> upper_limit" << endl;
        } else {
            x = mid;
            cout << "mid -> lower_limit" << endl;
        }

        relative_error = abs((mid - root_prev) / mid);
        root_prev = mid;
        step++;
    }

    cout << "-----------------------------------------------------------------------------------------" << endl;
    cout << "Final Root (approx): " << mid << endl;
    cout << "Function value at root: " << equation(mid) << endl;

    return 0;
}