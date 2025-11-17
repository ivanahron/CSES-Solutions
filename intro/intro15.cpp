#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  sort(s.begin(), s.end());

  vector<string> perms = {s};

  while (next_permutation(s.begin(), s.end())) {
    perms.push_back(s);
  }

  cout << perms.size();
  
  for (auto perm : perms) cout << '\n' << perm;
}