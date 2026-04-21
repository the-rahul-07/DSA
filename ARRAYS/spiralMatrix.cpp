#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

void spiralmatrix(vector<vector<int>> &arr)
{
    int right = arr[0].size() - 1;
    int left = 0;
    int top = 0;
    int bottom = arr.size() - 1;
    vector<int> values;

    while (left <= right && top <= bottom)
    {

        for (int i = left; i <= right; i++)
        {
            values.push_back(arr[top][i]);
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {

            values.push_back(arr[i][right]);
        }
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                values.push_back(arr[bottom][i]);
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                values.push_back(arr[i][left]);
            }
            left++;
        }
    }

    for (int i = 0; i < values.size(); i++)
    {
        cout << values[i] << " ";
    }
}

int main()
{
    int n;
    cin >> n;

    int m;
    cin >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cin >> arr[i][j];
        }
    }

    spiralmatrix(arr);
    return 0;
}