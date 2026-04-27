#include <iostream>
#include <bits/stdc++.h>
using std ::cin;
using std ::cout;
using namespace std;

// RECURSIVE FUN FOR FLOOR CEIL, TC=O(log2N)
void floorCeil(vector<int> &arr, int x, int low, int high)
{
    int n = arr.size();
    if (x < arr[0])
    {
        cout << -1 << endl;
        cout << arr[0];
        return;
    }
    if (x > arr[n - 1])
    {
        cout << arr[n - 1] << endl;
        cout << -1;
        return;
    }
    if (high == low + 1)
    {
        cout << arr[low] << endl;
        cout << arr[high];
        return;
    }

    int mid = (low + high) / 2;

    if (arr[mid] > x)
    {
        high = mid;
    }
    else if (arr[mid] < x)
    {
        low = mid;
    }
    else
    {
        cout << arr[mid] << endl;
        cout << arr[mid];
        return;
    }
    floorCeil(arr, x, low, high);
}

// ITERATIVE WAY
// COMBINE FLOOR AND CEIL
// TC = O(log2N)
void floorceil2(vector<int> &arr, int x)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ceil = -1;
    int floor = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
        {
            ceil = arr[mid];
            high = mid - 1;
        }
        else if (arr[mid] < x)
        {
            floor = arr[mid];
            low = mid + 1;
        }
        else
        {

            floor = arr[mid];
            ceil = arr[mid];
            break;
        }
    }
    cout << floor << endl;
    cout << ceil;
}

// FLOOR FUNCITON
int findfloor(vector<int> &arr, int x)
{
    int ans = -1;
    int n = arr.size();
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] < x)
        {
            ans = arr[mid];
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

// CEIL FUNCTION
int findceil(vector<int> &arr, int x)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] >= x)
        {
            ans = arr[mid];
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

    // floorCeil(arr, x, 0, n - 1);
    // floorceil2(arr, x);
    cout << findfloor(arr, x) << endl;
    cout << findceil(arr, x);
    return 0;
}