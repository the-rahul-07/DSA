#include<iostream>
#include<bits/stdc++.h>

using std :: cout;
using std :: cin;
using namespace std;

//Brute force approach - TC = O(NlogN+N)
int duplicate1(vector<int> &v){
    set<int> st;
    for(int i=0; i<v.size(); i++){
        st.insert(v[i]);
    }

    int index=0;
    for(auto it:st){
        v[index] = it;
        index++;
    }
    return index;
}

//optimal approach -> TC = O(N)
int duplicate2(vector<int> &v){
    int i=0;
    for(int j=0; j<v.size(); j++){
        if(v[j]!=v[i]){
            v[i+1] = v[j];
            i++;        
        }
    }
    return i+1;
}
int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < v.size(); i++)
    {
        cin>>v[i];
    }
    // int indx1 = duplicate1(v);
    int indx2 = duplicate2(v);
    for(int i=0; i<indx2; i++){
        cout<<v[i] << " ";
    }
    return 0;
}