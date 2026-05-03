// WITH DUPLICATES
#include <iostream>
#include <bits/stdc++.h>
using std ::cin;
using std ::cout;
using namespace std;

bool searchEle(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            return true;
        }

        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low++;
            high--;
            continue;
        }
        if (arr[low] <= arr[mid])
        {
            if (target >= arr[low] && target <= arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (target >= arr[mid] && target <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int target;
    cin>>target;

    cout<< searchEle(arr, target);
    return 0;
}