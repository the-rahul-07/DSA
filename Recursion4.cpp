#include <iostream>
#include <utility>

using std ::cin;
using std ::cout;

int cnt = 0;
void print()
{
    if (cnt == 3)
        return;
    cout << cnt << " ";
    cnt++;
    print();
}
void name(int i, int n)
{
    if (i > n)
        return;
    cout << "Neha\n";
    name(i + 1, n);
}
void numli(int i, int n)
{
    if (i > n)
        return;
    cout << i << " ";
    numli(i + 1, n);
}
void revnumli(int n)
{
    if (n < 1)
        return;
    cout << n << " ";
    revnumli(n - 1);
}

// BACKTRACKING
void fun1toN(int i, int n)
{
    if (i < 1)
        return;
    fun1toN(i - 1, n);
    cout << i << " ";
}
void funNto1(int i, int n)
{
    if (i > n)
        return;
    funNto1(i + 1, n);
    cout << i << " ";
}

// PARAMETRIZED
int s = 0;
void sum(int n)
{
    if (n < 0)
    {
        cout << s;
        return;
    }
    s += n;
    sum(n - 1);
}
void sum1(int i, int sum)
{
    if (i < 1)
    {
        cout << sum;
        return;
    }
    sum1(i - 1, sum + i);
}

// FUNCTIONAL --- ***RETURNS VALUE***
int sum2(int n)
{
    if (n == 0)
        return 0;
    return n + sum2(n - 1);
}

// PARAMETRIZED
void fac(int i, int fc)
{
    if (i == 1)
    {
        cout << fc;
        return;
    }
    fac(i - 1, fc * i);
}

// FUNCTIONAL
int fac1(int fc)
{
    if (fc == 1)
    {
        return 1;
    }
    return fc * fac1(fc - 1);
}

// array swap
void f(int i, int arr[], int n)
{
    if (i >= n / 2)
        return;
    std::swap(arr[i], arr[n - i - 1]);
    f(i + 1, arr, n);
}

// STRING PALINDROME
bool palin(int i, std::string &s)
{
    if (i >= s.size() / 2)
        return true;
    if (s[i] != s[s.size() - i - 1])
        return false;
    return palin(i + 1, s);
}

// *****MULTIPLE RECURSION CALL******
// FIBONACCI NUMBERS;
void fibo(int n)
{
}
int main()
{
    // print();

    int n;
    cin >> n;

    // name(1,n);
    // numli(1,n);
    // revnumli(n);
    // fun1toN(n,n);
    // funNto1(1,n);
    // sum(n);
    // sum1(n,0);
    // cout<<sum2;
    // fac(n,1);
    // cout<<fac1(n);

    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    // f(0, arr, n);
    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << " ";

    // std::string s = "12121";
    // cout << palin(0, s);

    // 0 1 1 2 3 5

    fibo(n);
    return 0;
}