#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

int fun(int arr[], int n)
{
    vector<int> temp;

    temp.push_back(arr[0]);
    for (int i = 0; i < n; i++)
    {
        if (temp.back() != arr[i])
        {
            temp.push_back(arr[i]);
        }
    }

    int indx = 0;
    for(auto it:temp){
        arr[indx] = it;
        indx++;
    }
    return temp.size();
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
    int k = fun(arr, n);
    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}