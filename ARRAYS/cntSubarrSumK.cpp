#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

// OPTIMAL APPROACH FOR POSTIVES AND ZEROS, TC = O(N)
void cntsubarr(vector<int> &arr, int k)
{
    int sum = 0;
    int cnt = 0;
    int i = 0;
    int j = 0;
    while (j < arr.size())
    {
        sum += arr[j];
        while (sum > k)
        {
            sum -= arr[i];
            i++;
        }
        if (sum == k)
        {
            cnt++;
        }
        j++;
    }
    cout << cnt;
}

// optimal soln but not std; tc = O(n);
//  TC = O(N*LOG N) -> worst
void cntsubarr2(vector<int> &arr, int k)
{
    map<int, int> prefixsum;
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];

        if (sum == k)
        {
            cnt++;
        }

        int req = sum - k;
        cnt += prefixsum[req];
        prefixsum[sum]++;
    }
    cout << cnt;
}

// OPTIMAL AND STD SOLN OF PREFIXSUM + HASHING
//  TC = O(N) ->best & avg
//  TC = O(N*LOG N) -> worst
void cntsubarr3(vector<int> &arr, int k)
{
    map<int, int> mpp;
    int cnt = 0;
    int prefixsum = 0;
    // this is storing 0 sum and frequency 1, std base case for prefixsum
    mpp[0] = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        // calculating sum
        prefixsum += arr[i];
        // finding what is required
        int req = prefixsum - k;

        // checks if req is there in map, if not then it returns 0
        cnt += mpp[req];

        // this maps prefixsum and its frequency
        mpp[prefixsum]++;
    }
    cout << cnt;
}

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;

    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
    cntsubarr3(arr, k);
    return 0;
}