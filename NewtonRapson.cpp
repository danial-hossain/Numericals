#include <bits/stdc++.h>
using namespace std;
float equation(float x)
{
    float y = (x * x) - (3 * x) + 2;
    return y;
}
float differentiation(float x)
{
    float diff = (2 * x) - 3;
    return diff;
}
float root(float x)
{
    float r = x - (equation(x) / differentiation(x));
    return r;
}
int main()
{
 /*
    x --> initial guess
    How to get initial guess?
    In Bisection method, we used to check: f(a) * f(b) < 0, meaning a root lies between them.

    Here, if we have two guesses x1 and x2, and we know f(x1) and f(x2),
    then we can choose the one with the larger |f(x)| as the initial guess,
    because it's farther from the root, and Newton-Raphson converges quickly.

    But Newton-Raphson typically starts with just one guess.
    You can choose that based on graph, or from interval [a, b] where f(a)*f(b)<0 like in Bisection.
    */
    float x=1.5;
    float tolerance = 0.00001;
    float relative_error = 1;
    float root_prev = x;
    while (tolerance < relative_error)
    {
        x = root(root_prev);
        relative_error = (abs(x - root_prev));
        root_prev = x;
    }
    // cout<<relative_error;
    cout << x;
}