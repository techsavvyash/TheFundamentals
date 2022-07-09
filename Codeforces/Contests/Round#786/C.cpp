#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s, t;
        cin >> s;
        cin >> t;
        if (t.length() > 1 && t.find('a') != string::npos)
        {
            cout << -1 << endl;
        }
        else
        {
            ll ans = 1;
            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] == t[0])
                {
                    ans *= 1;
                }
                else
                {
                    ans *= 2;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}