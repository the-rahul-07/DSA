#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

int minDays(vector<int> &bloomDay, int m, int k)
{
    int n = bloomDay.size();
    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());

    if (((long long)m * k) > n)
    {
        return -1;
    }

    while (low <= high)
    {
        int cnt = 0;
        int bouquets = 0;
        int mid = (low + high) / 2;

        for (int i = 0; i < n; i++)
        {
            if (bloomDay[i] <= mid)
            {
                cnt++;
            }
            else
            {
                cnt = 0;
            }

            // i made logical mistake thinking the cnt values are stored
            // checking it with the previous one
            //  if(cnt == cnt-1){
            //      cnt=0;
            //  }

            if (cnt == k)
            {
                bouquets++;
                cnt = 0;
            }
        }

        if (bouquets >= m)
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

    int m;
    cin >> m;

    int k;
    cin >> k;

    vector<int> bloomDay(n);
    for (int i = 0; i < n; i++)
    {
        cin >> bloomDay[i];
    }

    cout << minDays(bloomDay, m, k);
    return 0;
}