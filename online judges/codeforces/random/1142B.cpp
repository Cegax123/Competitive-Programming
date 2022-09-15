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

const int maxn = 2e5+5;
const int LOGN = 20;

struct Query {
	int l, r, id;
	bool ans = 0;
};

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, q; cin >> n >> m >> q;
	int p[n+1], pp[n+1];

	for(int i = 1; i <= n; i++) {
		cin >> p[i];
		pp[p[i]] = i;
	}

	int a[m+1];

	for(int i = 1; i <= m; i++) {
		cin >> a[i];
		// cout << a[i] << " ";
	}

	// cout << endl;

	vi last(n+1, m+1);
	vector<vi> go(m+2, vi(LOGN));

	for(int j = 0; j < LOGN; j++)
		go[m+1][j] = m+1;

	for(int i = m; i >= 1; i--) {
		int pos_nxt = pp[a[i]]+1;
		if(pos_nxt > n) pos_nxt -= n;

		int nxt = p[pos_nxt];

		go[i][0] = last[nxt];
		last[a[i]] = i;
	}


	for(int j = 1; j < LOGN; j++) {
		for(int i = 1; i <= m; i++) {
			go[i][j] = go[go[i][j-1]][j-1];
		}
	}

	int r[m+1];

	for(int i = 1; i <= m; i++) {
		r[i] = i;
		for(int j = 0; j < LOGN; j++) {
			if(((n-1) >> j)&1)
				r[i] = go[r[i]][j];
		}
	}

	// for(int i = 1; i <= m; i++)
	// 	cout << (r[i] == 100) << " ";

	vector<Query> save;
	vector<Query> queries[m+1];

	for(int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		queries[l].pb({l, r, i});
		save.pb({l, r, i});
	}

	priority_queue<ii> pq;
	vector<bool> ans(q, false);

	for(int i = 1; i <= m; i++) {
		for(auto Q : queries[i]) {
			pq.push({Q.r, Q.id});
		}

		if(r[i] == m+1) continue;

		while(!pq.empty()) {
			auto e = pq.top();

			int R = e.first, ID = e.second;

			if(R >= r[i]) {
				pq.pop();
				if(R >= i) ans[ID] = 1;
			}
			else break;
		}
	}

	for(int i = 0; i < q; i++)
		cout << ans[i];
	
    return 0;
}
