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
        vector<ll> a(n);
        vector<ll> even, odd;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] & 1)
                odd.push_back(a[i]);
            else
                even.push_back(a[i]);
        }

        if (odd.size() % 2 == 0)
        {
            for (int i = 0; i < odd.size(); i++)
            {
                cout << odd[i] << " ";
            }

            for (int i = 0; i < even.size(); i++)
            {
                cout << even[i] << " ";
            }

            cout << endl;
        }
        else if (odd.size() == 1 && even.size() == 0)
        {
            cout << odd[0] << endl;
            continue;
        }
        else if (odd.size() > 1 && odd.size() % 2 == 1)
        {
            cout << odd[0] << " " << odd[1] << " ";
            ll i, j;
            for (i = 0, j = 2; i < even.size() && j < odd.size(); i++, j++)
            {
                cout << even[i] << " " << odd[j] << " ";
            }
            for (; i < even.size(); i++)
            {
                cout << even[i] << " ";
            }

            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}