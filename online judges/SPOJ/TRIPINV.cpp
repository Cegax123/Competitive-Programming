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
int a[maxn];
vi up(maxn, 0), low(maxn, 0);
int n;

int LSO(int pos) {
	return pos - (pos & (pos-1));
}

int get(int pos, const vi& ft) {
	int res = 0;
	while(pos > 0) {
		res = ft[pos] + res;
		pos &= (pos-1);
	}
	return res;
}

void update(int pos, int val, vi& ft) {
	while(pos <= n) {
		ft[pos] = ft[pos] + val;
		pos += LSO(pos);
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	int cntUp[maxn], cntLow[maxn];

	for(int i = 0; i < n; i++) {
		update(a[i], 1, up);
		cntUp[i] = get(n, up)-get(a[i], up);
	}

	for(int i = n-1; i >= 0; i--) {
		update(a[i], 1, low);
		cntLow[i] = get(a[i]-1, low);
	}

	ll ans = 0;

	for(int i = 0; i < n; i++) {
		// cout << cntUp[i] << " " << cntLow[i] << "\n";
		ans += (ll) cntUp[i] * cntLow[i];
	}

	cout << ans << "\n";
	
	return 0;
}