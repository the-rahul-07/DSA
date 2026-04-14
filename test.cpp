#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

int fun(int arr[], int n)
{
    int i=0;
    int j=1;
    while (j < n)
    {
        if(arr[i]==arr[j]){

        }else{
            arr[i+1]=arr[j];
            i++;
        }
        j++;
    }
    return i + 1;
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