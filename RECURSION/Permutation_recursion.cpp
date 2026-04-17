#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

void permute(vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans, int mpp[])
{
    // BASE CONDN WHEN ds CONTAINS ONE COMPLETE PERMUTATION
    if (ds.size() == arr.size())
    {
        // PUSHING ds TO THE ANS, PUTTING PERMUTATION TO THE ANS
        ans.push_back(ds);
        return;
    }

    // RUNNING A LOOP
    // Try placing every unused element in the current position
    for (int i = 0; i < arr.size(); i++)
    {
        // CHECKING IF THE ELEMENT IS TAKEN OR NOT
        // If arr[i] is not already used in current permutation
        if (!(mpp[i]))
        {

            // IF NOT TAKEN THEN PUTTING IT IN ds
            ds.push_back(arr[i]);
            // MARKING THAT ELEMENT AS 1 MEANS TAKEN
            mpp[i] = 1;
            // CALLING THE FUNCTION AGAIN
            permute(arr, ds, ans, mpp);

            // UNMARKING THE ELEMENT AS SOME BATCH OF PERMUTATIONS ARE DONE MEANS
            //  FIRST i=0; means element 1
            //  SO 1 2 3 & 1 3 2 IS DONE FIRST IN RECURSION TREE
            //  SO NOW WE UNMARKS 1 SO THAT IT CAN BE USED IN NEXT BATCH

            // Backtrack: mark arr[i] as unused so it can be used in other permutations
            mpp[i] = 0;

            // WHEN ONE PERMUTATION IS DONE
            // THEN WE ARE REMOVING THE ELEMENTS FROM ds TO STORE THE NEXT PREMUTATION

            // Backtrack: remove the last added element and try the next possibility
            ds.pop_back();
        }
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
    vector<vector<int>> ans; // STORES THE PERMUTATIONS
    vector<int> ds;          // CONTAINER TO STORE NUMBERS ONE BY ONE THIS ds WILL FINALLY GO TO THE ANS VECTOR
    int mpp[n] = {0};        // MARKS WHICH ELEMENT IS PICKED WHICH IS NOT

    permute(arr, ds, ans, mpp);

    // OUTPUTTING THE PERMUTATIONS
    for (auto it : ans)
    {
        for (auto x : it)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}