#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

// SEARCH INSERT IS SAME AS THE OF LOWERBOUND
// IF ELEMENT PRESENT THEN RETURN ITS INDEX IF NOT THE
//  arr[mid]>x wali index
//  this will be same as insert search if u think
int searchinsert1(vector<int> &arr, int x)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= x)
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

// written by me
int searchInsert2(vector<int> &arr, int x)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] > x)
        {
            high = mid - 1;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            return mid;
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
    sort(arr.begin(), arr.end());

    int x;
    cin >> x;

    // cout << searchInsert1(arr, x);
    cout << searchInsert2(arr, x);
    return 0;
}