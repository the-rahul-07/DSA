#include <iostream>
#include <bits/stdc++.h>
using std ::cin;
using std ::cout;
using namespace std;

void stocks(int arr[], int n)
{
    int buyday;
    int saleday;
    int min = arr[0];
    int max;
    int profit;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            buyday = i + 1;
        }
    }

    max = arr[buyday];
    for (int j = buyday; j < n; j++)
    {
        if (arr[j] > max)
        {
            max = arr[j];
            saleday = j + 1;
        }
    }
    profit = max - min;
    cout << "buying day - " << buyday << " | price - " << max << " rupees" << "\n";
    cout << "selling day - " << saleday << "  | price - " << min << " rupees" << "\n";
    cout << "profit - " << profit << " rupees" << "\n";
}

void stocks2(int arr[], int n)
{
    int mini = arr[0];
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        int cost = arr[i] - mini;
        profit = max(profit, cost);
        mini = min(mini, arr[i]);
    }
    cout << "profit - " << profit << " rupees" << "\n";
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

    stocks2(arr, n);

    return 0;
}