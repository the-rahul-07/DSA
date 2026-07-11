#include<iostream>
#include<bits/stdc++.h>

using std :: cout;
using std :: cin;
using namespace std;

void print(vector<int>&tempArr){
    int n = tempArr.size();
    if(n==0) cout<<"{}";
    for(auto m : tempArr) cout<<m<<" ";

    cout<<endl;
}
void sumK(int i, vector<int>&arr, vector<int>&tempArr, int k, int sum){
    if(i==arr.size()){
        if(sum==k){
            print(tempArr);
        }   
        return;
    }

    tempArr.push_back(arr[i]);
    sum +=arr[i];
    sumK(i+1, arr, tempArr, k, sum);
    tempArr.pop_back();
    sum -=arr[i];
    sumK(i+1, arr, tempArr, k, sum);
}
int main() {
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    int k;
    cin>>k;

    vector<int>tempArr;
    sumK(0, arr, tempArr, k, 0);
    return 0;
}