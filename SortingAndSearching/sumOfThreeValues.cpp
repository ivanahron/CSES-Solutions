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
int arr[MAX_N];

bool notIn(int i, vector<int> &arr) {
  for (int j : arr) if (i == j) return false;
  return true;
}

void solve(int n, int x) {
  map<int, int> freq;
  for (int i = 0; i < n; i++) {
    freq[arr[i]]++;
  }

  multiset<int> nums;
  for (int i = 0; i < n; i++) {
    nums.insert(arr[i]);
  }

  int ans;
  vector<int> ansIndices;

  for (int i = 0; i < n; i++) {
    bool found = false;
    for (int j = i + 1; j < n; j++) {
      int curr = arr[i] + arr[j];
      int rem = x - curr;
      if ((nums.find(rem) != nums.end()) && ((rem != arr[i] && rem != arr[j]) ||
      (rem == arr[i] && rem == arr[j] && freq[rem] >= 3) ||
      (rem == arr[i] && rem != arr[j] && freq[rem] >= 2) || 
      (rem != arr[i] && rem == arr[j] && freq[rem] >= 2))) {
        ansIndices.push_back(i);
        ansIndices.push_back(j);
        ans = rem;
        found = true;
        break;
      }
    }
    if (found) break;
  }

  for (int i = 0; i < n; i++) {
    if (ans == arr[i] && notIn(i, ansIndices)) {
      ansIndices.push_back(i);
      break;
    }
  }

  sort(ansIndices.begin(), ansIndices.end());
  if (ansIndices.size() < 3) cout << "IMPOSSIBLE";
  else for (int i : ansIndices) cout << i + 1 << ws;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n, x;
  cin >> n >> x;

  for (int i = 0; i < n; i++) cin >> arr[i];
  solve(n, x);
}