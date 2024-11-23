#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    cin.ignore();
    int n, k;
    cin >> n >> k;

    map<int, vector<int>> idxs;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        idxs[arr[i]].push_back(i);
    }

    // logic to get the paths

    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        if (idxs[a].size() == 0 || idxs[b].size() == 0)
        {
            cout << "NO" << endl;
            continue;
        }
        if (idxs[a][0] <= idxs[b][idxs[b].size() - 1])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
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