#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    string str;
    cin >> str;
    ll p;
    cin >> p;

    vector<int> count(27);
    ll val = 0;

    for (int i = 0; i < str.length(); i++)
    {
        val += (str[i] - 'a' + 1);
        count[str[i] - 'a']++;
    }

    if (val <= p)
    {
        cout << str << endl;
        return;
    }

    int i = 25;
    while (val > p && i >= 0)
    {
        if ((count[i] * (i + 1)) >= (val - p) && (count[i] * (i + 1)) > 0)
        {
            val -= (count[i] * (i + 1));
            count[i] = 0;
        }
        else
        {
            while (count[i] > 0 && val > p)
            {
                val -= (i + 1);
                count[i]--;
            }
        }
        i--;
    }

    string res = "";

    for (int i = 0; i < str.length(); i++)
    {
        if (count[str[i] - 'a'] > 0)
        {
            res += str[i];
            count[str[i] - 'a']--;
        }
    }

    cout << res << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}