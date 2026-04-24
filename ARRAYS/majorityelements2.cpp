#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

// BRUTE FORCE SOLN TC = O(n2), SC = (1)
void majorityelement1(vector<int> &arr)
{
    int n = arr.size();
    list<int> ls;
    int maxi = (int)(n / 3) + 1;
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {

        if (ls.empty() || arr[0] != arr[i])
        {
            cnt = 0;
        }
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[i] == arr[j])
            {
                cnt++;
            }
            if (cnt == maxi)
            {
                ls.push_back(arr[j]);
            }
        }
        if (ls.size() == 2)
            break;
    }

    for (auto it : ls)
    {
        cout << it << " ";
    }
}

// BETTER SOLN USING HASING TC = O(N), SC = O(N);
void majorityelements1(vector<int> &arr)
{
    int n = arr.size();
    int mini = (int)(n / 3) + 1;
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i++)
    {
        cnt[arr[i]]++;
        if (cnt[arr[i]] == mini)
        {
            cout << arr[i] << " ";
        }
    }

    // for (auto it : cnt)
    // {
    //     if (it.second > arr.size() / 3)
    //     {
    //         cout << it.first << " ";
    //     }
    // }
}

// OPTIMAL SOLN TC=O(N2), SC = O(1);
// MODIFIED MOORES VOTING ALGO
void majorityelements2(vector<int> &arr)
{
    int ele1 = INT_MIN;
    int cnt1 = 0;
    int ele2 = INT_MIN;
    int cnt2 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (cnt1 == 0 && arr[i] != ele2)
        {
            cnt1 = 1;
            ele1 = arr[i];
        }
        else if (cnt2 == 0 && arr[i] != ele1)
        {
            cnt2 = 1;
            ele2 = arr[i];
        }
        else if (arr[i] == ele1)
        {
            cnt1++;
        }
        else if (arr[i] == ele2)
        {
            cnt2++;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (ele1 == arr[i])
            cnt1++;
        if (ele2 == arr[i])
            cnt2++;
    }

    int maxi = (int)(arr.size() / 3) + 1;

    if (cnt1 >= maxi)
        cout << ele1 << " ";
    if (cnt2 >= maxi)
        cout << ele2;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
    majorityelements1(arr);
    // majorityelements2(arr);
    return 0;
}