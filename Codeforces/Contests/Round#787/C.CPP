#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        if (str.length() == 1 || str[0] == '0' || str[str.length() - 1] == '1')
        {
            cout << 1 << endl;
            continue;
        }

        int posn0 = str.find('0');
        if (posn0 == string::npos)
        {
        }
        int suspects = 0;
        // anyone who says not remember or was there after a 0 is a suspect
        for (int i = posn0 + 1; i < str.length(); i++)
        {
            if (str[i] == '1' || str[i] == '?')
            {
                suspects++;
            }
        }
    }

    return 0;
}
