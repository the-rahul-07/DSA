#include <iostream>
#include <bits./stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

// brute forces by me TC = O(n1*n2)
void intersect(int arr1[], int arr2[], int n1, int n2)
{
    int i = 0, j = 0;
    list<int> ls;
    while (i < n1)
    {
        for (int x = 0; x < n2; x++)
        {
            if (arr1[i] == arr2[x])
            {
                if (ls.size() == 0 || ls.back() != arr1[i])
                {
                    ls.push_back(arr1[i]);
                }
            }
        }
        i++;
    }

    for (auto it : ls)
    {
        cout << it << " ";
    }
}

// brute force approach TC = O(n1*n2)
void intersect3(int arr1[], int arr2[], int n1, int n2)
{
    vector<int> ans;
    int visited[n2] = {0};
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (arr1[i] == arr2[j] && visited[j] == 0)
            {
                ans.push_back(arr1[i]);
                visited[j] = 1;
                break;
            }
            if (arr2[j] > arr1[i])
                break;
        }
    }
    for (auto it : ans)
    {
        cout << it << " ";
    }
}

// OPTIMAL APPROACH TC = O(n1+n2) & SC = O(n1+n2)
// this are at the worst cases
void intersect2(int arr1[], int arr2[], int n1, int n2)
{
    int i = 0, j = 0;
    vector<int> is;

    while (i <= n1 && j <= n2)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            is.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    for (auto it : is)
    {
        cout << it << " ";
    }
}

// optimal code written by me
//  for (int x = 0; x < n1; x++)
//  {
//      if (arr1[i] == arr2[j])
//      {
//          is.push_back(arr1[i]);
//          i++;
//          j++;
//      }
//      else
//      {
//          i++;
//      }
//      if (i > n1)
//          break;
//  }

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

    // intersect(arr1, arr2, n1, n2);  //brute force 1
    // intersect3(arr1, arr2, n1, n2);  //brute force 2
    intersect2(arr1, arr2, n1, n2); // optimal soln
    return 0;
}