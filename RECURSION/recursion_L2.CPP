#include<iostream>
#include<bits/stdc++.h>

using std :: cout;
using std :: cin;
using namespace std;

void num1toN(int i, int n){
    if(i>n) return;

    cout<<i<<endl;
    num1toN(i+1, n);
}

void numNto1(int i){
    if(i==0) return;
    cout<<i<<endl;

    numNto1(i-1);
}


// BACKTRACKING
// 1 TO N;

void fun1(int i, int n){
    if(i<1) return;

    fun1(i-1, n);
    cout<<i<<endl;
}

// N TO 1;

void fun2(int i, int n){
    if(i>n) return;

    fun2(i+1, n);
    cout<<i<<endl;
}

int main() {
    int n;
    cin>>n;
    
    num1toN(1, n);

    cout<<endl;
    
    numNto1(n);
    
    cout<<endl;

    fun1(n, n);

    cout<<endl;

    fun2(1, n);
    return 0;
}