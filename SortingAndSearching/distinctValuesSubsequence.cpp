#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e20
#define endl '\n'
#define ws ' '
#define MOD 1000000007

const int MAX_N = 2 * 1e5 + 5;
ll arr[MAX_N];

ll fast_exponent(int base, int exp) {
  if (exp <= 0) return 1 % MOD;
  
  if (exp & 1) return (base * fast_exponent(base, exp - 1)) % MOD;
  else {
    ll res = fast_exponent(base, exp / 2);
    return (res * res) % MOD;
  }
}

void solve(int n) {
  map<ll, int> freq;
  set<ll> rep;

  for (int i = 0; i < n; i++) {
    if (freq.find(arr[i]) != freq.end()) {
      freq[arr[i]]++;
      rep.insert(arr[i]);
    }
    else freq[arr[i]] = 0;
  }

  ll ans = fast_exponent(2, freq.size() - rep.size());

  for (auto [key, val] : freq) 
    if (val) ans = (ans * (2 + val)) % MOD;

  cout << ans - 1;
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