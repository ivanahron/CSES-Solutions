#include <bits/stdc++.h>
using namespace std;

int safeIndex(int i, int maxIndex) {
  return i % maxIndex;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, a, b;
    cin >> n >> a >> b;

    if ((a + b) > n || a >= n || b >= n || (a == 0 && b > 0) || (b == 0 && a > 0)) {
      cout << "NO\n";
      continue;
    }

    cout << "YES\n";

    vector<int> cardsA = {};
    vector<int> cardsB = {};

    int diff = n - (a + b);

    for (int i = 0; i < diff; i++) {
      cardsA.push_back(n - i);
      cardsB.push_back(n - i);
    }

    for (int i = 0; i < n - diff; i++) {
      cardsA.push_back(safeIndex(i + b, n - diff) + 1);
      cardsB.push_back(i + 1);
    }


    for (auto card : cardsA) {
      cout << card << ' ';
    }
    cout << '\n';
    for (auto card : cardsB) {
      cout << card << ' ';
    }
    cout << '\n';
  }  
}