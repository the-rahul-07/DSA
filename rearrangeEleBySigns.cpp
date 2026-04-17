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

// OPTIMAL SOLN TC = O(n), SC = O(n)
// only when POSITIVES = NEGATIVES
void rearrange2(int arr[], int n)
{
    int i = 0;
    vector<int> ans(n);
    int posIndx = 0;
    int negIndx = 1;
    while (i < n)
    {
        if (arr[i] > 0)
        {
            ans[posIndx] = arr[i];
            posIndx += 2;
        }
        else
        {
            ans[negIndx] = arr[i];
            negIndx += 2;
        }
        i++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}

// OPTIMAL SOLN FOR POSITIVES!=NEGATIVES
//  TC = O(2n), SC = O(N)
void rearrange3(int arr[], int n)
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
    if (posi.size() > neg.size())
    {
        // putting element till positives = negatives
        for (int i = 0; i < neg.size(); i++)
        {
            arr[2 * i] = posi[i];
            arr[2 * i + 1] = neg[i];
        }

        // putting the remaining places by positives elements
        int indx = neg.size() * 2;
        for (int i = neg.size(); i < posi.size(); i++)
        {
            arr[indx] = posi[i];
            indx++;
        }
    }
    else
    {

        // putting till positives = negatives
        for (int i = 0; i < posi.size(); i++)
        {
            arr[2 * i] = posi[i];
            arr[2 * i + 1] = neg[i];
        }

        // putting negatives elements
        int indx = posi.size() * 2;
        for (int i = posi.size(); i < neg.size(); i++)
        {
            arr[indx] = neg[i];
            indx++;
        }
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
    // rearrange(arr, n);       //brute force soln
    // rearrange2(arr, n);      //optimal soln when POSITIVES = NEGATIVES
    rearrange3(arr, n); // optimal soln whne POSITIVES != NEGATIVES
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}