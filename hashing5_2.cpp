#include <iostream>

using std ::cin;
using std ::cout;

int main()
{
    std::string s;
    cin >> s;

    // precompute
    int hash[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i] - 'a'] += 1;
    }

    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        // fetch
        cout << hash[c - 'a'] << "\n";
    }
    return 0;
}