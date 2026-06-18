#include<iostream>
#include<bits/stdc++.h>

using std :: cout;
using std :: cin;
using namespace std;

//tc = O(n*logn)
int cntrow(vector<int>&arr, int x){
    int m = arr.size();
    int low = 0;
    int high = m-1;
    int ans = m;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]>=x){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}
int maxOnces(vector<vector<int>>&arr){
    int n = arr.size();
    int m = arr[0].size();

    int indx = -1;
    int max_cnt = 0;

    for(int i=0; i<n; i++){
        int cnt_onces = m-cntrow(arr[i], 1);
        if(cnt_onces>max_cnt){
            max_cnt = cnt_onces;
            indx = i;
        }
    }
    return indx;
}

int main() {
    int n;
    cin>>n;
    int m;
    cin>>m;

    vector<vector<int>>arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
        }
    }

    cout<<maxOnces(arr);
    
    return 0;
}