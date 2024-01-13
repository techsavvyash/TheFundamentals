#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<pair<int, string>> moves;
    for (int i = 0; i < n; i++)
    {
        int b;
        string str;
        cin >> b;
        cin >> str;

        moves.push_back({b, str});
    }

    for (int i = 0; i < n; i++)
    {
        int b = moves[i].first;
        string str = moves[i].second;
        for (int j = 0; j < b; j++)
        {
            if (str[j] == 'U')
            {
                arr[i]--;
                if (arr[i] < 0)
                    (arr[i] = 10 + arr[i]);
            }

            if (str[j] == 'D')
            {
                arr[i]++;
                if (arr[i] > 9)
                    arr[i] = (arr[i] - 1) % 9;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
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