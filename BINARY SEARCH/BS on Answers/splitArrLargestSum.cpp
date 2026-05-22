#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

int splits(vector<int> &nums, int mid)
{
    int n = nums.size();
    int x = 1;
    int numbers = 0;
    for (int i = 0; i < n; i++)
    {
        if (numbers + nums[i] <= mid)
        {
            numbers += nums[i];
        }
        else
        {
            x++;
            numbers = nums[i];
        }
    }
    return x;
}

int splitArray(vector<int> &nums, int k)
{
    int n = nums.size();
    if (k > n)
        return -1;
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);

    while (low <= high)
    {
        long long mid = (low - high) / 2 + high;

        int cntslipts = splits(nums, mid);

        if (cntslipts > k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return low;
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

    cout << splitArray(arr, k);
    return 0;
}
