




#include <ios>
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std ;

ll getKnapsack(vector<ll> weights, vector<ll> values, vector<vector<ll>> &dp, ll n, ll w, ll start) {
  if(start == n) return 0;

  if(dp[start][w] != -1) return dp[start][w] ;

  if(weights[start] > w) return dp[start][w] = getKnapsack(weights, values, dp, n, w, start + 1) ;

  return dp[start][w] = max(getKnapsack(weights, values, dp, n, w, start + 1), values[start] + getKnapsack(weights, values, dp, n, w - weights[start], start + 1)) ;

}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  ll n, w;
  cin >> n >> w ;
  vector<ll> weights(n);
  vector<ll> value(n) ;

  for(int i = 0; i < n; i++) {
    cin >> weights[i] >> value[i] ;
  }
  vector<vector<ll>> dp(n + 1, vector<ll>(w + 1, -1)) ;
  cout << getKnapsack(weights, value, dp, n, w, 0)  << endl ;
  return 0;
}
