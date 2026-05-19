#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

int cntstudents(vector<int> &books, int pages)
{

    int n = books.size();
    int students = 1;
    int pagesToStudent = 0;

    for (int i = 0; i < n; i++)
    {
        if (pagesToStudent + books[i] <= pages)
        {
            pagesToStudent += books[i];
        }
        else
        {
            students++;
            pagesToStudent = books[i];
        }
    }
    return students;
}

// brute force
int bookAllocation1(vector<int> &books, int m)
{
    int n = books.size();

    if (m > n)
        return -1;
    long long low = *max_element(books.begin(), books.end());
    long long high = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     high += books[i];
    // }
    high = accumulate(books.begin(), books.end(), 0);
    for (int pages = 0; pages < high; pages++)
    {
        int students = cntstudents(books, pages);

        if (students == m)
        {
            return pages;
        }
    }
}

// optimal bs
int bookAllocation2(vector<int> &books, int m)
{
    int n = books.size();

    if (m > n)
        return -1;
    long long low = *max_element(books.begin(), books.end());
    long long high = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     high += books[i];
    // }
    high = accumulate(books.begin(), books.end(), 0);
    // accumulate use to sum
    while (low <= high)
    {
        long long mid = (low + high) / 2;

        int students = cntstudents(books, mid);

        if (students > m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    int n;
    cin >> n;

    vector<int> books(n);
    for (int i = 0; i < n; i++)
    {
        cin >> books[i];
    }

    int m;
    cin >> m;

    // cout << bookAllocation1(books, m);       //brute linear search
    cout << bookAllocation2(books, m); // optimal BS
    return 0;
}