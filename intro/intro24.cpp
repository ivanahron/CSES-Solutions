#include <bits/stdc++.h>
using namespace std;

const int N = 7;
bool vis[N][N];

static int di[4] = {1, -1, 0, 0};
static int dj[4] = {0, 0, 1, -1};

int total = 0;

bool valid(int i, int j) {
  return (0 <= i && i < N) && (0 <= j && j < N);
}

bool splits(int i, int j) {
  return (1 <= i && i < N - 1 && (j == 0 || j == N - 1 || (vis[i][j + 1] && vis[i][j - 1])) && !vis[i - 1][j] && !vis[i + 1][j]) || 
        (1 <= j && j < N - 1 && (i == 0 || i == N - 1 || (vis[i + 1][j] && vis[i - 1][j])) && !vis[i][j - 1] && !vis[i][j + 1]);
}

void dfs(string &ref, int refIndex, int i, int j) {
  if (i == 6 && j == 0) {
    if (refIndex == 48)
      total++;
    else return;
  }

  char curr = ref[refIndex];
  vis[i][j] = true;

  if (curr == '?') {
    for (int k = 0; k < 4; k++) {
      if (valid(i + di[k], j + dj[k]) && !vis[i + di[k]][j + dj[k]] && !splits(i + di[k], j + dj[k]))
        dfs(ref, refIndex + 1, i + di[k], j + dj[k]);
    }
  } else {
    int k = -1;
    if (curr == 'D') k = 0;
    else if (curr == 'U') k = 1;
    else if (curr == 'R') k = 2;
    else k = 3;

    if (valid(di[k] + i, dj[k] + j) && !vis[di[k] + i][dj[k] + j] && !splits(di[k] + i, dj[k] + j))
      dfs(ref, refIndex + 1, di[k] + i, dj[k] + j);
  }

  vis[i][j] = false;
}

int main() {
  ios_base :: sync_with_stdio(false);
  string moves;
  cin >> moves;

  for (int i = 0; i < N; i++) 
    for (int j = 0; j < N; j++) 
      vis[i][j] = false;

  dfs(moves, 0, 0, 0);
  cout << total;
}