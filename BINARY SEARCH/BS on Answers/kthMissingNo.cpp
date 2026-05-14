#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

// tc = O(N)
int findKthPositive1(vector<int> &arr, int k)
{
    int n = arr.size();
    int val;
    for (int i = 0; i < n; i++)
    {
        val = (arr[i] - (i + 1));

        if (val >= k)
        {
            // missing number+existing number;
            return k + i;
        }
    }
    return k + n;
}

// TC = O(logn)
int findKthPositive2(vector<int> &arr, int k)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int missing = (arr[mid] - (mid + 1));

        if (missing < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    // return high+1+k  == low+k;
    return low + k;
}
int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    // cout<<findKthPositive1(arr, k);    //brute using linear search (n)
    cout << findKthPositive2(arr, k); // optimal using bs logn
    return 0;
}