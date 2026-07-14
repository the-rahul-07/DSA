#include<iostream>
#include<bits/stdc++.h>

using std :: cout;
using std :: cin;
using namespace std;

void combSum1(int i, vector<int>&candidates, int target, vector<vector<int>>& combinations, vector<int>&ans){
        if(i == candidates.size()){
            if(target == 0){
                combinations.push_back(ans);
            }
            return;
        }

        if(target == 0){
            combinations.push_back(ans);
            return;
        }

        if(candidates[i]<=target){
            ans.push_back(candidates[i]);
            combSum1(i, candidates, target-candidates[i], combinations, ans);
            ans.pop_back();
        }

        combSum1(i+1, candidates, target, combinations, ans);
    }

int main() {
    int n;
    cin>>n;

    vector<int>candidates(n);
    for (int i = 0; i < n; i++)
    {
        cin>>candidates[i];
    }
    
    int target;
    cin>>target;

    vector<vector<int>>combinations;
    vector<int>ans;

    combSum1(0, candidates, target, combinations, ans);

    for (int j = 0; j < combinations.size(); j++)
    {
        cout<<"[";
        for (int k = 0; k < combinations[j].size(); k++)
        {
            cout<<combinations[j][k];
        }
        cout<<"],";
    }
    
    return 0;
}