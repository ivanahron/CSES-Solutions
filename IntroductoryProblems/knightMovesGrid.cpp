#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dir = {{2, 1}, {-2, 1}, {1, 2}, {-1, 2}, {2, -1}, {-2, -1}, {1, -2}, {-1, -2}};

bool valid(int i, int j, int n) {
  return (0 <= i && i < n) && (0 <= j && j < n);
}
void bfs(pair<int, int> start, int n, vector<vector<int>> &board) {
  vector<vector<bool>> vis(n, vector<bool>(n, 0));
  queue<pair<int, int>> kyu;
  kyu.push(start);

  while (!kyu.empty()) {
    pair<int, int> u = kyu.front();
    int i = u.first, j = u.second;
    kyu.pop();

    if (vis[i][j]) continue;
    vis[i][j] = true;

    for (auto [di, dj] : dir) {
      int ni = i + di, nj = j + dj;
      if (valid(ni, nj, n) && !vis[ni][nj]) {
        board[ni][nj] = board[i][j] + 1;
        pair<int, int> v(ni, nj);
        kyu.push(v);
      }
    }
  }
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> board(n, vector<int>(n, 0));
  pair<int, int> start(0, 0);
  bfs(start,  n, board);

  for (auto row : board) {
    for (auto cell : row) cout << cell << ' ';
    cout << '\n';
  } 
}