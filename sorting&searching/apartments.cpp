#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(int &acc, int n, int m, vector<ll> &apm, vector<ll> &p, ll e) {
  int i = 0, j = 0;

  while (i < n && j < m) {
    ll diff = p[i] - apm[j];
    if (abs(diff) <= e) {
      acc++;
      i++; j++;
    } else if (diff < 0) {
      j++;
    } else {
      i++;
    }
  }
}

int main() {
  ios_base :: sync_with_stdio(false);
  int n, m;
  ll k;
  cin >> n >> m >> k;

  vector<ll> applicants(n);
  vector<ll> apartments(m);

  for (int i = 0; i < n; i++) cin >> applicants[i];
  for (int i = 0; i < m; i++) cin >> apartments[i];

  sort(applicants.begin(), applicants.end(), greater<ll>());
  sort(apartments.begin(), apartments.end(), greater<ll>());

  int acc = 0;

  solve(acc, n, m, apartments, applicants, k);

  cout << acc;
}