#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

// BRUTE FORCE O(N)
int searchEle1(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return arr[0];

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (arr[i] != arr[i + 1])
            {
                return arr[i];
            }
        }
        else if (i == n - 1)
        {
            if (arr[i] != arr[i - 1])
            {
                return arr[i];
            }
        }
        else
        {
            if (arr[i] != arr[i + 1] && arr[i] != arr[i - 1])
            {
                return arr[i];
            }
        }
    }
    return -1;
}

// OPTIMAL APPROACH O(logN)
int searchEle2(vector<int> &arr)
{
    int n = arr.size();
    int low = 1;
    int high = n - 2;

    if (n == 1)
        return arr[0];
    if (arr[0] != arr[1])
        return arr[0];
    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
        {
            return arr[mid];
        }

        if ((mid % 2 == 0 && arr[mid] == arr[mid + 1]) ||
            (mid % 2 == 1 && arr[mid] == arr[mid - 1]))
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

    cout << searchEle1(arr);
    return 0;
}