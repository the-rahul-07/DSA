#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

// BRUTE FORCE SOLN
// TC = O(N3 + LOG(NO OF UNIQUE TRIPLETS))
// SC = O(2*NO OF TRIPLETS)
vector<vector<int>> sum1(vector<int> &arr)
{
    set<vector<int>> st;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            for (int k = j + 1; k < arr.size(); k++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    // SET STORES ONLY THE UNIQUE ELEMENTS
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> triplets(st.begin(), st.end());
    return triplets;
}

// BETTER SOLN
// TC = O(N2 + logM) -> near to n2 if we are using unordered set
// SC = O(N+ 2*NO OF UNIQUE TRIPLETS)
vector<vector<int>> sum2(vector<int> &arr)
{
    int n = arr.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        // declaring map in loop so that it get erased as i increment;
        set<int> hashset;
        for (int j = i + 1; j < n; j++)
        {
            int sum = -(arr[i] + arr[j]);
            if (hashset.find(sum) != hashset.end())
            {
                vector<int> temp = {sum, arr[i], arr[j]};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }
    vector<vector<int>> triplets(st.begin(), st.end());
    return triplets;
}

// OPTIMAL APPROACH
//  TC = O(NLOGN + N2);
//  SC = O(1)
vector<vector<int>> sum3(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<vector<int>> triplets;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
        {
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

    // vector<vector<int>> indx = sum1(arr);       //BRUTE FORCE SOLN
    // vector<vector<int>> indx = sum2(arr);       //BETTER APPROACH USING HASHMAP
    vector<vector<int>> indx = sum3(arr); // OPTIMAL APPROACH USING 2 POINTERS

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