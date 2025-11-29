#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>

#define ll long long
#define INF 1e20
#define endl '\n'
#define ws ' '
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

const int MAX_N = 2 * 1e5 + 5;
vector<pair<pair<int, int>, int>> arr;

void solve(int n) {
  vector<pair<pair<int, int>, int>> sorted_pairs(n);
  copy(arr.begin(), arr.end(), sorted_pairs.begin());

  sort(sorted_pairs.begin(), sorted_pairs.end(),
    [](const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b) {
      return (a.first.first == b.first.first) ? a.first.second > b.first.second : a.first.first < b.first.first;
    });

  vector<int> contained(n);
  vector<int> contains(n);

  ordered_set oSet;
  for (int i = 0; i < n; i++) {
    auto curr = sorted_pairs[i];
    pair<int, int> currKey(curr.first.second, -i);
    oSet.insert(currKey);
    contained[curr.second] = oSet.size() - oSet.order_of_key(currKey) - 1;
  }

  oSet.clear();
  
  for (int i = n - 1; i > - 1; i--) {
    auto curr = sorted_pairs[i];
    pair<int, int> currKey(curr.first.second, -i);
    oSet.insert(currKey);
    contains[curr.second] = oSet.order_of_key(currKey);
  }

  for (int i = 0; i < n; i++) cout << contains[i] << ws;
  cout << endl;
  for (int i = 0; i < n; i++) cout << contained[i] << ws;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    arr.push_back(pair<pair<int, int>, int>(pair<int, int>(a, b), i));
  }
  solve(n);
}