#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back 
#define dbg(x) do {cerr << #x <<" = " << (x) << "\n"; } while (false)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
//cout << setprecision(12) << fixed;

const int maxn = 1e5+5;
int n, k;

int a[maxn];
ll ft[maxn];
ll cnt[maxn];

int LSO(int pos) {
	return pos - (pos & (pos-1));
}

ll get(int pos) {
	ll res = 0;
	while(pos > 0) {
		res = ft[pos] + res;
		pos -= LSO(pos); // pos = pos & (pos-1);
	}
	return res;
}

void update(int pos, ll val) {
	while(pos <= n) {
		ft[pos] = ft[pos] + val;
		pos += LSO(pos);
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> k;

	for(int i = 0; i < maxn; i++) 
		cin >> a[i];

	memset(cnt, 0, sizeof(cnt));

	for(int i = 1; i <= n; i++)
		cnt[i] = 1;

	for(int t = 0; t < k; t++) {
		memset(ft, 0, sizeof(ft));
		ll tmp[maxn];

		for(int i = 0; i < n; i++) {
			update(a[i], cnt[a[i]]);
			tmp[a[i]] = get(a[i]-1);
		}

		for(int i = 1; i <= n; i++)
			cnt[i] = tmp[i];
	}

	ll ans = 0;

	for(int i = 1; i <= n; i++) {
		ans += cnt[i];
	}

	cout << ans << "\n";
	
	return 0;
}