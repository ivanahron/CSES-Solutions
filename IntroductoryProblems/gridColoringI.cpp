#include <bits/stdc++.h>
using namespace std;

bool valid(int i, int j, int n, int m) {
  return (0 <= i && i < n) && (0 <= j && j < m);
}

int di[2] = {-1, 0};
int dj[2] = {0, -1};

int main() {
  int n, m;
  cin >> n >> m;

  vector<string> grid;
  for (int i = 0; i < n; i++){
    string row;
    cin >> row;
    grid.push_back(row);
  }

  set<char> chars = {'A', 'B', 'C', 'D'};
  map<char, bool> allowed;
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (auto ch : chars) allowed[ch] = true;
      
      allowed[grid[i][j]] = false;

      for (int k = 0; k < 2; k++) {
        int ni = i + di[k], nj = j + dj[k];
        if (valid(ni, nj, n, m)) allowed[grid[ni][nj]] = false;
      }

      for (auto [ch, v] : allowed) {
        if (v) {
          grid[i][j] = ch;
          break;
        }
      }
    }
  }
  
  cout << grid[0];
  for (int i = 1; i < n; i++) {
    cout << '\n' << grid[i];
  }
  
}