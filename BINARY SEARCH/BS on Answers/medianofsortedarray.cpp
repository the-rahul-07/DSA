#include<iostream>
#include<bits/stdc++.h>

using std :: cout;
using std :: cin;
using namespace std;

double medianArr1(vector<int>&arr1, vector<int>&arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();

    vector<int>arr3;
    int i=0;
    int j=0;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            arr3.push_back(arr1[i]);
            i++;
        }else{
            arr3.push_back(arr2[j]);
            j++;
        }
    }
    while(i<n1) arr3.push_back(arr1[i++]);
    while(j<n2) arr3.push_back(arr2[j++]);

    int n = arr3.size();
    if(n%2==1){
        return arr3[n/2];
    }  
    return (double) ((double)arr3[n/2]+(double)arr3[n/2-1])/2.0;
}

double medianArr2(vector<int>&arr1, vector<int>&arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();

    int n = n1+n2;

    if(n==0) return 0;
    int indx1 = n/2;
    int indx2 = indx1 -1;

    int i=0;
    int j=0;
    int cnt = 0;

    int indx1Ele = 0;
    int indx2Ele = 0;


    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            if(cnt == indx1) indx1Ele = arr1[i];
            if(cnt == indx2) indx2Ele = arr1[i];
            cnt++;
            i++;
        }else{
            if(cnt == indx1) indx1Ele = arr2[j];
            if(cnt == indx2) indx2Ele = arr2[j];
            cnt++;
            j++;
        }
    }

    while(i<n1){
        if(cnt == indx1) indx1Ele = arr1[i];
        if(cnt == indx2) indx2Ele = arr1[i];
        cnt++;
        i++;
    }
    while(j<n2){
        if(cnt == indx1) indx1Ele = arr2[j];
        if(cnt == indx2) indx2Ele = arr2[j];
        cnt++;
        j++;
    }

    if(n%2==0){
        return (double)(indx1Ele+indx2Ele)/2.0;
    }
    return (double)(indx1Ele);
}

double medianArr3(vector<int>&arr1, vector<int> &arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();

    int n = n1+n2;
    int left = (n1+n2+1)/2;

    if(n1>n2) return medianArr3(arr2, arr1);
    int low = 0, high =n1; 

    
    while(low<=high){
        int mid1 = low + (high-low)/2;
        int mid2 = left - mid1;

        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if(mid1-1>=0) l1 = arr1[mid1-1];
        if(mid2-1>=0) l2 = arr2[mid2-1];
        if(mid1<n1) r1 = arr1[mid1];
        if(mid2<n2) r2 = arr2[mid2];

        if(l1<=r2 && l2<=r1){
            if(n%2==0)
                return (double)(max(l1,l2)+min(r1, r2))/2.0;
            else
                return max(l1,l2);
        }else if(l1>r2){
            high = mid1-1;
        }else{
            low = mid1+1;
        }
    }

    return 0;
}

int main() {
    int n1;
    cin>>n1;
    vector<int>arr1(n1);
    for (int i = 0; i < n1; i++)
    {
        cin>>arr1[i];
    }

    int n2;
    cin>>n2;
    
    vector<int>arr2(n2);
    for (int j = 0; j < n2; j++)
    {
        cin>>arr2[j];
    }
    
    // cout<<medianArr1(arr1, arr2);
    // cout<<medianArr2(arr1, arr2);
    cout<<medianArr3(arr1, arr2);
    return 0;
}