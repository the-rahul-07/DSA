#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

// BRUTE FORCE SOLN TC = O(n2), SC = O(n)
void leaders1(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        bool lead = true;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                lead = false;
                break;
            }
        }
        if (lead == true)
        {
            ans.push_back(arr[i]);
        }
    }

    for (int l = 0; l < ans.size(); l++)
    {
        cout << ans[l] << " ";
    }
}

// OPTIMAL SOLN by me TC = O(n), stores indexs of maximum
void leaders2(vector<int> &arr)
{
    vector<int> lead;
    int n = arr.size();
    int big = n - 1;
    int j = n - 1;

    lead.push_back(arr[n - 1]);
    while (j > 0)
    {
        if (arr[j - 1] > arr[big])
        {
            lead.push_back(arr[j - 1]);
            big = j - 1;
        }
        j--;
    }
    for (int l = 0; l < lead.size(); l++)
    {
        cout << lead[l] << " ";
    }
}

// OPTIMAL SOLN STRIVER TC = O(n), stores maximum VALUE
void leaders3(vector<int> &arr)
{
    vector<int> lead;
    int n = arr.size();

    int max = INT_MIN;
    int j = n - 1;

    while (j >= 0)
    {
        if (arr[j] > max)
        {
            lead.push_back(arr[j]);
            max = arr[j];
        }
        j--;
    }
    for (int l = 0; l < lead.size(); l++)
    {
        cout << lead[l] << " ";
    }
}

// same as above just changed in putting the maxi
void leaders4(vector<int> &arr)
{
    vector<int> lead;
    int n = arr.size();

    int maxi = INT_MIN;
    int j = n - 1;

    while (j >= 0)
    {
        if (arr[j] > maxi)
        {
            lead.push_back(arr[j]);
        }
        maxi = max(maxi, arr[j]);
        j--;
    }
    for (int l = 0; l < lead.size(); l++)
    {
        cout << lead[l] << " ";
    }
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
    // leaders1(arr);       //brute force soln
    // leaders2(arr);       //optimal soln, me
    leaders3(arr); // optimal soln, striver
    return 0;
}