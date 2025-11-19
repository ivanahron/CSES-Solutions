#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e20

const int MAX_N = 2 * 1e5;
pair<int, int> arr[MAX_N];

void solve(int n) {
  int round = 1;
  
  for (int i = 0; i < n - 1; i++) {
    auto curr = arr[i], next = arr[i + 1];
    if (curr.first > next.first) round++;
  }

  cout << round;
}

int main() {
  ios_base :: sync_with_stdio(false);
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    arr[i] = pair<int, int>(i, num);
  }

  sort(begin(arr), begin(arr) + n, [](const pair<int, int>&a, const pair<int, int>&b) {
    return a.second < b.second;
  });

  solve(n);
}
// 1 5 2 3 4
// (0, 4), (1, 2), (2, 1), (3, 5), (4, 3)
// (2, 1), (1, 2), (4, 3), (0, 4), (3, 5)