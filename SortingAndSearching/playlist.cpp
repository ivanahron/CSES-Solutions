#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e20

const int MAX_N = 2 * 1e5 + 5;
int arr[MAX_N];

void solve(int n) {
  int i = 0, j = 1;

  int global_max = 1;
  set<int> songs = {arr[i]};

  while (i < n && j < n) {
    if (songs.find(arr[j]) != songs.end()) {
      global_max = max(global_max, j - i);

      while (arr[i] != arr[j]) {
        songs.erase(arr[i++]);
      }
      songs.erase(arr[i++]);
    } else {
      songs.insert(arr[j++]);
    }
  }

  global_max = max(global_max, j - i);

  cout << global_max;
}

int main() {
  ios_base :: sync_with_stdio(false);
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) cin >> arr[i];

  solve(n);
}