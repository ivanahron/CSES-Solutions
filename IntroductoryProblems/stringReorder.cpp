#include <bits/stdc++.h>
using namespace std;

bool valid(map<char, int> &freq, char curr, char& maxChar, int rem) {
  return ((maxChar == curr) || (rem - freq[maxChar] >= freq[maxChar])) && freq[curr];
}

int main() {

  ios_base :: sync_with_stdio(false);

  string s;
  cin >> s;

  map<char, int> freq;
  vector<char> chars;

  for (auto ch : s) {
    if (freq.find(ch) == freq.end()) {
      freq[ch] = 1;
      chars.push_back(ch);
    }
    else freq[ch]++;
  }

  string ans;
  char prev = '1';
  char maxChar = chars[0];

  for (auto& [key, val] : freq) 
    if (val > freq[maxChar]) maxChar = key;

  sort(chars.begin(), chars.end());

  for (int i = 0; i < s.size(); i++) {
    bool found = false;
    for (auto cand : chars) {
      if ((freq.find(cand) != freq.end()) && cand != prev && valid(freq, cand, maxChar, s.size() - ans.size())) {
        ans.push_back(cand);
        freq[cand]--;
        found = true;
        prev = cand;

        if (cand == maxChar) {
          for (auto& [key, val] : freq) 
            if (val > freq[maxChar]) maxChar = key;
        }
        break;
      }
    }
    if (!found) {
      cout << -1;
      exit(0);
    }
  }

  cout << ans;
}
