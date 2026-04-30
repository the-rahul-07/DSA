#include <iostream>
#include <bits/stdc++.h>
using std ::cin;
using std ::cout;
using namespace std;

int rotated(vector<int> &arr)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int mini = INT_MAX;
    int indx = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[low] <= arr[high])
        {
            if (arr[low] < mini)
            {
                mini = arr[low];
                indx = low;
            }
            break;
        }
        if (arr[low] <= arr[mid])
        {
            if (arr[low] < mini)
            {
                mini = arr[low];
                indx = low;
            }
            low = mid + 1;
        }
        else
        {
            if (arr[mid] < mini)
            {
                mini = arr[mid];
                indx = mid;
            }
            high = mid - 1;
        }
    }
    return indx;
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

    cout << rotated(arr);
    return 0;
}