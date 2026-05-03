#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

// BRUTE FORCE TC = O(N)
int findPeakElement1(vector<int> &nums)
{
    int n = nums.size();

    if (n == 1)
        return 0;

    if (nums[0] > nums[1])
    {
        return 0;
    }

    if (nums[n - 1] > nums[n - 2])
    {
        return n - 1;
    }

    for (int i = 1; i < n - 1; i++)
    {
        if (nums[i] > nums[i + 1] && nums[i] > nums[i - 1])
        {
            return i;
        }
    }
    return -1;
}

int findPeakElement2(vector<int> &nums)
{
    int n = nums.size();

    if (n == 1)
        return 0;

    if (nums[0] > nums[1])
    {
        return 0;
    }

    if (nums[n - 1] > nums[n - 2])
    {
        return n - 1;
    }

    int low = 1;
    int high = n - 2;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
        {
            return mid;
        }

        if (nums[mid + 1] > nums[mid])
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

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // cout << "index - " << findPeakElement1(arr);
    cout << "index - " << findPeakElement2(arr);
    return 0;
}