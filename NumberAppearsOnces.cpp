#include<iostream>
#include<bits/stdc++.h>

using std :: cout;
using std :: cin;
using namespace std;

int oncesAppears(int arr[],int n){
    int xor1=0;
    for(int i=0; i<n; i++){
        xor1 = xor1^arr[i];
    }
    return xor1;
}

int main() {
    int n;
    cin>>n;
    
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    cout<<oncesAppears;
    return 0;
}