#include <iostream>

using std ::cin;
using std ::cout;
using namespace std;

void Selection_Sort(int arr[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        int temp;
        int mini = i;
        for (int j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[mini])
            {
                mini = j;
            }
        }
        temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}

void Bubble_Sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int did_Swap = 0;
        // for(int j=0; j<n-i; j++)
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                did_Swap = 1;
            }
        }
        if (did_Swap == 0)
        {
            break;
        }
    }
}

void Bubble_Sort_2(int arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        int did_Swap = 0;
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                did_Swap = 1;
            }
        }
        if (did_Swap == 0)
        {
            break;
        }
    }
}

void insertion_Sort(int arr[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        int j = i;
        int did_Swap = 0;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
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

    // Selection_Sort(arr,n);
    // Bubble_Sort(arr, n);
    insertion_Sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}