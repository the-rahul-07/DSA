#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

int shipWithinDays(vector<int> &weights, int days)
{
    int n = weights.size();
    long long low = *max_element(weights.begin(), weights.end());
    long long high = 0;
    for (int i = 0; i < n; i++)
    {
        high += weights[i];
    }

    while (low <= high)
    {
        long long mid = (low + high) / 2;
        int wtg = 0;
        int noofdays = 0;
        for (int i = 0; i < n; i++)
        {
            wtg += weights[i];
            if (wtg > mid)
            {
                wtg = 0;
                i--;
                noofdays++;
            }
            if (i == n - 1)
            {
                if (wtg <= mid)
                {
                    noofdays++;
                }
            }
        }

        if (noofdays <= days)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    int n;
    cin >> n;

    vector<int> weights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    int days;
    cin >> days;

    cout << shipWithinDays(weights, days);
    return 0;
}