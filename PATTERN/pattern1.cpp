#include <iostream>

using std ::cin;
using std ::cout;

void pattern1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << "\n";
    }
}
void pattern2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << "\n";
    }
}
void pattern3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}
void pattern4(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}
void pattern5(int n)
{
    /*
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j <i; j++)
        {
            cout << "* ";
        }
        cout << "\n";
    }
    */
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= (n - i + 1); j++)
        {
            cout << "* ";
        }
        cout << "\n";
    }
}
void pattern6(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= (n - i + 1); j++)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}
void pattern7(int n)
{
    for (int i = 0; i < n; i++)
    {
        // spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "  ";
        }
        // star
        for (int k = 0; k < 2 * i + 1; k++)
        {
            cout << "* ";
        }
        // spaces
        for (int l = 0; l < n - i - 1; l++)
        {
            cout << " ";
        }
        cout << "\n";
    }
}
void pattern8(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "  ";
        }
        for (int j = 0; j < (2 * n - (2 * i + 1)); j++)
        {
            cout << "* ";
        }
        for (int l = 0; l < i; l++)
        {
            cout << " ";
        }
        cout << "\n";
    }
}
// PATTERN 9 IS COMBINATION OF PATTERN 7 AND 8
void pattern10(int n)
{
    // METHOD 1
    //  for (int i = 0; i < n; i++)
    //  {
    //      for (int j = 0; j <= i; j++)
    //      {
    //          cout<<"* ";
    //      }
    //      cout<<"\n";
    //  }
    //  for (int i = 0; i <n; i++)
    //  {
    //      for (int k = 1; k < n-i; k++)
    //      {
    //          cout<<"* ";
    //      }
    //      cout<<"\n";
    //  }
    // METHOD 2
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;
        if (i > n)
            stars = 2 * n - i;
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}
void pattern11(int n)
{
    for (int i = 0; i < n; i++)
    {
        int start = 1;
        if (i % 2 == 0)
            start = 1;
        else
            start = 0;
        for (int j = 0; j <= i; j++)
        {
            cout << start;
            start = 1 - start;
        }
        cout << "\n";
    }
}
void pattern12(int n)
{
    // METHOD 1
    //  for (int i = 0; i < n; i++)
    //  {
    //      int start1=1;
    //      //numbers
    //      for (int j = 0; j <=i; j++)
    //      {
    //          cout<<start1;
    //          start1=1+start1;
    //      }
    //      //spaces --- 2*(n-i-1)
    //      for (int j = 0; j < 2*(n-i-1); j++)
    //      {
    //          cout<<" ";
    //      }
    //      //numbers
    //      int start2=start1-1;
    //      for (int m = 0; m <=i; m++)
    //      {
    //          cout<<start2;
    //          start2--;
    //      }
    //      cout<<"\n";
    //  }
    //  METHOD 2
    // for (int i = 1; i <= n; i++)
    // {
    //     // numbers
    //     for (int j = 1; j <= i; j++)
    //     {
    //         cout << j;
    //     }
    //     // spaces  -- 2*(n-i)
    //     for (int k = 0; k < 2 * n - 2 * i; k++)
    //     {
    //         cout << " ";
    //     }
    //     // numbers;
    //     for (int m = i; m >= 1; m--)
    //     {
    //         cout << m;
    //     }
    //     cout << "\n";
    // }
    // METHOD 3
    int space = 2 * (n - 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        for (int m = 0; m < space; m++)
        {
            cout << " ";
        }
        for (int k = i; k >= 1; k--)
        {
            cout << k;
        }
        cout << "\n";
        space -= 2;
    }
}
void heart(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 5; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < 2 * i + 1; k++)
        {
            cout << "*";
        }
        for (int l = 0; l < n - 2 * i - 4; l++)
        {
            cout << " ";
        }
        for (int k = 0; k < 2 * i + 1; k++)
        {
            cout << "*";
        }
        for (int j = 0; j < n - i - 5; j++)
        {
            cout << " ";
        }
        // bottom
        // for (int o = 0; o < i; o++)
        // {
        //     cout<<" ";
        // }
        // for (int c = 0; c < (2*n-(2*i+1)); c++)
        // {
        //     cout<<"*";
        // }
        // for (int e = 0; e < i; e++)
        // {
        //     cout<<" ";
        // }
        cout << "\n";
    }
}
void pattern13(int n)
{
    int x = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << x << " ";
            x++;
        }
        cout << "\n";
    }
}
void pattern14(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << char(j + 64);
        }
        cout << "\n";
    }
    // ASCII VALUE
    //  A=65
    //  a=97
}
void pattern15(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << char(j + 65);
        }
        cout << "\n";
    }
}
void pattern16(int n)
{
    char c = 65;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << c;
        }
        c++;
        cout << "\n";
    }
}
void pattern17(int n)
{
    // METHOD 1
    //  for (int i = 0; i < n; i++)
    //  {
    //      // spaces
    //      for (int l = 0; l < n-i-1; l++)
    //      {
    //          cout << " ";
    //      }
    //      // alphabets
    //      for (int j = 1; j <= 2*i+1; j++)
    //      {
    //          cout << char(j+64);
    //          if(j==i+1) break;
    //      }
    //      for (int o = i; o >= 1 ; o--)
    //      {
    //          cout<< char(o+64);
    //      }
    //      // space
    //      for (int m = 0; m < n-i-1; m++)
    //      {
    //          cout << " ";
    //      }
    //      cout << "\n";
    //  }
    // METHOD 2
    for (int i = 0; i < n; i++)
    {
        // spaces
        for (int l = 0; l < n - i - 1; l++)
        {
            cout << " ";
        }
        // ALPHABETS
        char c = 'A';
        int breakpoint = (2 * i + 1) / 2;
        for (int m = 1; m <= 2 * i + 1; m++)
        {
            cout << c;
            if (m <= breakpoint)
                c++;
            else
                c--;
        }
        for (int l = 0; l < n - i - 1; l++)
        {
            cout << " ";
        }
        cout << "\n";
    }
}
void pattern18(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char k = 64 + n - i; k <= 64 + n; k++)
        {
            cout << k << " ";
        }
        // OR
        /*
        for(char m = 'E'-i; m<='E'; m++)
        {
            cout << m << " ";
        }
        */
        cout << "\n";
    }
}
void pattern19(int n)
{
    // TOP
    for (int i = 0; i < n; i++)
    {
        // stars
        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }
        // spaces
        for (int m = 0; m < 2 * i; m++)
        {
            cout << " ";
        }
        // stars
        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
    // BOTTOM
    for (int i = 0; i < n; i++)
    {
        // stars
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        // spaces
        for (int m = 0; m < 2 * n - (2 * i) - 2; m++)
        {
            cout << " ";
        }
        // stars
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}
void pattern20(int n)
{
    // METHOD 1
    //  for (int i = 1; i <=n; i++)
    //  {
    //     int breakpoint = n / 2;

    //     int STAR = i;
    //     if (i > breakpoint)
    //     STAR = n-i;

    //     // stars
    //     for (int j = 0; j < STAR; j++)
    //     {
    //         cout << "*";
    //     }

    //     // spaces
    //     int spaces = n-(2*i);
    //     if (i > breakpoint)
    //         spaces = (2*i)-n;
    //     for (int m = 0; m < spaces; m++)
    //     {
    //         cout << " ";
    //     }

    //     //stars
    //     for (int l = 0; l < STAR; l++)
    //     {
    //         cout << "*";
    //     }
    //     cout << "\n";
    // }
    // METHOD 2
    int spaces = 2 * n - 2;
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;
        if (i > n)
            stars = 2 * n - i;

        // stars
        for (int m = 0; m < stars; m++)
        {
            cout << "*";
        }

        // spaces
        for (int n = 0; n < spaces; n++)
        {
            cout << " ";
        }

        // STARS
        for (int m = 0; m < stars; m++)
        {
            cout << "*";
        }
        cout << "\n";
        if (i < n)
            spaces -= 2;
        else
            spaces += 2;
    }
}
void pattern21(int n)
{
    // METHOD 1
    //  for (int i = 0; i < n; i++)
    //  {
    //      if(i==0 || i==n-1){
    //          for (int j = 0; j < n; j++)
    //          {
    //              cout<<"*";
    //          }
    //      }
    //      else{
    //          for (int k = 0; k < n-(n-1); k++)
    //          {
    //              cout<<"*";
    //          }
    //          for (int m = 0; m < n-2; m++)
    //          {
    //              cout<<" ";
    //          }
    //          for (int k = 0; k < n-(n-1); k++)
    //          {
    //              cout<<"*";
    //          }
    //      }
    //      cout<<"\n";
    //  }

    // METHOD 2
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }
}
void pattern22(int n)
{
    for (int i = 0; i < n; i++)
    {
        int x = (n + 1) / 2;
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
            {
                cout << x;
            }
            else if (i == 1 || i == n - 2 || j == 1 || j == n - 2)
            {
                cout << x - 1;
            }
            else if (i == 2 || i == n - 3 || j == 2 || j == n - 3)
            {
                cout << x - 2;
            }
            else
            {
                cout << x - 3;
            }
        }
        cout << "\n";
    }
}
// pattern22 incomplete*********
int main()
{
    // TEST CASING
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        pattern22(n);
        cout << "\n";
    }
    return 0;
}