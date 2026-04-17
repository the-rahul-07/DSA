#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

// brute force -> TC = O(n^2), SC = O(1)
int oncesAppears1(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == num)
                cnt++;
        }
        if (cnt == 1)
            return num;
    }
    return -1;
}

// Better soln TC = O(3n), SC = O(max element in arr)
int oncesAppears2(int arr[], int n)
{
    int maxi = arr[0];
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }
    int hasharr[maxi + 1] = {0};

    for (int i = 0; i < n; i++)
    {
        hasharr[arr[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (hasharr[i] == 1)
        {
            return i;
            break;
        }
    }
}

// Better soln if there are more elements in the arr
// if arr is of size 10^9 or 10^12 then we use map DS
// TC = O(nlog(n/2+1) + (n/2+1))
int oncesAppears3(int arr[], int n)
{
    map<long long, int> mpp;
    // map has n/2+1 element as all the elements appears twice and one element is alone

    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    // this has tc = O(n/2+1)
    for (auto it : mpp)
    {
        if (it.second == 1)
        {
            return it.first;
        }
    }
}

// OPTIMAL SOLN TC = O(n), SC = O(1)
int oncesAppears4(int arr[], int n)
{
    int xor1 = 0;
    for (int i = 0; i < n; i++)
    {
        xor1 = xor1 ^ arr[i];
    }
    return xor1;
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

    // cout << oncesAppears1(arr, n);
    // cout << oncesAppears2(arr, n);
    // cout << oncesAppears3(arr, n);
    cout << oncesAppears4(arr, n);
    return 0;
}