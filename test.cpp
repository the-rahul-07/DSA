#include <iostream>
#include <math.h>

using std ::cin;
using std ::cout;

int power(int x, int y)
{
    int pw = 1;
    for (int i = 0; i < y; i++)
    {
        pw *= x;
    }
    return pw;
}

void revn(int n)
{
    int temp = n;
    int rev = 0;
    int cnt = 0;
    int rem = 0;
    while (n > 0)
    {
        n = n / 10;
        cnt++;
    }
    cnt = cnt - 1;
    while (temp > 0)
    {
        rem = temp % 10;
        temp = temp / 10;
        rev = rev + (rem * pow(10,cnt));
        cnt--;
    }
    cout << rev;
}
int main()
{
    int n;
    cin >> n;
    revn(n);
    // power(2, 3);
    return 0;
}