#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e20
#define endl '\n'
#define ws ' '

const int MAX_N = 2 * 1e5 + 5;
ll arr[MAX_N];

void solve() {
	int n;
	cin >> n;
	set<ll> fs;
  set<ll> sf;
	
	vector<pair<ll, ll>> o;
	vector<pair<ll, ll>> intervals;
	for (int i = 0; i < n; i++) {
		ll f, s;
		cin >> f >> s;
		o.push_back(pair<ll,ll>(f, s));
		intervals.push_back(pair<ll, ll>(f, s));
	}
	
	sort(intervals.begin(), intervals.end(), [](const pair<ll, ll> &a, const pair<ll,ll>&b){ return a.first == b.first ? a.second > b.second : a.first < b.first;});
	
	map<pair<ll,ll>, int> isContained;
	map<pair<ll,ll>, int> contains;
	
	for (int i = 0; i<n;i++) {
		auto pr = intervals[i];
		ll a = pr.first, b = pr.second;
		
		if (fs.lower_bound(b) != fs.end()){
			isContained[pr] = 1;
			} else isContained[pr] = 0;
		fs.insert(b);
	}
	
	for (int i = n - 1; i > -1; i--) {
	  auto pr = intervals[i];
	  ll a = pr.first, b = pr.second;
	  auto lowr = sf.lower_bound(b);
	  if (*lowr == b){
	    contains[pr] = 1;
	  } else {
	    if (lowr == sf.begin()) {
	      contains[pr] = 0;
	    } else contains[pr] = 1;
	  }
	  sf.insert(b);
	}
	for (int i = 0; i < n; i++) cout << contains[o[i]] << ' ';
	cout << '\n';
	for (int i = 0; i < n; i++) cout << isContained[o[i]] << ' ';
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}