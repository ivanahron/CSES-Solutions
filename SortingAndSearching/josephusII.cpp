#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define INF 1e20
#define endl '\n'
#define ws ' '

const int MAX_N = 2 * 1e5 + 5;
bool arr[MAX_N];

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

void solve(int n, ll k) {
  ordered_set oSet;
  for (int i = 1; i <= n; i++) {
    oSet.insert(i);
  }

  int curr = 0;
  while (oSet.size() > 0) {
    curr = (curr + k) % oSet.size();
    auto toDelete = oSet.find_by_order(curr);
    cout << *toDelete << ws;
    oSet.erase(toDelete);
  }

}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n; ll k;
  cin >> n >> k;

  solve(n, k);
}