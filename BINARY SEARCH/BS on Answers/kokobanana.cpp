#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

// WRONG!!
// int minEatingSpeed(vector<int> &piles, int h)
// {
//     int n = piles.size();
//     int low = 1;
//     int high = *max_element(piles.begin(), piles.end());

//     int ans;

//     while (low <= high){
//         int k = 0;
//         int temph = h;
//         int mid = (low + high) / 2;

//         for (int j = 0; j < n; j++){
//             int val = (mid - piles[j]);
//             if (val >= 0){
//                 k = 1;
//                 temph--;
//             }else{
//                 temph--;
//                 if (temph > 0){
//                     while (temph > 0){
//                         val = val + mid;
//                         if (val >= 0)
//                         {
//                             k = 1;
//                             temph--;
//                             break;
//                         }
//                         else
//                         {
//                             k = 0;
//                         }
//                         temph--;
//                     }
//                 }else{
//                     k = 0;
//                 }
//             }
//         }

//         if (k == 0)
//         {
//             low = mid + 1;
//         }
//         else
//         {
//             high = mid - 1;
//         }

//         ans = mid;
//     }
//     return ans;
// }

// by + -
int kokobanana2(vector<int> &piles, int h)
{
    int n = piles.size();
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());
    int ans;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int totalhrs = 0;

        for (int i = 0; i < n; i++)
        {
            int val = piles[i];

            while (val > 0)
            {
                val -= mid;
                totalhrs++;
            }
            if (totalhrs > h)
                break;
        }

        if (totalhrs < h)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
            ans = mid;
        }
    }
    return ans;
}

int kokobanana(vector<int> &piles, int hr)
{
    int n = piles.size();
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());
    int ans;
    while (low <= high)
    {
        int totalhrs = 0;
        int mid = (low + high) / 2;
        for (int i = 0; i < n; i++)
        {
            // totalhrs += (piles[i] / mid);
            // if ((piles[i] % mid) != 0)
            // {
            //     totalhrs++;
            // }
            //above code is equivalent to
            //or this can be done as ceil
            totalhrs +=ceil((double)piles[i]/(double)mid);
            if (totalhrs > hr)
            {
                break;
            }
        }

        if (totalhrs > hr)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
            ans = mid;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> piles(n);
    for (int i = 0; i < n; i++)
    {
        cin >> piles[i];
    }

    int hr;
    cin >> hr;

    cout << kokobanana(piles, hr);
    // cout << kokobanana2(piles, hr);
    return 0;
}