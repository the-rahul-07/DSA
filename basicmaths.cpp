#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using std ::cin;
using std ::cout;

int min(int n1, int n2)
{
    if (n1 < n2)
        return n1;
    else
        return n2;
}
int power(int ld, int cnt)
{
    int cb = 1;
    for (int i = 0; i < cnt; i++)
    {
        cb *= ld;
    }
    return cb;
}
void lstdigit(int n)
{
    int ld;
    int cnt = 0;
    while (n > 0)
    {
        ld = n % 10;
        n = n / 10;
        cnt++;
    }

    cout << ld << "\n";
    cout << cnt << "\n";
}
void revNum(int n)
{
    int revno = 0;
    int ld;
    while (n > 0)
    {
        ld = n % 10;
        n = n / 10;
        revno = (revno * 10) + ld;
    }
    cout << revno << "\n";
}
void palindrome(int n)
{
    int dupli = n;
    int revno = 0;
    int ld;
    while (n > 0)
    {
        ld = n % 10;
        n = n / 10;
        revno = (revno * 10) + ld;
    }
    if (revno == dupli)
        cout << "Palindrome Number\n";
    else
        cout << "Not a palindrome number\n";
}
void armstrong(int n)
{
    int ld;
    int dupli = n;
    int temp = n;
    int cb = 0;
    int cnt = 0;
    while (temp > 0)
    {
        temp = temp / 10;
        cnt++;
    }
    while (n > 0)
    {
        ld = n % 10;
        n = n / 10;
        cb += power(ld, cnt);
    }
    if (cb == dupli)
        cout << "Armstrong number\n";
    else
        cout << "Not a armstrong number\n";
}
void divisors(int n)
{
    // you forgot tht if ke andar cout hoga so written long code
    /*
    std :: vector<int>div;
    int cnt=0;
    for (int i = 1; i <= n; i++)
    {
        if(n%i==0){
        div.push_back(i);
        cnt++;
        }
    }
    for (int j = 0; j < cnt ; j++)
    {
    cout<<div[j]<<" ";
    }
    */

    //***METHOD 2***
    // for (int i = 1; i <=n; i++)
    // {
    //     if(n%i==0)
    //     {
    //         cout<<i<<" ";
    //     }
    // }
    // TIME COMPLEXCITY OF THIS WAS O(N)

    /*METHOD 3*/
    // TC = O(sqrt(n))
    std::vector<int> ls;
    // i<=sqrt(n)---> can be written as i*i<=n
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            ls.push_back(i);
            if ((n / i) != i)
            {
                ls.push_back(n / i);
            }
        }
    }

    // TC = O(no of fact*log(no of fact))
    sort(ls.begin(), ls.end());
    // TC = O(no of fact)
    for (auto it : ls)
        cout << it << " ";
    // total TC = O(sqrt(n)+(no of fac*log(no of fac))+no of fact)
}
void prime(int n)
{
    // TC = O(n)
    //  int cnt=0;
    //  for (int i = 1; i <=n; i++)
    //  {
    //      if(n%i==0)
    //      cnt++;
    //  }
    //  if(cnt==2)
    //  {
    //      cout<<"Prime no";
    //  }
    //  else
    //  cout<<"Not a prime no";

    // TC=O(sqrt(n))
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cnt++;
            if ((n / i) != i)
                cnt++;
        }
    }
    if (cnt == 2)
        cout << "PRIME NO";
    else
        cout << "NOT A PRIME NO";
}
void gcd(int n1, int n2)
{
    int cnt = 0;
    int x = min(n1, n2);
    for (int i = 1; i <= x; i++)
    {
        if (n1 % i == 0 && n2 % i == 0)
            cnt = i;
    }
    cout << cnt;
    // TC = O(min(n1,n2))
}

// LEETCODE CODE WITH STACKOVERFLOW
int reverse(int n)
{
    // n=-123;
    int ld;
    int revno = 0;

    while (n != 0)
    {
        ld = n % 10;
        n = n / 10;
        if (revno > INT_MAX / 10 || (revno == INT_MAX / 10 && ld > 7))
            return 0;
        if (revno < INT_MAX / 10 || (revno == INT_MIN / 10 && ld < -8))
            return 0;
        revno = (revno * 10) + ld;
    }
    return revno;
}

// EUCLIDEAN ALGORITHM****
void gcdEucli(int n1, int n2)
{
    while (n1 > 0 && n2 > 0)
    {
        if (n1 > n2)
            n1 = n1 % n2;
        else
            n2 = n2 % n1;
    }
    if (n1 == 0)
        cout << n2;
    else
        cout << n1;
}

int main()
{
    // int n;
    // cin >> n;
    // lstdigit(n);
    // revNum(n);
    // palindrome(n);
    // armstrong(n);
    // divisors(n);
    // prime(n);
    // cout<< reverse(n);

    // FOR GCD
    // int n1, n2;
    // cin >> n1 >> n2;
    // gcd(n1,n2);

    // EUCLIDEAN ALOGO
    // int n1, n2;
    // cin>>n1>>n2;
    // gcdEucli(n1, n2);
    return 0;
}