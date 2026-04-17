#include<iostream>
#include<bits/stdc++.h>

using std :: cout;
using std :: cin;
using namespace std;

void permute(int index, vector<int> &arr, vector<vector<int>> &ans){
    if(index == arr.size()){
        ans.push_back(arr);
        return;
    }

    for (int i = index; i < arr.size(); i++)
    {
        swap(arr[index], arr[i]);
        permute(index+1, arr, ans);
        swap(arr[index],arr[i]);
    }
}
int main() {
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    vector<vector<int>> ans;
    permute(0, arr, ans);
    
    int m;
    for(auto it:ans){
        for(auto x : it){
            for(int i=0; i<n; i++){
                if(x==arr[i]){
                    m = x+1;
                }
            }
        }
    }
    cout<<m;
    return 0;
}