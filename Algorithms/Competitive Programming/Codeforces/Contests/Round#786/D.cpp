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
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (ll i = n - 1; i >= 1; i = i - 2)
        {
            if (arr[i - 1] > arr[i])
            {
                swap(arr[i], arr[i - 1]);
            }
        }
        // for (ll i = 0; i < n; i++)
        // {
        //     cout << arr[i] << " ";
        // }
        // cout << endl;
        bool check = true;
        for (ll i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                check = false;
                break;
            }
        }

        cout << (check ? "YES" : "NO") << endl;
    }
    return 0;
}