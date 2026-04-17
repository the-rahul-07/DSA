#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

// left rotate by one index
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

// OPTIMAL SOLN - TC = O(2n) & SC = O(1)
void rotateLeftD3(vector<int> &arr, int n, int d)
{
    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.end());
    reverse(arr.begin(), arr.end());
}

void rightRotate(vector<int> &arr, int d, int n)
{
    d = d % n;
    reverse(arr.begin(), arr.begin() + n - d);
    reverse(arr.begin() + n - d, arr.end());
    reverse(arr.begin(), arr.end());
}

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
    // rotateLeftD2(arr, d);
    // rotateLeftD3(arr,n , d);
    rightRotate(arr, d, n);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}