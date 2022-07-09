#include <iostream>
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define int long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define repi(i, x, n) for (int i = x; i < n; i++)
#define br cout << endl
#define vi vector<int>
using namespace std;

void SOLVE()
{
    int n, m, x1, x2, y1, y2;
    cin >> n >> m;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    x1--;
    x2--;
    y1--;
    y2--;
    // cout<<((x1 + y1) % 2)<<" "<< ((x2 + y2) % 2)<<endl;
    if (((x1 + y1) % 2) != ((x2 + y2) % 2))
    {
        // cout<<"f"<<endl;
        rep(i, n)
        {
            rep(j, m)
            {
                int temp = (i + j) % 2;
                if (temp == (x1 + y1) % 2)
                {
                    cout << 1 << " ";
                }
                else
                {
                    cout << 2 << " ";
                }
            }
            cout << endl;
        }
        return;
    }

    int res[n][m];
    rep(i, n)
    {
        rep(j, m)
        {
            int temp = (i + j) % 2;
            if (temp == (x1 + y1) % 2)
            {
                res[i][j] = 1;
            }
            else
            {
                res[i][j] = 2;
            }
        }
    }
    res[x1][y1] = 1;
    res[x2][y2] = 2;

    if (x2 > 0)
    {
        res[x2 - 1][y2] = 3;
    }
    if (x2 < n - 1)
    {
        res[x2 + 1][y2] = 3;
    }
    if (y2 > 0)
    {
        res[x2][y2 - 1] = 3;
    }
    if (y2 < m - 1)
    {
        res[x2][y2 + 1] = 3;
    }
    rep(i, n)
    {
        rep(j, m)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {
        SOLVE();
    }
}