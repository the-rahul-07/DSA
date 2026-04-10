#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

// Brute force Approach -> TC = O(n1logn+n2logn+(n1+n2))
void uni(int arr1[], int arr2[], int n1, int n2)
{
    set<int> u;
    // tc = o(n1logn)
    for (int i = 0; i < n1; i++)
    {
        u.insert(arr1[i]);
    }
    // tc = o(n2logn)
    for (int i = 0; i < n2; i++)
    {
        u.insert(arr2[i]);
    }

    // putting sets elements to array
    // tc = O(n1+n2)
    int arr[u.size()];
    int indx = 0;
    for (auto it : u)
    {
        arr[indx] = it;
        indx++;
    }

    // output
    for (int j = 0; j < u.size(); j++)
    {
        cout << arr[j] << " ";
    }
}

// optimal approach -> TC = O(n1+n2) & SC = O(n1+n2)
void uni2(int arr1[], int arr2[], int n1, int n2)
{
    int i = 0;
    int j = 0;
    list<int> ls;

    while (i < n1 && i < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            if (ls.size() == 0 || ls.back() != arr1[i])
            {
                ls.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if (ls.size() == 0 || ls.back() != arr2[j])
            {
                ls.push_back(arr2[j]);
            }
            j++;
        }
    }
    while (i < n1)
    {
        if (ls.size() == 0 || ls.back() != arr2[i])
        {
            ls.push_back(arr2[i]);
        }
        i++;
    }
    while (j < n2)
    {
        if (ls.size() == 0 || ls.back() != arr2[j])
        {
            ls.push_back(arr2[j]);
        }
        j++;
    }

    for (auto it : ls)
    {
        cout << it << " ";
    }
}

int main()
{
    int n1;
    cin >> n1;

    int arr1[n1];
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }

    int n2;
    cin >> n2;

    int arr2[n2];
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }

    // uni(arr1, arr2, n1, n2);
    uni2(arr1, arr2, n1, n2);
    return 0;
}