#include<iostream>
#include<bits/stdc++.h>

using std :: cout;
using std :: cin;
using namespace std;

void subset1(int i, vector<int>&vec, int sum, vector<int>&subSum){
    if(i == vec.size()){
        subSum.push_back(sum);
        return;
    }

    sum +=vec[i];
    subset1(i+1, vec, sum, subSum);
    sum -=vec[i];

    subset1(i+1, vec, sum, subSum);
}
int main() {
    int n;
    cin>>n;

    vector<int>vec(n);
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }

    vector<int>subSum;
    subset1(0,vec,0, subSum);
    sort(subSum.begin(), subSum.end());

    for (int j = 0; j < subSum.size(); j++)
    {
        cout<<subSum[j]<<" ";
    }
    
    return 0;
}