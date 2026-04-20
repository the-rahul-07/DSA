#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

// TC = O(n2), SC = O(n2)
void rotateMatrix(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    vector<vector<int>> newarr(n, vector<int>(m, 0));

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            newarr[j][arr.size() - 1 - i] = arr[i][j];
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            arr[i][j] = newarr[i][j];
        }
    }
}

// OPTIMAL SOLN TC = O(n2), SC = O(1)
// here 1st we took transpose of matrix and then we made each row reverse
//  if u observe every column is becoming row form this we got idea of transpose
//  and the transpose matrix every row is getting reversed to rotate matrix by 90
void rotateMatrix2(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr[i].size(); j++)
        {
            if (i == j)
            {
                continue;
            }
            else
            {
                swap(arr[i][j], arr[j][i]);
            }
        }
        reverse(arr[i].begin(), arr[i].end());
    }
}

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    rotateMatrix2(arr);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}