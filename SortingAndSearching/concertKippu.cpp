#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(multiset<ll> &tickets, ll target) {
  auto nextLe = tickets.upper_bound(target);
  if (nextLe == tickets.begin()) {
    return -1;
  } else {
    nextLe--;
    tickets.erase(nextLe);
    return *nextLe;
  }
}

int main() {
  ios_base :: sync_with_stdio(false);
  int n, m;
  cin >> n >> m;

  multiset<ll> tickets;
  vector<ll> budget(m);

  for (int i = 0; i < n; i++) {
    ll tix;
    cin >> tix;
    tickets.insert(tix);
  }

  for (int i = 0; i < m; i++) 
    cin >> budget[i];
  
  for (int i = 0; i < m; i++) {
    cout << solve(tickets, budget[i]) << '\n';
  }

}