#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(int &acc, int n, ll max_weight, vector<ll> &decr) {
  int i = 0;
  int rem = n;

  while (i < rem) {
    if ((decr[i] + decr[rem - 1]) <= max_weight) {
      rem--;
    } 
    acc++;
    i++;
  }
}

int main() {
  ios_base :: sync_with_stdio(false);
  int n;
  ll x;
  cin >> n >> x;
  
  vector<ll> weights(n);
  for (int i = 0; i < n; i++) cin >> weights[i];

  sort(weights.begin(), weights.end(), greater<ll>());

  int ans = 0;
  solve(ans, n, x, weights);

  cout << ans;
}