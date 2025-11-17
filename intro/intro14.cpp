#include <bits/stdc++.h>
using namespace std;

void tower_of_hanoi(int n, string start, string end, string mid, vector<string> &ans) {
  if (n == 1) {
    string step = start + " " + end; 
    ans.push_back(step);
  } else {
    tower_of_hanoi(n - 1, start, mid, end, ans);
    string step = start + " " + end; 
    ans.push_back(step);
    tower_of_hanoi(n - 1, mid, end, start, ans);
  }
}

int main() {
  int n;
  cin >> n;
  vector<string> ans = {};
  tower_of_hanoi(n, "1", "3", "2", ans);

  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
    if (i != ans.size() - 1) cout << '\n';
  }
}