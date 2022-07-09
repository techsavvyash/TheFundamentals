/CODE BY AJ :)

#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define fa(i, N) for (auto i : N)
#define ci(x) cin >> x
#define pi(x) cout << x << el
#define int long long
#define ks(x) cout << "Case #" << x << ": "
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define all(x) x.begin(), x.end()
#define Asort(x) sort(all(x))
#define Dsort(x)  \
    sort(all(x)); \
    reverse(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
#define ceill(a, b) ((a) / (b) + (((a) % (b)) != 0))
#define bin(n) bitset<32>(n).to_string()
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define vin(name, N) \
    vi name(N);      \
    fo(i, 0, N) { cin >> name[i]; }
#define print(V)                   \
    fa(i, V) { cout << i << " "; } \
    el;
typedef map<int, int> mi;
typedef unordered_map<int, int> umi;
typedef map<char, int> mc;
typedef unordered_map<int, vector<int>> graph;
typedef unordered_map<int, vector<pii>> wgraph;
typedef priority_queue<int> pq;

void solve()
{
    int i = 0, j, n;
    string s;
    cin >> s;
    int cnte = 0, cnto = 0;
    while (s[i])
    {
        if ((s[i] - '0') % 2 == 0)
            cnte++;
        else
            cnto++;
        i++;
    }

    if (((s[s.size() - 1]) - '0') & 1)
    {
        if (cnto >= 2)
            yes;
        else
            no;
    }
    else
    {
        if (cnte >= 2)
            yes;
        else
            no;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}