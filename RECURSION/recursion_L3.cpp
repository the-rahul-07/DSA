#include<iostream>
#include<bits/stdc++.h>

using std :: cout;
using std :: cin;
using namespace std;

// parametrized sum 1 to n

void fun1(int i, int sum){
    if(i<1){
        cout<<sum;
        return;
    }

    fun1(i-1, sum+i);
}

// FUNCTIONAL WAY - DP
int fun2(int n){
    if(n==0) return 0;

    return n + fun2(n-1);
}


int fun3(int i, int n){
    if(i>n) return 0;

    int sum=fun3(i+1, n);
    sum +=i;
    return sum;
}

// FACTORIAL OF N;

int fact(int n){
    if(n==0) return 1;

    return n * fact(n-1);
}

int main() {
    int n;
    cin>>n;

    fun1(n, 0);

    cout<<endl;
    
    int r = fun2(n);
    cout<<r;
    
    cout<<endl;

    int r1 = fact(n);
    cout<<r1;
    return 0;
}