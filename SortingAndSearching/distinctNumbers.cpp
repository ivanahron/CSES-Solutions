#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(int &acc, vector<ll> &nums) {
  set<ll> uniqueNums;

  for (auto& num : nums) {
    uniqueNums.insert(num);
  }

  acc = uniqueNums.size();
}

int main() {
  ios_base :: sync_with_stdio(false);
  int n;
  cin >> n;

  vector<ll> nums(n);
  for (int i = 0; i < n; i++) 
    cin >> nums[i];
  
  int acc = 0;
  solve(acc, nums);
  cout << acc;
}