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
        ll n;
        cin >> n;
        string str;
        cin >> str;
        // cout << "str: " << str << endl;
        ll count0 = 0, count1 = 0;
        if (n == 1)
        {
            cout << str << endl;
            continue;
        }
        int first1 = -1, countTillFirst1 = 0;
        if (str[0] == '0')
            count0++;
        else
        {
            count1++;
            first1 = 0;
        }
        bool flag = true;

        for (int i = 1; i < n; i++)
        {
            if (str[i] == '0')
            {
                if (str[i - 1] == '1')
                    flag = false;
                count0++;
            }
            else
            {
                if (count1 == 0)
                {
                    first1 = i;
                    countTillFirst1 = count0;
                }
                count1++;
            }
        }

        if (flag || count0 == n)
        {
            cout << str << endl;
        }
        else
        {
            int zero = 0, one = 0;
            int i;
            for (i = first1; i < n && zero < (count0 - countTillFirst1); i++)
            {
                if (str[i] == '0')
                {
                    zero++;
                }
                else
                {
                    one++;
                }
            }

            reverse(str.begin() + first1, str.begin() + i);
            cout << str << endl;
        }
    }
    return 0;
}