#include <bits/stdc++.h>
using namespace std;

int main() {
  string dna;
  cin >> dna;

  int global_max = 1;
  int curr_max = 1;
  for (int i = 1; i < dna.length(); i++) {
    if (dna[i] == dna[i - 1]) curr_max++;
    else curr_max = 1;

    global_max = max(global_max, curr_max);
  }

  cout << global_max;
}