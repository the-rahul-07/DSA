#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

// brute force soln TC = O(n+n/2)
void rearrange(int arr[], int n)
{
    vector<int> posi;
    vector<int> neg;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            posi.push_back(arr[i]);
        }
        else
        {
            neg.push_back(arr[i]);
        }
    }

    int x = 0, y = 0;
    for (int i = 0; i < n / 2; i++)
    {
        // better way
        arr[2 * i] = posi[i];
        arr[2 * i + 1] = neg[i];

        // if (i % 2 == 0)
        // {
        //     arr[i] = posi[x];
        //     x++;
        // }
        // else
        // {
        //     arr[i] = neg[y];
        //     y++;
        // }
    }
}
int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    rearrange(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}