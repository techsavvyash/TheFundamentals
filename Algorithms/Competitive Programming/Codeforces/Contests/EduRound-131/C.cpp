
#include <bits/stdc++.h>
#include <iostream>
#define ll long long
using namespace std;

void solve() {

  int n, m;
  cin >> n >> m;
  vector<int> workers(n + 1, 0);
  vector<int> profs(m);
  int currMin = INT_MAX;
  for (int i = 0; i < m; i++) {
    cin >> profs[i];
    workers[profs[i]]++;
    currMin = min(currMin, workers[profs[i]]);
  }

  vector<pair<int, int>> newArr;
  for (int i = 1; i <= n; i++) {
    newArr.push_back({workers[i], i});
  }

  sort(newArr.begin(), newArr.end(),
       [](pair<int, int> a, pair<int, int> b) { return a.first < b.first; });

  int ans = newArr[0].first ;
  for(int i = 1; i < n; i++) {
    int tasks = newArr[i].first;
    int remTasks = tasks - ans ;
    if(remTasks < 0) continue ;
    ans += 2*(remTasks/(i + 2)) ;
    if(remTasks%(i + 2) ==1) ans += 1 ;
    else if(remTasks%(i + 2) > 1) ans += 2 ;
  }

  cout << ans << endl ;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
