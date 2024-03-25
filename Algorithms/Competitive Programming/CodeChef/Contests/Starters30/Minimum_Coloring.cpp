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
        ll n, m, x1, x2, y1, y2;
        cin >> n >> m;
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        ll k = 0;
        ll arr[n][m];
        arr[0][0] = 1;
        for (ll i = 0; i < n; i++)
        {
            k = (i + 1) % 2;
            for (ll j = 0; j < m; j++)
            {

                arr[i][j] = (k++) % 2 + 1;
            }
        }

        if (arr[x2 - 1][y2 - 1] == arr[x1 - 1][y1 - 1])
        {
            if (arr[x1 - 1][y1 - 1] != 1)
            {
                arr[x1 - 1][y1 - 1] = 1;
                if (x1 - 2 >= 0)
                    arr[x1 - 2][y1 - 1] = 3;
                if (x1 < n)
                    arr[x1][y1 - 1] = 3;
                if (y1 < m)
                    arr[x1 - 1][y1] = 3;
                if (y1 - 2 >= 0)
                    arr[x1 - 1][y1 - 2] = 3;
            }
            else
            {
                arr[x2 - 1][y2 - 1] = 2;
                if (x2 - 2 >= 0)
                    arr[x2 - 2][y2 - 1] = 3;
                if (x2 < n)
                    arr[x2][y2 - 1] = 3;
                if (y2 < m)
                    arr[x2 - 1][y2] = 3;
                if (y2 - 2 >= 0)
                    arr[x2 - 1][y2 - 2] = 3;
            }
        }
        else if (arr[x1 - 1][y1 - 1] != 1)
        {
            if (n % 2 != 0 || m % 2 != 0)
            {
                for (ll i = n - 1; i >= 0; i--)
                {
                    for (ll j = m - 1; j >= 0; j--)
                    {
                        cout << arr[i][j] << " ";
                    }
                    cout << endl;
                }
            }
            else
            {
                for (ll i = 0; i < n; i++)
                {
                    for (ll j = 0; j < m; j++)
                    {
                        cout << ((arr[i][j] == 1) ? 2 : 1) << " ";
                    }
                    cout << endl;
                }
            }
            continue;
        }

        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}