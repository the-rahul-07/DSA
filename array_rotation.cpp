#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

void rotateLeft(vector<int> &arr)
{
    int temp = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[arr.size() - 1] = temp;
}

// Brute force - TC = O(d*n);
void rotateLeftD(vector<int> &arr, int d)
{
    for (int i = 0; i < d % arr.size(); i++)
    {
        int temp = arr[0];
        for (int j = 1; j < arr.size(); j++)
        {
            arr[j - 1] = arr[j];
        }
        arr[arr.size() - 1] = temp;
    }
}

// Brute force - TC = O(n+d) = O(d) + O(d) + O(n-d)
void rotateLeftD2(vector<int> &arr, int d)
{
    d = d % arr.size();
    int temp[d];
    for (int i = 0; i < d; i++)
    {
        temp[i] = arr[i];
    }
    for (int i = d; i < arr.size(); i++)
    {
        arr[i - d] = arr[i];
    }
    int j = 0;
    for (int i = arr.size() - d; i < arr.size(); i++)
    {
        arr[i] = temp[j];
        j++;
    }
}

// OPTIMAL SOLN - TC = O()
int main()
{
    int n;
    cin >> n;
    int d;
    cin >> d;
    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
    // rotateLeft(arr);
    rotateLeftD2(arr, d);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}