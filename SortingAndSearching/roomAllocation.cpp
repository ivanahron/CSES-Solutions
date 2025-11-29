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
vector<pair<pair<int, int>, int>> arr;

struct Compare {
  bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
    return a.second < b.second;
  }
};

void solve(int n) {
  sort(arr.begin(), arr.end(), [](const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b) {
    return a.first.first < b.first.first;
  });

  int rm = 0;
  multiset<pair<int, int>, Compare> cm;
  multimap<pair<int, int>, int> assignment;
  vector<int> ans(n);

  for (int i = 0; i < n; i++) {
    auto en = arr[i];
    auto curr = en.first;
    int rmAssign = rm;
    if (cm.size() <= 0) {
      assignment.insert({curr, rm});
      rm++;
    } else {
      auto lowest = cm.begin();
      if (lowest->second < curr.first) {
        auto as = assignment.find(*lowest);
        rmAssign = as->second;
        assignment.insert({curr, as->second});
        assignment.erase(as);
        cm.erase(lowest);
      } else {
        assignment.insert({curr, rm});
        rm++;
      }
    }
    cm.insert(curr);
    ans[en.second] = rmAssign + 1;
  }

  cout << rm << endl;
  for (auto rmNum : ans) cout << rmNum << ws;
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
    arr.push_back(pair<pair<int, int>, int>(pair<int, int>(a, b), i));
  }
  solve(n);
}