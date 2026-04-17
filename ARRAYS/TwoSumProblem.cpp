#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

// Brute force soln TC = O(n2), SC = O(1)
string twosum1(int arr[], int n, int target)
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
string twosum2(int arr[], int n, int target)
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

// optimal soln without using MAPS DS -> TC = O(n+nlogn)
//logn is bcoz of sorting 
//SC = O(1), if sorting considered then O(n)
string twosum3(int arr[], int n, int target)
{
    sort(arr, arr + n);
    int i = 0;
    int j = n - 1;
    int sum = 0;
    while (i < j)
    {
        sum = arr[i] + arr[j];
        if (sum < target)
        {
            i++;
        }
        else if (sum > target)
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


//IF WANTED TO RETURN INDEXS THEN HASHING IS OPTIMAL SOLN
vector<int> twosum4(int arr[], int n, int target)
{
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int req = target - arr[i];
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
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cin >> target;
    // cout << twosum1(arr, n, target);    //brute force soln
    // cout << twosum2(arr, n, target);    //better soln by using hashing
    // cout << twosum3(arr, n, target);    //optimal soln without using any data structure

    //optimal soln using hashing if u want to return index
    vector<int>v = twosum4(arr, n, target); 
    cout<<v[0]<<","<<v[1];
    return 0;
}