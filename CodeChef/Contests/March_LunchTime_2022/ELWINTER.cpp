#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<ll, list<ll>> graph;
    map<ll, ll> freezeTimings;
    map<ll, bool> freezeStatus;
    // set<ll> frozen;
    set<ll> unfrozen;
    ll n, m, q;
    cin >> n >> m >> q;

    for (ll i = 0; i < m; i++)
    {
        ll src, dest;
        cin >> src >> dest;
        graph[src].push_back(dest);
        graph[dest].push_back(src);
        freezeTimings[src] = LONG_LONG_MAX;
        freezeTimings[dest] = LONG_LONG_MAX;
        freezeStatus[src] = false;
        freezeStatus[dest] = false;
        unfrozen.insert(src);
        unfrozen.insert(dest);
    }
    ll currentTime = 0;
    for (ll i = 0; i < q; i++)
    {
        int type;
        ll node;
        cin >> type;
        cin >> node;
        switch (type)
        {
        case 1:
            freezeStatus[node] = true;
            freezeTimings[node] = min(freezeTimings[node], currentTime);
            // frozen.insert(node);
            unfrozen.erase(node);
            for (auto nbr : graph[node])
            {
                freezeTimings[nbr] = min(freezeTimings[nbr], freezeTimings[node] + 1);
            }
            break;
        case 2:
            currentTime += node;
            for (set<ll>::iterator itr = unfrozen.begin(); itr != unfrozen.end(); itr++)
            {
                if (freezeTimings[*itr] <= currentTime)
                {
                    freezeStatus[*itr] = true;
                    for (auto nbr : graph[*itr])
                    {
                        freezeTimings[nbr] = (freezeTimings[nbr] < freezeTimings[*itr] + 1 ? freezeTimings[nbr] : freezeTimings[*itr] + 1);
                        if (freezeTimings[nbr] <= currentTime)
                        {
                            freezeStatus[nbr] = true;
                            unfrozen.erase(nbr);
                        }
                    }
                }
                unfrozen.erase(itr);
            }
            break;
        case 3:

            if (freezeStatus[node] || freezeTimings[node] <= currentTime)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
            break;
        }
    }

    return 0;
}