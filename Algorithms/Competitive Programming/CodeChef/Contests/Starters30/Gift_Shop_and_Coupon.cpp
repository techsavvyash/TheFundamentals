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
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        ll i = 0, count = 0;
        while (k > 0 && i < n)
        {
            if (k >= a[i])
            {
                count++;
                k -= a[i];
            }
            else
            {
                break;
            }
            i++;
        }
        if (k >= ceil((a[i] * 1.0) / 2))
        {
            count++;
        }
        cout << count << endl;
    }
    return 0;
}