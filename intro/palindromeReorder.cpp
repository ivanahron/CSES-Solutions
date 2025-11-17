#include <bits/stdc++.h>
using namespace std;

int main() {
  map<char, int> freq = {};

  string s;
  cin >> s;

  for (auto c : s) {
    if (freq.find(c) == freq.end()) {
      freq[c] = 1;
    } else 
      freq[c] += 1;
  }

  int odd = 0, even = 0;

  for (auto [key, val] : freq) {
    if (val & 1) odd++;
    else even++;
  }

  if (odd > 1) cout << "NO SOLUTION\n";
  else {
    string ans = "";
    string oddChar;
    for (auto [key, val] : freq) {
      if (val % 2 == 0) {
        string s(val/2, key);
        ans += s;
      } else {
        string o(val, key);
        oddChar = o;
      }
    }
    string rev(ans.size(), ' ');
    reverse_copy(ans.begin(), ans.end(), rev.begin());

    ans += oddChar;
    ans += rev;
    cout << ans << '\n';
  }
  
}