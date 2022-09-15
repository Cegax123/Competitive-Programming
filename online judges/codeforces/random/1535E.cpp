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

const int maxn = 3e5+5;
const int MAX_LOG = ceil(log2(maxn))+2;

int p[maxn][MAX_LOG];
ll a[maxn], c[maxn];
ll used[maxn];
ll amount[maxn];

void update(int v, int par) {
	p[v][0] = par;
	if(v) amount[v] = (ll) amount[par] + a[v];

	for(int i = 1; i < MAX_LOG; i++) {
		p[v][i] = p[p[v][i-1]][i-1];
	}
}

bool isUsed(int v) {
	return used[v] != -1;
}

int find_used(int v) {
	if(isUsed(v)) 
		return v;

	for(int i = MAX_LOG-1; i >= 0; i--) {
		if(!isUsed(p[v][i])) {
			v = p[v][i];
		}
	}

	return p[v][0];
}

bool canObtain(int v, ll substract, int w) {
	return amount[v] - substract >= (ll) w;
}

int find_s(int v, ll substract, int w) {
	for(int i = MAX_LOG - 1; i >= 0; i--) {
		if(canObtain(p[v][i], substract, w)) {
			v = p[v][i];
		} 
	}

	return v;
}

ll fill_s(int s, bool all, ll toUse) {
	if(used[s] == a[s])
		return 0ll;

	ll ans = 0;
	if(!all) {
		ans = toUse * c[s];

		if(isUsed(s)) used[s] += toUse;
		else used[s] = toUse;
	}
	else {
		ans = (a[s]-(isUsed(s) ? used[s] : 0)) * c[s];
		used[s] = a[s];
	}
	return ans + (s == 0 ? 0:fill_s(p[s][0], 1, -1));
}

int main() {
	update(0, 0);

	memset(used, -1, sizeof(used));
	used[0] = 0;

	int q; scanf("%d %lld %lld", &q, &a[0], &c[0]);
	// int q; cin >> q >> a[0] >> c[0]
	amount[0] = a[0];

	for(int i = 1; i <= q; i++) {
		int op; scanf("%d",&op);
		
		if(op == 1) {
			int par; scanf("%d %lld %lld", &par, &a[i], &c[i]);
			// int par; cin >> par >> a[i] >> c[i];
			update(i, par);
		}
		else {
			int v; ll w; scanf("%d %lld", &v, &w);
			// int v, w; cin >> v >> w;
			int x = find_used(v);
			ll substract = amount[x] - a[x] + used[x];

			if(!canObtain(v, substract, w)) {
				w = amount[v] - substract;
			}

			int s = find_s(v, substract, w);
			ll buyed = 0;
			if(s) buyed = max(0ll, amount[p[s][0]]-substract);

			ll ans = fill_s(s, 0, w-buyed);
			printf("%lld %lld\n", w, ans);
			fflush(stdout);
			// cout << w << " " << ans << "\n";
		}
		
	}


	
	return 0;
}
