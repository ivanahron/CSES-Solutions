#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e20

const int MAX_N = 2 * 1e5 + 5;
ll arr[MAX_N];

void solve(int n, ll x) {
  map<ll, ll> dist = {};
  dist[x] = 0;
  dist[0] = x;

  multiset<ll> dists = {x};

  for (int i = 0; i < n; i++) {
    ll curr = arr[i];
    if (dist.find(curr) != dist.end()) continue;

    auto up = dist.upper_bound(curr);
    auto low = dist.lower_bound(curr);
    low--;

    ll curr_dist = up->first - curr;
    ll low_dist = curr - low->first;

    auto prev = dists.find(low->second);
    if (prev != dists.end()) dists.erase(prev);

    dist[low->first] = low_dist;
    dist[curr] = curr_dist;

    dists.insert(curr_dist);
    dists.insert(low_dist);

    auto ans = dists.end();
    ans--;

    cout << *ans << ' ';
  }
}

int main() {
  ios_base :: sync_with_stdio(false);
  ll x; int n;
  cin >> x >> n;

  for (int i = 0; i < n; i++) cin >> arr[i];

  solve(n, x);
}