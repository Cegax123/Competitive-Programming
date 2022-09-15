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
const int LOGN = 20;

int sieve[maxn];
vi p;

void init() {
	for(int i = 2; i < maxn; i++) {
		if(sieve[i]) continue;

		sieve[i] = i;
		p.pb(i);

		for(int j = 2; i*j < maxn; j++) {
			if(sieve[i*j]) continue;
			sieve[i*j] = i;
		}
	}
}

vi get_div(int x) {
	vi ans;

	while(x != 1) {
		int d = sieve[x];
		while(x%d == 0) x/=d;
		ans.pb(d);
	}

	return ans;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();

    int n, q; cin >> n >> q;
    int a[n];

    for(int i = 0; i < n; i++)
    	cin >> a[i];

	int r = 0;
	vi cnt(maxn, 0);
	int cmp = 0;

	vector<vi> go(maxn, vi(LOGN));

	for(int i = 0; i < LOGN; i++)
		go[n][i] = n;

	for(int i = 0; i < n; i++) {
		while(r < n) {
			vi d = get_div(a[r]);

			for(int x : d) {
				if(cnt[x] == 1) cmp++;
				cnt[x]++;
			}

			if(cmp) {
				for(int x : d) {
					if(cnt[x] == 2) cmp--;
					cnt[x]--;
				}

				break;
			}
			r++;
		}

		go[i][0] = r;

		vi d = get_div(a[i]);

		for(int x : d) {
			if(cnt[x] == 2) cmp--;
			cnt[x]--;
		}
	}

	// for(int i = 0; i < n; i++)
	// 	cout << go[i][0] << " ";
	// cout << endl;

	for(int j = 1; j < LOGN; j++) {
		for(int i = 0; i < n; i++) {
			go[i][j] = go[go[i][j-1]][j-1];
		}
	}

	while(q--) {
		int l, r; cin >> l >> r;
		l--; r--;

		int ans = 0;

		for(int i = LOGN-1; i >= 0; i--) {
			if(go[l][i] <= r) {
				l = go[l][i];
				ans |= (1 << i);
			}
		}

		ans++;

		cout << ans << "\n";
	}

    return 0;
}
