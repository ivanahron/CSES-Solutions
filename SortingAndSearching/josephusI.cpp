#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e20
#define endl '\n'
#define ws ' '

const int MAX_N = 2 * 1e5 + 5;
bool arr[MAX_N];

void solve(int n, ll k) {
  list<int> l;
  for (int i = 1; i <= n; i++) l.push_back(i);

  auto iter = l.begin();
  int pos = 1;
  while (l.size() > 0) {
    vector<list<int>::iterator> iterators;

    while (iter != l.end()) {
      if (pos == 0) {
        iterators.push_back(iter);
      }
      iter++;
      pos = (pos + 1) % k;
    }

    for (auto it : iterators) {
      cout << *it << ws;
      l.erase(it);
    }

    iter = l.begin();
  }

}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n; ll k;
  cin >> n >> k;

  solve(n, k);
}