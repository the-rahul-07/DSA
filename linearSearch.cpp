#include <iostream>

using std ::cin;
using std ::cout;

int linerS(int arr[], int n, int num)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            return i + 1;
            break;
        }
    }
    return -1;
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

    int num;
    cin >> num;
    cout << linerS(arr, n, num);
    return 0;
}