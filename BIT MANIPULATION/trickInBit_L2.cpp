#include<iostream>
#include<bits/stdc++.h>

using std :: cout;
using std :: cin;
using namespace std;

void swapnum(int a, int b){
    a = a^b;
    b = a^b;
    a = a^b;

    cout<<a<<endl;
    cout<<b<<endl;
}

void checkSetUnset1(int n, int i){
    // left shift
    if((n & (1<<i)) != 0)
        cout<<true;
    else
        cout<<false;
}

void checkSetUnset2(int n, int i){
    if((n>>i & 1) != 0)
        cout<<true;
    else
        cout<<false;
}

void set1(int n, int i){
    cout<<(n | 1<<i);
}

void clear1(int n, int i){
    cout<<(n & ~(1<<i));
}

void toggle(int n, int i){
    cout<< (n^(1<<i));
}

void lastSetBit(int n){
    cout<< (n & (n-1));
}

void powerOf2(int n){
    cout<<(n>0 && (n & (n-1))==0);
}
int main() {
    int a = 10;
    int b = 20;

    swapnum(a,b);

    cout<<endl;

    checkSetUnset1(13, 2);
    cout<<endl;
    checkSetUnset2(13, 1);

    cout<<endl;
    set1(9, 2);

    cout<<endl;
    clear1(13, 2);

    cout<<endl;
    toggle(13,1);

    cout<<endl;
    lastSetBit(13);

    cout<<endl;
    powerOf2(5);
    return 0;
}