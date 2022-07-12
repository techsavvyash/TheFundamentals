#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    vector<ll> ineqArr;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] < i)
            ineqArr.push_back(i);
    }

    // ineqArr is a sorted array of indexes now we can use
    // binary search to find all the indexes smaller and then
    // count pairs
    // complexity will be klogK where K is the length of ineqArr
    // and in worst case nlogn

    find()
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