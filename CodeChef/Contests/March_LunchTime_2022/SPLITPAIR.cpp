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
        ll even = 0, odd = 0;
        bool flag = (n % 2) ? false : true;
        int last = n % 10;
        bool zeroFlag = false;
        while (n != 0)
        {
            if ((n % 10) % 2 == 0)
            {
                even++;
            }
            else
            {
                odd++;
            }
            n = n / 10;
        }

        if ((!flag && odd > 1) || (flag && even > 1))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}