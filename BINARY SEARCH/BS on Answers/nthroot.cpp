#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

double multiply(int n, double mid)
{
    double val = 1;
    for (int j = 0; j < n; j++)
    {
        val = val * mid;
    }
    return val;
}
double nthroot(int n, int m)
{
    double low = 1;
    double high = m;
    double eps = 1e-6;

    while ((high - low) > eps)
    {
        double mid = (low + high) / 2.0;
        if (multiply(n, mid) <= m)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}
int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;

    cout << nthroot(n, m);
    cout<<endl;
    cout<< pow(m, (double)(1.0)/(double)n);  //27 raise to the power 1/3
    return 0;
}