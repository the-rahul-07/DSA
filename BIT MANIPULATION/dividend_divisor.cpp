#include<iostream>
#include<bits/stdc++.h>

using std :: cout;
using std :: cin;
using namespace std;

int main() {
    int dividend = 222;
    int divisor = 3;

    int sign = 1;
    if(dividend>0 && divisor<0) sign = -1;
    if(dividend<0 && divisor>0) sign = -1;

    long long a = llabs((long long)dividend);
    long long b = llabs((long long)divisor);
    long long ans = 0;
    while(a>=b){

        int cnt =0;

        while(a >= (b<<(cnt+1))){
            cnt++;
        }

        ans += 1LL<<cnt;
        a -= b<<(cnt);
    }

    if(ans == (1LL<<31) && sign<0)
        cout<<INT_MIN;
    else if(ans == (1LL<<31) && sign>0)
        cout<<INT_MAX;
    else  
        cout<<sign*ans;
    return 0;
}