#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        string s = "", s1 = "";
        cin >> s;

        int count1 = 0, count0 = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                count1 += 1;
            }
            else
            {
                count0 += 1;
            }
        }

        for (int x = 0; x < count1; x++)
        {
            s1 += "1";
        }

        for (int x = 0; x < count0; x++)
        {
            s1 += "0";
        }

        reverse(s1.begin(), s1.end());

        cout << s1 << endl;
    }

    return 0;
}
