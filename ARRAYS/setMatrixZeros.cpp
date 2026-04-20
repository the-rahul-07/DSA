#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

// BRUTE FORCE SOLN TC = O(n*m + x(n+m))
// x is number of zeros
void matrixZeros1(vector<vector<int>> &arr)
{
    vector<pair<int, int>> zeros;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (arr[i][j] == 0)
            {
                zeros.push_back({i, j});
            }
        }
    }

    for (int k = 0; k < zeros.size(); k++)
    {
        auto it = zeros[k];
        int row = it.first;
        int colm = it.second;

        for (int j = 0; j < arr[0].size(); j++)
        {
            arr[row][j] = 0;
        }
        for (int m = 0; m < arr.size(); m++)
        {
            arr[m][colm] = 0;
        }
    }
}

// BRUTE FORCE SOLN TC = O(n3), SC = O(1)
void markrow(vector<vector<int>> &arr, int i)
{
    // this loop is to travel in the column,
    //  coz i is already given row is already given
    for (int j = 0; j < arr[0].size(); j++)
    {
        if (arr[i][j] != 0)
            arr[i][j] = -1;
    }
}
void markcolm(vector<vector<int>> &arr, int j)
{
    // this loop is to travel in the row,
    //  coz j is already given column is already given
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i][j] != 0)
            arr[i][j] = -1;
    }
}
void matrixZeros2(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            if (arr[i][j] == 0)
            {
                markrow(arr, i);
                markcolm(arr, j);
            }
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            if (arr[i][j] == -1)
            {
                arr[i][j] = 0;
            }
        }
    }
}

// BETTER SOLN TC = O(2*n*m)
//  SC = O(n+m) --> for storing indexs
void matrixZeros3(vector<vector<int>> &arr)
{
    vector<int> n(arr.size());
    vector<int> m(arr[0].size());

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (arr[i][j] == 0)
            {
                n[i] = 1;
                m[j] = 1;
            }
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (n[i] || m[j])
            {
                arr[i][j] = 0;
            }
        }
    }
}

// Optimal soln TC = O(2*n*m), SC = O(1)
void matrixZeros4(vector<vector<int>> &arr)
{
    int colm = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {

            if (arr[i][j] == 0)
            {
                arr[i][0] = 0;
                if (j != 0)
                {
                    arr[0][j] = 0;
                }
                else
                {
                    colm = 0;
                }
            }
        }
    }

    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = 1; j < arr[i].size(); j++)
        {
            if (arr[i][j] != 0)
            {
                if (arr[0][j] == 0 || arr[i][0] == 0)
                {
                    arr[i][j] = 0;
                }
            }
        }
    }
    if (arr[0][0] == 0)
    {
        for (int j = 0; j < arr[0].size(); j++)
            arr[0][j] = 0;
    }
    if (colm == 0)
    {
        for (int i = 0; i < arr.size(); i++)
            arr[i][0] = 0;
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

    // matrixZeros1(arr);      //brute force soln
    // matrixZeros2(arr);      //better soln
    // matrixZeros3(arr);
    matrixZeros4(arr);

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