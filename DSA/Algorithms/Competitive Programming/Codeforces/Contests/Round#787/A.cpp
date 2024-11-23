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
        ll a, b, c, x, y;
        cin >> a >> b >> c >> x >> y;
        ll cForDogs = max(0LL, x - a);
        ll cForCats = max(0LL, y - b);
        // cout << "cForDogs: " << cForDogs << endl;
        // cout << "cForCats: " << cForCats << endl;
        if (cForCats + cForDogs <= c)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}