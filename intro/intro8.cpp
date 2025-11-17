#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> left = {};
  vector<int> right = {};

  if ((n & 1 && !(((n - 1) / 2) & 1)) || (!(n & 1) && ((n / 2) & 1))) {
    cout << "NO";
    exit(0);
  }
  
  cout << "YES" << '\n';

  for (int i = 1; i <= n / 2; i++) {
    if (i & 1) {
      left.push_back(i);
      left.push_back(n & 1 ? n - i : n - i + 1);
    } else {
      right.push_back(i);
      right.push_back(n & 1 ? n - i : n - i + 1);
    }
  }

  if (n & 1) {
    right.push_back(n);
  }

  int l = left.size(), r = right.size();
  cout << l << '\n';
  for (int i = 0; i < l; i++) {
    cout << left.at(i);
    if (i == l - 1) cout << '\n';
    else cout << ' ';
  }

  cout << r << '\n';
  for (int j = 0; j < r; j++) {
    cout << right.at(j);
    if (j != r - 1) cout << ' ';
  }
}
