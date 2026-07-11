#include<iostream>
#include<bits/stdc++.h>

using std :: cout;
using std :: cin;
using namespace std;

int sumK(int i, vector<int>&arr, int k, int sum){
    if(i==arr.size()){
        if(sum==k)
            return 1;
        else
            return 0;
    }

    sum +=arr[i];
    int l = sumK(i+1, arr, k, sum);
   
    sum -=arr[i];
    int r = sumK(i+1, arr, k, sum);
    return l+r;
}

int main() {
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    int k;
    cin>>k;

    cout<<sumK(0, arr, k, 0);
    return 0;
}