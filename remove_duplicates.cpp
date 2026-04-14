#include <iostream>
#include <bits/stdc++.h>

using std ::cin;
using std ::cout;
using namespace std;

// Brute force approach - TC = O(NlogN+N)
int duplicate1(vector<int> &v)
{
    set<int> st;
    for (int i = 0; i < v.size(); i++)
    {
        st.insert(v[i]);
    }

    int index = 0;
    for (auto it : st)
    {
        v[index] = it;
        index++;
    }
    return index;
}

// Better soln -> TC = O(2n) = O(N), SC =O(x) x-no of uniqe elements
//  which can be n also
int duplicate2(vector<int> &v)
{
    vector<int> temp;

    temp.push_back(v[0]);
    for (int i = 0; i < v.size(); i++)
    {
        if (temp.back() != v[i])
        {
            temp.push_back(v[i]);
        }
    }

    int indx = 0;
    for (auto it : temp)
    {
        v[indx] = it;
        indx++;
    }
    return temp.size();
}

// optimal approach -> TC = O(N) & SC = O(1)
int duplicate3(vector<int> &v)
{
    int i = 0;
    for (int j = 0; j < v.size(); j++)
    {
        if (v[j] != v[i])
        {
            v[i + 1] = v[j];
            i++;
        }
    }
    return i + 1;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < v.size(); i++)
    {
        cin >> v[i];
    }
    // int indx1 = duplicate1(v);  //brute foce soln

    int k = duplicate2(v); // better soln
    for (int i = 0; i < k; i++)
    {
        cout << v[i] << " ";
    }

    // int indx2 = duplicate3(v);     //optimal soln
    // for(int i=0; i<indx2; i++){
    //     cout<<v[i] << " ";
    // }
    return 0;
}