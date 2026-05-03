#include <iostream>
#include <bits/stdc++.h>
using std ::cin;
using std ::cout;
using namespace std;

// this hve TC = O(2logn)
// this method by dividing array in 2 parts
int largest(vector<int> &arr)
{
    int indx = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > arr[indx])
        {
            indx = i;
        }
    }
    return indx;
}
int searchEle1(vector<int> &arr, int target)
{
    if (arr.size() == 1)
    {
        if (arr[0] == target)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    int n = arr.size();
    int low1 = 0;
    int high1 = largest(arr);
    int low2 = high1 + 1;
    int high2 = n - 1;

    while (low1 <= high1)
    {
        int mid1 = (low1 + high1) / 2;
        if (arr[mid1] == target)
        {
            return mid1;
        }
        else if (arr[mid1] > target)
        {
            high1 = mid1 - 1;
        }
        else
        {
            low1 = mid1 + 1;
        }
    }

    while (low2 <= high2)
    {
        int mid2 = (low2 + high2) / 2;
        if (arr[mid2] == target)
        {
            return mid2;
        }
        else if (arr[mid2] > target)
        {
            high2 = mid2 - 1;
        }
        else
        {
            low2 = mid2 + 1;
        }
    }

    return -1;
}

// STANDARD APPROACH
// TC = O(logn)

int searchEle2(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
            return mid;

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

    int x;
    cin >> x;
    // cout << searchEle1(arr, x);
    cout << searchEle2(arr, x);
    return 0;
}