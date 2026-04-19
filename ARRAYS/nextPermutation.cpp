#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

void permute(int index, vector<int> &arr, vector<vector<int>> &ans)
{
    if (index == arr.size())
    {
        ans.push_back(arr);
        return;
    }

    for (int i = index; i < arr.size(); i++)
    {
        swap(arr[index], arr[i]);
        permute(index + 1, arr, ans);
        swap(arr[index], arr[i]);
    }
}

// better soln using STL
void permute1(vector<int> &arr)
{
    next_permutation(arr.begin(), arr.end());
}

// OPTIMAL SOLN TC = O(3n), SC = O(n)
void permute2(vector<int> &arr)
{
    int indx = -1;
    int n = arr.size();
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            indx = i;
            break;
        }
    }
    if (indx == -1)
        reverse(arr.begin(), arr.end());

    for (int i = n - 1; i >= indx; i--)
    {
        if (arr[i] > arr[indx])
        {
            swap(arr[i], arr[indx]);
            break;
        }
    }

    reverse(arr.begin() + indx + 1, arr.end());
    return;
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

    // BRUTE FORCE SOLN

    // vector<int> origarr = arr;
    // vector<vector<int>> ans;

    // permute(0, arr, ans);

    // sort(ans.begin(), ans.end());

    // for (int i = 0; i < ans.size(); i++)
    // {
    //     if (ans[i] == origarr)
    //     {
    //         int indx = (i + 1) % ans.size();

    //         for (auto it : ans[indx])
    //         {
    //             cout << it << " ";
    //         }
    //         break;
    //     }
    // }

    // permute1(arr);   // BETTER SOLN USING STL
    permute2(arr); // OPTIMAL SOLN - 3n
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}