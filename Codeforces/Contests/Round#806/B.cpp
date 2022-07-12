#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;

    map<char, bool> visited;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[str[i]])
            ans++;
        else
        {
            ans += 2;
            visited[str[i]] = true;
        }
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}