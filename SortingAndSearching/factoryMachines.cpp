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
vector<ll> arr;

ll productsMade(ll time, int n) {
  ll ans = 0;
  for (int i = 0; i < n; i++) ans += (time / arr[i]);
  return ans;
}

ll bSearch(int n, ll t) {
  ll left = 1, right = (ll)*min_element(begin(arr), end(arr)) * t;
  ll optimal = right;

  while (left <= right) {
    ll mid = (left + right) / 2;
    ll res = productsMade(mid, n);
    if (res == t) {
      if (mid == optimal) {
        return optimal;
      } else {
        optimal = mid;
      }
      right = mid;
    }
    else if (res < t) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return left;
}

void solve(int n, ll t) {
  cout << bSearch(n, t);
} 

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n, t;
  cin >> n >> t;

  for (int i = 0; i < n; i++) {
    ll num;
    cin >> num;
    arr.push_back(num);
  };

  solve(n, t);
}