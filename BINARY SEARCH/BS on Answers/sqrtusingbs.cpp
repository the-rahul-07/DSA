#include<iostream>
#include<bits/stdc++.h>

using std :: cout;
using std :: cin;
using namespace std;

int sqrroot(int num){
    int low =1;
    int high = num;
    
    while(low<=high){
        int mid = (low+high)/2;

        if((mid*mid)<=num){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return high;
}

int main() {
    int num;
    cin>>num;
    cout<< sqrroot(num);
    return 0;
}