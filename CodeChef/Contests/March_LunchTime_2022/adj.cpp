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
        vector<ll> a(n);
        vector<ll> odd;
        vector<ll> even;
        for (ll i = 0; i < n; i++)
        {

            cin >> a[i];
            if (a[i] & 1)
            {
                odd.push_back(a[i]);
            }
            else
            {
                even.push_back(a[i]);
            }
        }
        if (odd.size() == n && (n % 2 != 0))
        {
            cout << -1 << endl;
        }
        else if (odd.size() == 1 && even.size() > 0)
        {
            cout << -1 << endl;
        }
        else if (odd.size() == 1 && even.size() == 0)
        {
            cout << odd[0] << endl;
        }
        else if (odd.size() >= 2)
        {
            if (odd.size() % 2 != 0)
            {
                cout << odd[0] << " ";
                for (ll i = 0; i < even.size(); i++)
                {
                    cout << even[i] << " ";
                }
                for (ll i = 1; i < odd.size(); i++)
                {
                    cout << odd[i] << " ";
                }
                cout << endl;
            }
            else
            {
                for (ll i = 0; i < even.size(); i++)
                {
                    cout << even[i] << " ";
                }
                for (ll i = 0; i < odd.size(); i++)
                {
                    cout << odd[i] << " ";
                }
                cout << endl;
            }
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}