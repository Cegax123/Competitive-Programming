#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back 
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
//cout << setprecision(12) << fixed;

const int maxn = 1e5+5;

int n;
vii a;
ll M, D;

bool comp(const ll& d) {
	ll curr = 0;
	for(int i = 0; i < n; i++) {
		curr += (ll) (a[i].first / d) * d * a[i].second;
		if(curr >= D) return true;
	}
	return false;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while(t--) {
		cin >> n >> M;
		ll sum = 0;

		int A = 0;
		map<int, int> freq;

		for(int i = 0; i < n; i++) {
			int x; cin >> x;
			freq[x]++;

			A = max(A, x);
			sum += x;
		}

		a.clear();

		for(auto& el : freq) 
			a.pb({el.first, el.second});

		D = sum - M;

		int ans = 0;
		for(int i = A; i >= 1; i--) {
			if(D%i) continue;

			if(comp(i)) {
				ans = i;
				break;
			}
		}

		cout << ans << "\n";
	}
	
	
    return 0;
}
