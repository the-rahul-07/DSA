#include<iostream>
#include<bits/stdc++.h>

using std :: cout;
using std :: cin;
using namespace std;

void combSum2(int indx, vector<int>&candidates, int target, vector<vector<int>>&combinations, vector<int>&ans){
        if(target == 0){
            combinations.push_back(ans);
            return;
        }

        for(int i = indx; i<candidates.size(); i++){
            if(i>indx && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            ans.push_back(candidates[i]);
            combSum2(i+1, candidates, target-candidates[i], combinations, ans);
            ans.pop_back();
        }
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

    sort(candidates.begin(), candidates.end());
    combSum2(0, candidates, target, combinations, ans);

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