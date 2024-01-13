#include <iostream>
using namespace std;
#define ll long long

int main() {
  ll n, *arr, numWays = 0;
  cin >> n;
  arr = new ll[n];
  cin >> arr[0];
  for (int i = 1; i < n; i++) {
    cin >> arr[i];
    if (arr[i] < arr[i - 1]) {
      numWays += (arr[i - 1] - arr[i]);
      arr[i] = arr[i - 1];
    }
  }

  return 0;
}
