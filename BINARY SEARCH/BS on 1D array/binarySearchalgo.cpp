#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

// ITERATIVE MANNER
// TC = O(logbase(2)N)
int bs(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (target == arr[mid])
        {
            return mid;
        }
        else if (target > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

// RECURSIVE MANNER
// TC = O(logbase(2)N)
int recusiveBs(vector<int> &arr, int target, int low, int high)
{
    if (low > high)
    {
        return -1;
    }
    int mid = (high + low) / 2;
    if (target == arr[mid])
    {
        return mid;
    }
    else if (target > arr[mid])
    {
        return recusiveBs(arr, target, mid + 1, high);
    }
    else
    {
        return recusiveBs(arr, target, low, mid - 1);
    }
    // the else statement can be written wihtout the ELSE ALSO**
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
    sort(arr.begin(), arr.end());

    int target;
    cin >> target;

    // cout << bs(arr, target);
    cout << recusiveBs(arr, target, 0, n - 1);
    return 0;
}