#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x, sum=0;

    cout << "Input the Highest Degree of the Polynomial : " << endl;
    cin >> n;
    int cf[n+1];
    cout << endl;
    cout << "Input the Value of Co-efficients : " << endl;

    for (int i = 0; i < n+1; i++)
    {
        cin >> cf[i];
    }
    cout << endl;
    cout << "Input the given value of x : ";
    cout << endl;
    cin >> x;
   // sum = cf[1] + (cf[0] * x);
    for (int i = 0; i <= n; i++)
    {
        sum = cf[i] + (sum * x);
    }
    cout << "The value of f(x) : "<<endl<<sum;
}