#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    string str;
    cin >> str;
    int count = 0;
    int ans = 0;
    map<char, bool> visited;
    for (int i = 0; i < str.length(); i++)
    {
        if (!visited[str[i]] && count == 3)
        {
            count = 0;
            ans++;
            for (auto c : visited)
            {
                visited[c.first] = false;
            }
        }
        if (!visited[str[i]])
        {
            count++;
            visited[str[i]] = true;
        }

        // if (count > 3)
        // {
        //     count = 0;
        //     ans++;
        //     for (auto c : visited)
        //     {
        //         visited[c.first] = false;
        //     }
        // }
    }
    // cout << "count: " << count << endl;
    // cout << "ans: " << ans << endl;
    cout << (count ? ans + 1 : ans) << endl;
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