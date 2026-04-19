#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;
// BRUTE FORCE SOLN TC = O(n2)

bool ls(vector<int> &arr, int x)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == x)
        {
            return true;
        }
    }
    return false;
}
void seq1(vector<int> &arr)
{
    int longest = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        int cnt = 1;
        int x = arr[i];
        while (ls(arr, x + 1) == true)
        {
            x += 1;
            cnt++;
        }
        longest = max(longest, cnt);
    }
    cout << longest;
}

// BETTER SOLN TC = O(nlogn+n)
void seq2(vector<int> &arr)
{
    if (arr.size() == 0)
    {
        cout << 0;
        return;
    }
    sort(arr.begin(), arr.end());

    int lastSmaller = INT_MIN;
    int len = 0;
    int maxi = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == lastSmaller + 1)
        {
            len++;
        }
        else if (arr[i] == lastSmaller)
        {
            continue;
        }
        else
        {
            len = 1;
        }
        maxi = max(maxi, len);
        lastSmaller = arr[i];
    }
    cout << maxi;
}

// OPTIMAL SOLN TC = O(4n), SC = O(n)
void seq3(vector<int> &arr)
{
    if (arr.size() == 0)
    {
        cout << 0;
        return;
    }
    int longest = 1;
    unordered_set<int> newarr;

    // TC = O(n)
    for (int i = 0; i < arr.size(); i++)
    {
        newarr.insert(arr[i]);
    }

    // TC = O(3n)
    for (auto it : newarr) // tc = n
    {
        if (newarr.find(it - 1) == newarr.end())
        {
            int cnt = 1;
            int x = it;

            // tc = 2n
            while (newarr.find(x + 1) != newarr.end())
            {
                x = x + 1;
                cnt++;
            }
            longest = max(longest, cnt);
        }
    }
    cout << longest;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // seq1(arr);      //BRUTE FORCE SOLN
    // seq2(arr);      //BETTER SOLN
    seq3(arr); // OPTIMAL SOLN
    return 0;
}