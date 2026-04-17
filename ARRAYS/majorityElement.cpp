#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

// BRUTE FORCE -> TC = O(n2)
int majorityEle1(int arr[], int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                cnt++;
            }
        }
        if (cnt > n / 2)
            return arr[i];
        cnt = 0;
    }
    return -1;
}

// BETTER SOLN -> TC = O(nlogn+n), SC = O(n)
int majorityEle2(int arr[], int n)
{
    map<int, int> mpp;
    // loop - n and map - logn
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    // loop n
    for (auto it : mpp)
    {
        if (it.second > n / 2)
        {
            return it.first;
        }
    }
    return -1;
}

// OPTIMAL SOLN TC = O(n) if ques states there exist majority element
// TC = O(2n) if ques states there may not exist majority element
// SC = O(1 )
// MOORES VOTING ALGORITHM
int majorityEle3(int arr[], int n)
{
    int ele;
    int cnt = 0;
    int i = 0;
    // this is to find the element
    /*
    n=7 and arr[7] = {2,2,3,3,1,2,2}
    i=0
    cnt = 1
    ele = 2

    i=1
    arr[1] = 2 which is equal to ele
    cnt = 2

    i=2
    arr[2] = 3 which is not equal to ele
    cnt = 1

    i=3
    arr[3] = 3 which is not equal to ele
    cnt = 0
    small hypo arr1 = {2,2,3,3}

    now cnt became 0 so again
    cnt = 1
    and ele = arr[4] = 1

    i=5
    arr[5] = 2 which is not ele
    cnt = 0
    small hypo arr2 = {1,2}

    now cnt became 0 again so
    cnt = 1
    and ele = arr[6] = 2
    small hypo arr3 = {2}

    HERE THE LOOP END AND ELEMENT ELE = 2
    */
    while (i < n)
    {
        if (cnt == 0)
        {
            cnt = 1;
            ele = arr[i];
        }
        else if (arr[i] == ele)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
        i++;
    }

    /*
    HERE WE WILL CHECK HOW MANY TIMES DOES ELEMENT ELE APPEARS
    AND INCREASE THE COUNTER
    */
    int cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        // checking how many times that element has appeared
        if (arr[i] == ele)
        {
            cnt1++;
        }
    }

    // checking weather count of that element is greater then n/2
    if (cnt1 > n / 2)
    {
        return ele;
    }

    return -1;
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

    // cout << majorityEle1(arr, n);
    // cout << majorityEle2(arr, n);
    cout << majorityEle3(arr, n);
    return 0;
}