#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

void pascaltriangle(int n, int r, int c)
{
    vector<vector<int>> arr(n, vector<int>(n));

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (j == 0)
            {
                arr[i][0] = 1;
            }
            else if (i == j)
            {
                arr[i][i] = 1;
            }
            else
            {
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            }
        }
    }

    cout << arr[r][c];
}

// TC = O(r), SC = O(1)
// Ques -> find element in pascals triangle at any position [n][c];
// to do it easily we use nCr formula, but n goes as n-1 and c goes as c-1
// in this to find index
void pascaltriangle2(int n, int r)
{
    int nu = 1;
    int ans;
    for (int i = 0; i < r; i++)
    {
        nu = nu * (n - i);
        ans = nu / (i + 1);
    }
    cout << ans;
}

// Ques -> print any nth row in pascals triangle
// TC = O(N), SC = O(1)
void pascaltriangle3(int n)
{
    int ans = 1;
    cout << ans << " ";
    for (int i = 1; i < n; i++)
    {
        ans = ans * (n - i);
        ans = ans / (i);
        cout << ans << " ";
    }
}

// TC = O(N2)
// Printing pascals triangle give row number N
vector<int> generateRow(int n)
{
    long long ans = 1;
    vector<int> ansrow;
    ansrow.push_back(1);
    for (int i = 1; i < n; i++)
    {
        ans = ans * (n - i);
        ans = ans / i;
        ansrow.push_back(ans);
    }
    return ansrow;
}
void pascaltriangle4(int n)
{
    vector<vector<int>> triangle;
    for (int i = 1; i <= n; i++)
    {
        triangle.push_back(generateRow(i));
    }
    for (int i = 0; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    // int r;
    // cin >> r;

    // int c;
    // cin>>c;
    // pascaltriangle(n, r, c);
    // pascaltriangle2(n - 1, r - 1);
    // pascaltriangle3(n);
    pascaltriangle4(n);
    return 0;
}