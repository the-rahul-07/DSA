#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

// BRUTE FORCE SOLN
vector<vector<int>> sum1(vector<int> &arr)
{
    set<vector<int>> st;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i+1; j < arr.size(); j++)
        {
            for (int k = j+1; k < arr.size(); k++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> triplets(st.begin(), st.end());
    return triplets;
}
// BETTER SOLN
vector<int> sum2(vector<int> &arr)
{
    map<int, int> mpp;
    vector<int> indx;
    int n = arr.size();
    int x = arr[0];
    int j = n - 1;
    int target = -x;
    indx.push_back(x);

    for (int i = 0; i < n; i++)
    {
        int req = target - arr[i];
        if (mpp.find(req) != mpp.end())
        {
            indx.push_back(i);
            indx.push_back(mpp[req]);
        }
        mpp[arr[i]] = i;
    }
    return indx;
}

vector<vector<int>> sum3(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<vector<int>> triplets;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
        {
            i++;
            continue;
        }
        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0)
            {
                j++;
            }

            else if (sum > 0)
            {
                k--;
            }
            else
            {
                triplets.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;
                while (j < k && arr[j] == arr[j - 1])
                    j++;
                while (j < k && arr[k] == arr[k + 1])
                    k--;
            }
        }
    }
    return triplets;
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

    vector<vector<int>> indx = sum1(arr);

    for (int i = 0; i < indx.size(); i++)
    {
        for (int j = 0; j < indx[i].size(); j++)
        {
            cout << indx[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}