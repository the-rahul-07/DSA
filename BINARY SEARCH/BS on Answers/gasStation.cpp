#include<iostream>
#include<bits/stdc++.h>

using std :: cout;
using std :: cin;
using namespace std;

//brute force -- tc = (k*n)+n
long double gasStation1(vector<int>&arr, int k){
    int n = arr.size();
    vector<int>howMany(n-1,0);

    for(int gasStations=1; gasStations<=k; gasStations++){
        long double maxSection = -1;
        int maxIndx = -1;

        for(int i=0; i<n-1; i++){
            long double diff = arr[i+1]-arr[i];
            long double sectionLen = diff/(long double)(howMany[i]+1);
            if(sectionLen>maxSection){
                maxSection = sectionLen;
                maxIndx = i;
            }
        }
        howMany[maxIndx]++;
    }

    long double maxAns = -1;
    for(int i=0; i<n-1; i++){
        long double diff = arr[i+1]-arr[i];
        long double sectionLen = diff/(long double)(howMany[i]+1);

        maxAns = max(maxAns, sectionLen);
    }

    return maxAns;
}

//BETTER SOLN
//tc = nlogn+klogn;
//sc = n-1;

long double gasStation2(vector<int> &arr, int k){
    int n = arr.size();
    priority_queue<pair<long double, int>>pq;

    vector<int>howMany(n-1,0);
    //inserting all the sections in pq;
    for (int i = 0; i < n-1; i++)
    {
        pq.push({arr[i+1]-arr[i], i});
    }
    
    for(int gasStation=1; gasStation<=k; gasStation++){
        auto tp = pq.top(); pq.pop();
        int secInd = tp.second;
        howMany[secInd]++;
        long double initDiff = arr[secInd+1]-arr[secInd];
        long double newSecLen = initDiff/(long double)(howMany[secInd]+1);

        pq.push({newSecLen, secInd});
    }  
    
    return pq.top().first;
}

//OPTIMAL SOLN
//tc = 
//sc =

long double gasStation3(vector<int>&arr, int k){
    int n = arr.size();

}

int main() {
    int n;
    cin>>n;
    
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int k;
    cin>>k;

    // cout<<gasStation1(arr,k); 
    cout<<gasStation2(arr,k); 
    return 0;
}