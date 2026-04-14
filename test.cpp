#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

string fun(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int i = 0;
    int j = n - 1;
    int sum = 0;
    while (i < j)
    {
        sum = arr[i] + arr[j];
        if (sum < k)
        {
            i++;
        }
        else if (sum > k)
        {
            j--;
        }
        else
        {
            return "Yes";
        }
    }
    return "No";
}

vector<int> fun1(int arr[], int n, int k)
{
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int req = k - arr[i];
        if (mpp.find(req) != mpp.end())
        {
            return {mpp[req], i};
        }
        else
        {
            mpp[arr[i]] = i;
        }
    }
    return {-1, -1};
}
int main()
{
    int n1;
    cin >> n1;
    int arr1[n1];
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }

    int k;
    cin >> k;
    vector<x    int> ans = fun1(arr1, n1, k);
    cout << ans[0] << "," << ans[1];
    return 0;
}