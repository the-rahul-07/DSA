#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

// BRUTE SOLN TC = O(n3), SC = O(1)
int maxSubarrSum1(int arr[], int n)
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            for (int k = i; k < j; k++)
            {
                sum += arr[k];
                maxi = max(maxi, sum);
            }
        }
    }
    return maxi;
}

// BETTER SOLN TC = O(n2), SC = O(1)
int maxSubarrSum2(int arr[], int n)
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}

// OPTIMAL SOLN USING KADANE'S ALGORITHM
// TC = O(n), SC = O(1)
void maxSubarrSum3(int arr[], int n)
{
    int start = 0;
    int ansStart = 0;
    int ansEnd=0;
    int sum = 0;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if(sum==0) start = i;
        if (sum < 0)
        {
            sum = 0;
            start=i;
        }
        sum += arr[i];
        if(sum>maxi){
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
    }
    // for the empty subarray
    if (maxi < 0)
    {
        cout<<0;
    }

    cout << maxi << "\n";
    for (int k = ansStart; k <= ansEnd; k++)
    {
        cout << arr[k] << " ";
    }
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

    // cout<<maxSubarrSum1(arr,n);
    // cout<<maxSubarrSum2(arr,n);
    maxSubarrSum3(arr, n);
    return 0;
}