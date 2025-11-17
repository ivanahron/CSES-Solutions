#include <bits/stdc++.h>
using namespace std;

bool arr[200005];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) arr[i] = false;

  for (int i = 0; i < n - 1; i++) {
    int num;
    cin >> num;
    arr[num - 1] = true;
  }

  for (int i = 0 ; i < n; i++) {
    if (!arr[i]) {
      cout << i + 1;
      break;
    }
  }
}
