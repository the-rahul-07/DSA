#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

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

void matrixZeros2(vector<vector<int>> &arr)
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

void matrixZeros3(vector<vector<int>> &arr)
{
    int k = 0;
    int l = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {

            if (arr[i][j] == 0)
            {
                while (k < arr.size())
                {
                    arr[i][k] = 0;
                    k++;
                }
                k = 0;

                while (l < arr[0].size())
                {
                    arr[l][j] = 0;
                    l++;
                }
                l = 0;
            }
        }
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
    matrixZeros3(arr);
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