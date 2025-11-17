#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool valid(vector<pair<int, int>> chosen, pair<int, int> curr) {
  int row = curr.first, col = curr.second;
  for (auto [r1, c1] : chosen) {
    if (abs(r1 - row) == abs(c1 - col) || (r1 + c1) == (row + col)) {
      return false;
    }
  }

  return true;
}

int main() {
  vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {1, -1}, {1, 1}};
  
  // int invalidCells = 0;
  vector<vector<int>> board(8, vector<int>(8));
  for (int i = 0; i < 8; i++) {
    string row;
    cin >> row;
    for (int j = 0; j < 8; j++) {
      // if (row[j] == '*') invalidCells++;
      board[i][j] = row[j];
    }
  }
  
  int ans = 0;
  vector<int> queens(8);
  for (int i = 0; i < 8; i++) queens[i] = i + 1;

  while (next_permutation(queens.begin(), queens.end())) {
    vector<pair<int, int>> chosen = {};
    for (int row = 0; row < 8; row++) {
      int col = queens.at(row) - 1;
      pair<int, int> curr(row, col);
      if (!valid(chosen, curr) || board[row][col] == '*') break;
      chosen.push_back(curr);
    }

    if (chosen.size() == 8) ans++;
  }

  cout << ans;

}