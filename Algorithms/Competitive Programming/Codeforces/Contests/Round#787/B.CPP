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
        bool isGood = true;
        cin >> arr[0];
        for (ll i = 1; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] < arr[i - 1])
            {
                isGood = false;
            }
        }

        if (isGood || n == 0 || n == 1)
        {
            cout << 0 << endl;
            continue;
        }

        if (n > 2 && arr[n - 1] == 1)
        {
            cout << -1 << endl;
            continue;
        }

        ll steps = 0;
        bool leave = false;
        for (ll i = 0; i < n; i++)
        {
            if (leave)
            {
                break;
            }
            if (isGood)
            {
                // cout << "array " << endl;
                // for (ll k = 0; k < n; k++)
                // {
                //     cout << arr[k] << " ";
                // }
                // cout << endl
                //      << "steps: ";
                cout << steps << endl;
                break;
            }
            isGood = true;
            for (ll j = 0; j < n - i - 1; j++)
            {
                while (arr[j] >= arr[n - i - 1] && arr[j] > 0)
                {
                    arr[j] /= 2;
                    steps++;
                }
                if (arr[j] == 0 && j > 0)
                {
                    cout << -1 << endl;
                    leave = true;
                    break;
                }
                if (j > 0 && arr[j] <= arr[j - 1])
                {
                    isGood = false;
                }
            }
        }
    }

    return 0;
}
