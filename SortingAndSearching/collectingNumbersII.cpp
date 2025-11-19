#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e20

const int MAX_N = 2 * 1e5 + 5;
pair<int, int> arr[MAX_N];

int solve(int n, vector<int> &pos) {
  int round = 1;
  for (int i = 0; i < n - 1; i++) {
    auto curr = arr[i], next = arr[i + 1];
    if (curr.first > next.first) round++;
    pos[i] = curr.first;
  }

  pos[n - 1] = arr[n - 1].first;

  return round;
}

int main() {
  ios_base :: sync_with_stdio(false);
  int n, m;
  cin >> n >> m;

  vector<int> unsortedArr(n);
  vector<int> pos(n);

  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    arr[i] = pair<int, int>(i, num);
    unsortedArr[i] = num;
  }

  sort(begin(arr), begin(arr) + n, [](const pair<int, int>&a, const pair<int, int>&b) {
    return a.second < b.second;
  });

  int round = solve(n, pos);

  for (int k = 0; k < m; k++) {
    int i, j;
    cin >> i >> j;

    int right = unsortedArr[max(i, j) - 1];
    int left = unsortedArr[min(i, j) - 1];

    set<pair<int, int>> candidates;

    for (int i = max(1, left - 1); i < min(left + 1, n); i++) 
      candidates.insert(pair<int, int>(i, i + 1));
    
    for (int i = max(1, right - 1); i < min(right + 1, n); i++) 
      candidates.insert(pair<int, int>(i, i + 1));
    
    for (auto [u, v] : candidates) if (pos[u - 1] > pos[v - 1]) round--;
    
    swap(pos[left - 1], pos[right - 1]);
    swap(unsortedArr[max(i, j) - 1], unsortedArr[min(i, j) - 1]);

    for (auto [u, v] : candidates) if (pos[u - 1] > pos[v - 1]) round++;
    cout << round << '\n';
  }
}
// let ai = # num less than a sa right
// a > ai, ai+1, ai+2
// b > bi, bi+1, bi+2
// a > b !=> ai, ai+1, ai+2 > bi, bi+1, bi+2

// 3 5 2 1 4
// 