#include <iostream>
#include <bits/stdc++.h>
using std ::cin;
using std ::cout;
using namespace std;

int upperbound(vector<int> &arr, int x)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
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

    int x;
    cin >> x;

    cout << upperbound(arr, x);
    return 0;
}