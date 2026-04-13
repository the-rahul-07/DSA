#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

// brute force soln TC = O(n2), SC = O(1)
int longsubarr(int arr[], int n, int k)
{
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}

// BETTER SOLN using hashmap TC = O(n)
int longsubarr1(int arr[], int n, long long k)
{
    map<long long, int> prefixSum;
    long long sum;
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        // puts the sum of indexs one by one
        sum += arr[i];
        // when putting sum of indexs it checks weather sum directly came equal to 'k'
        if (sum == k)
            maxLen = i + 1;

        // this is like 7-3 which is 4 then we check in if that weather 4 is in map
        long long rem = sum - k;

        // MEANING OF *****prefixSum.find(rem) != prefixSum.end(); ******
        //  checking if sum-k is present before in map;
        //  by prefixSum.find(rem) -> finding if 4 is in map, find searches for 'key'
        //  prefixSum.end() means that element is not found
        //  means see if map is like 1-->0, 2-->1, 4-->2
        //  so when i do prefix.find(2) -> 2 is present so it returns iterator
        //  but when i do prefix.find(20) -> 20 is not present so it returns
        //  prefixSum.end(); so prefixSum.end()!=prefixSum.end() which is false so
        //  loop does not run

        // when it returns iterator if value present then
        // iterator!=prefixSum.end() which is true so the loop runs measn the value is presnt
        if (prefixSum.find(rem) != prefixSum.end())
        {
            int len = i - prefixSum[rem];
            maxLen = max(len, maxLen);
        }

        // prefixSum[sum] = i; // hashing -> if we do it like this then if zeros are present then program fails

        // if condn bvoz if zeros are present in array
        if (prefixSum.find(sum) == prefixSum.end())
        {
            prefixSum[sum] = i;
        }
    }

    // cannot be done here as we want the present index
    //  for(auto it : prefixSum){
    //      if(sum-k == it.first)
    //          len = max(len, i-it.second);
    //  }
    return maxLen;
}

// OPTIMAL SOLN TC = O()
int longsubarr2(int arr[], int n, long long k)
{
    int sum = 0;
    int j = 0;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > k)
        {
            sum = sum - arr[j];
            if (sum == k)
                len = i - j + 1;
            j++;
        }
    }
    return len;
}

// OPTIMAL SOLN TC = O(2n), SC = O(1)
int longsubarr3(int arr[], int n, int k)
{
    int left = 0;
    int right = 0;
    int maxLen = 0;
    long long sum = arr[0];

    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -= arr[left];
            left++;
        }
        if (sum == k)
            maxLen = max(maxLen, right - left + 1);
        right++;
        if (right < n)
            sum += arr[right];
    }

    return maxLen;
}
int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;

    // cout << longsubarr(arr, n, k);   //BRUTE FORCE SOLN
    // cout << longsubarr1(arr, n, k);  //OPTIMAL SOLN FOR NEGATIVE AND BETTER SOLN FOR + AND 0
    // cout << longsubarr2(arr, n, k);  //OPTIMAL SOLN FOR ONLY POSTIVE AND ZEROS
    cout << longsubarr3(arr, n, k); // OPTIMAL SOLN FOR ONLY POSITIVE AND ZEROS
    return 0;
}