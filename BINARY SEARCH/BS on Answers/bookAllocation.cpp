#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

int allocate(vector<int> &books, int pages)
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
    for (int i = 0; i < n; i++)
    {
        high += books[i];
    }

    for (int pages = 0; pages < high; pages++)
    {
        int cntStudents = allocate(books, pages);

        if (cntStudents == m)
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
    for (int i = 0; i < n; i++)
    {
        high += books[i];
    }

    while (low <= high)
    {
        long long mid = (low + high) / 2;

        int cntstudents = allocate(books, mid);

        if (cntstudents > m)
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

    // cout << bookAllocation1(books, m);
    cout << bookAllocation2(books, m);
    return 0;
}