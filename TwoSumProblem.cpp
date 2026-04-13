#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

// Brute force soln TC = O(n2), SC = O(1)
string twosum(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // means if i equals j then we wont check coz
            // eg : arr = [3, 5, 7], target = 6
            //  i = 0, j = 0 → 3 + 3 = 6 --> returns yes
            // But correct answer should be NO
            if (i == j)
                continue;

            // checking if its equal to target
            if (arr[i] + arr[j] == target)
            {
                return "Yes";
            }
        }
    }
    return "No";
}

// Better Soln TC = O(nlogn) -> map is ordered
// Better Soln TC = O(n) -> map is unordered (best nd avg)
// Better Soln TC = O(n^2) -> map is unordered (worst)
string twosum1(int arr[], int n, int target)
{
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int req = target - arr[i];
        if (mpp.find(req) != mpp.end())
        {
            return "Yes";
        }
        mpp[arr[i]] = i;
    }
    return "No";
}

// optimal soln without using MAPS DS -> TC = O()

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cin >> target;
    cout << twosum1(arr, n, target);
    return 0;
}