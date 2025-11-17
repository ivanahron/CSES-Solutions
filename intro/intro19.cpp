#include <bits/stdc++.h>
using namespace std;

bool valid(int i, int j, int n) {
  return (0 <= i && i < n) && (0 <= j && j < n);
}

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> dir = {{-1, 0}, {0, -1}};

  vector<vector<int>> grid(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) 
    for (int j = 0; j < n; j++) {
      set<int> taken;

      for (auto [di, dj] : dir) {
        int ni = i + di, nj = j + dj;
        while (valid(ni, nj, n)) {
          taken.insert(grid[ni][nj]);
          ni += di;
          nj += dj;
        }
      }

      for (int k = 0; k < n * n; k++) {
        if (taken.find(k) == taken.end()) {
          grid[i][j] = k;
          break;
        }
      }
    }
  
  for (auto row : grid) {
    for (auto cell : row) cout << cell << ' ';
    cout << '\n';
  } 
}