#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    vector<int> temp;
    // [low .... mid]
    // [mid+1 ... high]

    // somewhat like sliding window
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // this for the cases when both the condition are togther false
    // means that the left side or the right is fully sorted
    // so one of them will be remaining thats we give seperate condition for them
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // pushing the temp vector element into the original array
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
        // i-low --> low - low = 0;
        // i-low --> low+1 - low = 1;
        // i-low --> low+2 - low = 2;
        // and so on
    }
}

void mS(int arr[], int low, int high)
{
    // base condition to end the recursion
    if (low >= high)
        return;
    // mid divides the array into 2 parts
    int mid = (low + high) / 2;
    mS(arr, low, mid);
    // mid+1 coz sending the next index which is of right array
    mS(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mS(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}