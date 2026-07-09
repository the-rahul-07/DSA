#include<iostream>
#include<bits/stdc++.h>

using std :: cout;
using std :: cin;
using namespace std;

// recursion using 2 pointers
void revArr1(vector<int>&arr, int l, int r){
    if(l>=r) return;

    swap(arr[l], arr[r]);
    revArr1(arr, l+1, r-1);
}

// recursion using single variable
void revArr2(vector<int>&arr, int i)
{
    if(i>(arr.size())/2) return;

    swap(arr[i], arr[arr.size()-i-1]);
    revArr2(arr, i+1);
}

bool palindrome(string &str, int i){
    if(i>=str.size()/2) return true;

    if(str[i]!=str[str.size()-i-1]) return false;

    return palindrome(str, i+1);
}

int main() {
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    string str;
    cin>>str;

    revArr1(arr, 0, n-1);
    for(auto m : arr) cout<<m<<" ";

    cout<<endl;
    
    revArr2(arr, 0);
    for(auto m : arr)  cout<<m<<" ";
    
    cout<<endl;

    cout<<palindrome(str, 0);
    return 0;
}