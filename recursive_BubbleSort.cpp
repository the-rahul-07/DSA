#include <iostream>
#include <bits./stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

void recursive_Bubble(int arr[], int n)
{
    if (n == 1)
        return;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i + 1], arr[i]);
        }
    }
    recursive_Bubble(arr, n - 1);
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

    recursive_Bubble(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}