#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void getDiffs(vector<ll> &nums, ll sum,  ll sumAll, int index, vector<ll> &diffs) {
  if (index == nums.size()) {
    diffs.push_back(abs(sumAll - 2*sum));
  } else {
    getDiffs(nums, sum + nums[index], sumAll, index + 1, diffs);
    getDiffs(nums, sum, sumAll, index + 1, diffs);
  }
}

int main() {
  int n;
  cin >> n;

  vector<ll> nums;
  vector<ll> diffs;
  
  for (int i = 0; i < n; i++) {
    ll num;
    cin >> num;
    nums.push_back(num);
  }

  getDiffs(nums, 0, accumulate(nums.begin(), nums.end(), 0LL), 0, diffs);

  cout << *min_element(diffs.begin(), diffs.end());
}