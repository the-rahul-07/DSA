#include<iostream>
#include<bits/stdc++.h>

using std :: cout;
using std :: cin;
using namespace std;

void print(vector<int>&arr){
    int n = arr.size();
    for(auto m : arr) cout<<m<<" ";
    if(n==0) cout<<"{}";
    cout<<endl;
}

void subsequence(int indx, vector<int>&arr, vector<int>&subs, int n){
    if(indx>=n){
        print(subs);
        return;
    }
    
    // PICK OR TAKE ELEMENT
    subs.push_back(arr[indx]);
    subsequence(indx+1, arr, subs, n);

    // DONT PICK OR DONT TAKE ELEMENT
    subs.pop_back();
    subsequence(indx+1, arr, subs, n);
}

int main() {
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    vector<int>subs;
    subsequence(0, arr, subs, n);
    return 0;
}