#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

// optimal soln if array is **SORTED** TC = O(n) SC = O(1)
int missingno01(int arr[], int n)
{
    int ans = n;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] != i + 1)
        {
            ans = i + 1;
            break;
        }
    }
    return ans;
}

// brute force approach TC = O(n2)
int missingno02(int arr[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] != i)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            return i;
        }
    }
}

// Better soln TC = O(2n) SC = O(n)
int missingno03(int arr[], int n)
{

    int hash[n + 1] = {0};
    for (int i = 0; i < n - 1; i++)
    {
        hash[arr[i]]++;
    }
    for (int j = 1; j < n; j++)
    {
        if (hash[j] == 0)
        {
            return j;
            break;
        }
    }
}

// optimal soln 1 -> using sum TC = O(n)
int missingno04(int arr[], int n)
{
    int sum = (n * (n + 1)) / 2;
    int s2 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        s2 += arr[i];
    }
    return (sum - s2);
}

// XOR IS BETTER THEN SUM
// optimal soln 2 -> XOR TC = O(n)
int missingno05(int arr[], int n)
{
    int xor1 = 0;
    int xor2 = 0;

    // for n=5;
    // for arr = [2,3,5,1]
    // loop runs form zero to 3->4 times
    for (int i = 0; i < n - 1; i++)
    {
        xor1 = xor1 ^ (i + 1);
        // 1^2^3^4;
        xor2 = xor2 ^ arr[i];
    }

    xor1 = xor1 ^ n;
    // 1^2^3^4^5;
    return xor1 ^ xor2;
}

int main()
{
    int n;
    cin >> n;

    int arr[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
    }

    // cout << missingno01(arr, n);    //BRUTE SOLN
    // cout << missingno02(arr, n);    //BRUTE SOLN
    // cout << missingno03(arr, n);    //BETTER SOLN
    // cout << missingno04(arr, n);    //OPTIMAL SOLN SUM
    cout << missingno05(arr, n); // OPTIMIAL SOLN XOR
    return 0;
}