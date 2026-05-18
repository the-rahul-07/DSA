#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

bool canweplace(vector<int> &stalls, int dist, int cows)
{
    int n = stalls.size();
    int cntcow = 1;
    int lastplaced = stalls[0];
    for (int j = 0; j < n; j++)
    {
        if (stalls[j] - lastplaced >= dist)
        {
            lastplaced = stalls[j];
            cntcow++;
        }
        if (cntcow == cows)
        {
            return true;
        }
    }
    return false;
}

// tc = o((max-min)*n)
int aggressiveCows1(vector<int> &stalls, int ncow)
{
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();

    int dist = (stalls[n - 1] - stalls[0]);
    for (int i = 0; i < dist; i++)
    {
        if (canweplace(stalls, i, ncow) == true)
        {
            continue;
        }
        else
        {
            return (i - 1);
        }
    }
    return -1;
}

// tc = nlogn+ log2(max-min) + n
int aggressiveCows2(vector<int> &stalls, int ncow)
{
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int low = 1;
    int high = (stalls[n - 1] - stalls[0]);

    while (low <= high)
    {
        // mid is ntg but minidist
        int mid = (low + high) / 2;

        if (canweplace(stalls, mid, ncow) == true)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}

int main()
{
    int n;
    cin >> n;

    vector<int> stalls(n);
    for (int i = 0; i < n; i++)
    {
        cin >> stalls[i];
    }

    int ncow;
    cin >> ncow;

    // cout << aggressiveCows1(stalls, ncow);
    cout << aggressiveCows2(stalls, ncow);
    return 0;
}