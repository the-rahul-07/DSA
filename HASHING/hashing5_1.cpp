#include <iostream>
#include <bits/stdc++.h>
using std ::cin;
using std ::cout;
using namespace std;

// globally integer array can go to 10e7
// in int main it can go till 10e6

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // precompute
    // int hash[13] = {0};
    // for (int i = 0; i < n; i++)
    // {
    //     hash[arr[i]] += 1;
    // }

    // precompute using map
    std ::map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    // iterating in map
    int maxm = 0;
    int maximum = 0;
    int freq = 0;
    for (auto it : mpp)
    {
        cout << it.first << "->" << it.second << endl;
        if (it.second > maximum)
        {
            maximum = it.first;
            freq = it.second;
        }
    }
    // cout<< max <<endl;
    cout << "most frequent element = " << freq << ", its freq is " << maxm << endl;

    int q;
    cin >> q;
    while (q--)
    {
        int number;
        cin >> number;
        // fetch
        cout << mpp[number] << endl;
    }
    return 0;
}