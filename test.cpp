#include <iostream>

using std ::cin;
using std ::cout;

void prime(int n)
{
    int i = 2;
    while (i <= n)
    {
        int is_prime = 1;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                is_prime = 0;
                break;
            }
        }
        if (is_prime)
        {
            cout << i << " ";
        }
        i++;
    }
}
int main()
{
    int n;
    cin >> n;

    prime(n);
    return 0;
}