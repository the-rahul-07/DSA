#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

// First Approach
//  void moveleft(int n, int arr[], int k){
//      int temp = arr[k];
//      while(k<n-1){
//          arr[k]=arr[k+1];
//          k++;
//      }
//      arr[n-1] = temp;
//  }
//  void MoveZeros(int arr[], int n){
//      int temp;
//      for(int i=0; i<n; i++){
//          if(arr[i]==0){
//              moveleft(n,arr,i);
//              if(arr[i]!=0) i--;
//          }
//      }
//  }

// BRUTE FORCE -> TC = O(2n);
void MoveZeros1(vector<int> &arr, int n)
{
    list<int> ls;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            ls.push_back(arr[i]);
        }
    }
    int indx = 0;
    for (auto it : ls)
    {
        // arr.push_back(it);
        // cant use push back bcoz it adds elements at the end but we want to replace from front
        arr[indx] = it;
        indx++;
    }
    for (int i = ls.size(); i < n; i++)
    {
        arr[i] = 0;
    }
}

// OPTIMAL SOLN -> TC = O(n);
void MoveZeros2(vector<int> &arr, int n)
{
    int p1 = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            p1 = i;
            break;
        }
    }

    // if none of the element is zero
    if (p1 == -1)
        return;

    // i going from p1+1 bcoz p1 tak everything is nonzero
    for (int i = p1 + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[p1]);
            p1++;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // MoveZeros1(arr, n); // brute soln
    MoveZeros2(arr, n); // optimal soln

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}