#include <bits/stdc++.h>
using namespace std;

#define ll long long

int bs(vector<pair<ll, int>> &nums, ll target, int index) {
  int left = 0;
  int right = nums.size();

  while (left < right) {
    int mid = (left + right) / 2;
    if (nums[mid].first == target) {
      if (nums[mid].second != index) return nums[mid].second;
      else {
        if (nums[mid - 1].first == target) return nums[mid - 1].second;
        if (nums[mid + 1].first == target) return nums[mid + 1].second;
        else {
          return -1;
        }
      }
    } else if (nums[mid].first < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return -1;
}

void solve(vector<pair<ll, int>> &nums, ll target) {
  for (auto [num, index]: nums) {
    ll tryFind = bs(nums, target - num, index);
    if (tryFind != -1) {
      if (index >= tryFind) cout << tryFind << ' ' << index;
      else cout << index << ' ' << tryFind;
      exit(0);
    }
  }

  cout << "IMPOSSIBLE";
}

int main() {
  ios_base :: sync_with_stdio(false);
  int n;
  ll x;
  cin >> n >> x;

  vector<pair<ll, int>> numIndex;

  for (int i = 0; i < n; i++) {
    ll num;
    cin >> num;
    numIndex.push_back(pair<ll, int>(num, i + 1)); 
  }

  sort(numIndex.begin(), numIndex.end(), [](const pair<ll, int> &a, const pair<ll, int> &b) {
    return a.first < b.first;
  });

  solve(numIndex, x);
}