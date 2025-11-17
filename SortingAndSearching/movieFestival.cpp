#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(vector<pair<ll, ll>> &startEnd) {
  int ans = 1;

  ll curr_end = startEnd[0].second;
  for (int i = 1; i < startEnd.size(); i++) {
    if (curr_end <= startEnd[i].first) {
      ans++;
      curr_end = startEnd[i].second;
    }
  }

  cout << ans;
}

int main() {
  ios_base :: sync_with_stdio(false);
  int n;
  cin >> n;

  vector<pair<ll, ll>> movies(n);

  for (int i = 0; i < n; i++) {
    ll s, e;
    cin >> s >> e;
    movies[i] = pair<ll, ll>(s, e);
  }

  sort(movies.begin(), movies.end(), [](const pair<ll, ll> &a, const pair<ll, ll> &b) {
    return a.second < b.second;
  });
  
  solve(movies);
}