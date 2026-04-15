#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

// brute force soln TC = O(n2)
void fun(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// better soln TC = O(2n)
void fun1(int arr[], int n)
{
    int hasharr[3] = {0};
    for (int i = 0; i < n; i++)
    {
        hasharr[arr[i]]++;
    }

    for (int i = 0; i < hasharr[0]; i++)
    {
        arr[i] = 0;
    }
    for (int i = hasharr[0]; i < hasharr[0] + hasharr[1]; i++)
    {
        arr[i] = 1;
    }
    for (int i = hasharr[0] + hasharr[1]; i < hasharr[0] + hasharr[1] + hasharr[2]; i++)
    {
        arr[i] = 2;
    }
}

// optimal soln TC = O(n), SC =O(1)
void fun2(int arr[], int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
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
    // fun(arr, n);        //BRUTE SOLN USING SORTING ALGO
    // fun1(arr, n);       //BETTER SOLN USING HASHING
    fun2(arr, n); // OPTIMAL SOLN USING DUTCH NATIONAL FLAG ALGO
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}