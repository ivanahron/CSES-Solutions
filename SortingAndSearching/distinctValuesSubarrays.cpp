#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e20
#define endl '\n'
#define ws ' '

const int MAX_N = 2 * 1e5 + 5;
ll arr[MAX_N];

void solve(int n) {
  ll ans = 0;
  int l = 0, r = 0;

  set<ll> window = {};

  while (r < n) {
    if (window.find(arr[r]) != window.end()) {
      while (window.find(arr[r]) != window.end()) 
        window.erase(window.find(arr[l++]));
    }
    ans += (r - l + 1);
    window.insert(arr[r++]);
  }
  
  cout << ans;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) cin >> arr[i];

  solve(n);
}