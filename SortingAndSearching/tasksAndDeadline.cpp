#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define INF 1e20
#define endl '\n'
#define ws ' '
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

const int MAX_N = 2 * 1e5 + 5;
vector<pair<int, int>> arr;

void solve(int n) {
  sort(arr.begin(), arr.end(), [](const pair<int, int> &a, pair<int, int> &b) {
    return a.first < b.first;
  });

  ll time = 0;
  ll ans = 0;
  for (auto [a, b] : arr) {
    time += a;
    ans += (b - time);
  }
  cout << ans;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    arr.push_back(pair<int, int>(a, b));
  }
  solve(n);
}