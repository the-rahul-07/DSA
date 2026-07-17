#include<iostream>
#include<bits/stdc++.h>

using std :: cout;
using std :: cin;
using namespace std;

void subs2(vector<int>&nums, int indx, vector<int>&vec, vector<vector<int>>&ans){
    ans.push_back(vec);
    for(int i=indx; i<nums.size(); i++){
        if(indx != i && nums[i] == nums[i-1]) continue;
        vec.push_back(nums[i]);
        subs2(nums, i+1, vec, ans);
        vec.pop_back();
    }
}

int main() {
    int n;
    cin>>n;

    vector<int>nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;
    vector<int> vec;

    subs2(nums, 0, vec, ans);

    for (int j = 0; j < ans.size(); j++)
    {
        for (int k = 0; k < ans[j].size(); k++)
        {
            cout<<ans[j][k]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}