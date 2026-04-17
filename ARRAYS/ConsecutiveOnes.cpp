#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

// brute force approach TC = O(n+j)
// in worst case TC = O(2n), when j=n
int consecutiveone(int arr[], int n)
{
    int cnt[n] = {0};
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            cnt[j]++;
        }
        else
        {
            j++;
        }
    }

    int largest = cnt[0];
    for (int k = 0; k <= j; k++)
    {
        if (cnt[k] > largest)
        {
            largest = cnt[k];
        }
    }
    return largest;
}

// OPTIMAL SOLN TC = O(n)
int consecutiveone2(int arr[], int n)
{
    int cnt = 0;
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            cnt++;
            maxi = max(cnt, maxi);
        }
        else
        {
            cnt = 0;
        }
    }
    return maxi;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // cout << consecutiveone(arr, n);
    cout << consecutiveone2(arr, n);
    return 0;
}