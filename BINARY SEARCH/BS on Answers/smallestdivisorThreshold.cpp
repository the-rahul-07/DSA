#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

int smallestDivisor(vector<int> &nums, int threshold)
{
    int n = nums.size();
    int low = 1;
    long long high = 0;
    for (int i = 0; i < n; i++)
    {
        high += nums[i];
    }

    while (low <= high)
    {
        int sum = 0;
        float mid = (low + high) / 2;

        for (int i = 0; i < n; i++)
        {
            sum += ceil(nums[i] / mid);
        }

        if (sum <= threshold)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{

    return 0;
}