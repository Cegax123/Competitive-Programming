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

const int L = 31;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		
		vi a(n);
		vii gr[L];

		for(int i = 0; i < n; i++) {
			cin >> a[i];

			for(int j = 0; j < L; j++) {
				if((a[i] >> j) & 1)
					gr[j].pb({a[i], i});
			}
		}

		vector<bool> used_bit(L, 0);
		int id[n];
		vector<vi> res;

		for(int i = 0; i < L; i++) {
			if(used_bit[i]) continue;

			vector<bool> marked(n, 0);
			int mask = (1 << i);


			queue<int> q;
			q.push(i);

			while(!q.empty()) {
				int v = q.front(); q.pop();
				used_bit[v] = 1;

				for(auto& el : gr[v]) {
					mask |= el.first;
					marked[el.second] = 1;
				}

				for(int j = 0; j < L; j++)
					if(((mask >> j) & 1) and !used_bit[j]) 
						q.push(j);
			}

			vi curr;

			for(int j = 0; j < n; j++) {
				if(marked[j]) {
					curr.pb(a[j]);
					id[j] = res.size();
				}
			}

			if(!curr.empty()) res.pb(curr);
		}

		for(auto& v : res)
			sort(all(v));

		int curr[L];
		memset(curr, 0, sizeof(curr));

		int c[n];

		for(int i = 0; i < n; i++) {
			if(a[i] == 0) {
				c[i] = 0;
				continue;
			}

			int pos = id[i];
			c[i] = res[pos][curr[pos]];
			curr[pos]++;
		}
		
		bool cmp = 1;

		for(int i = 1; i < n; i++) 
			if(c[i] < c[i-1]) cmp = 0;

		cout << (cmp ? "YES\n" : "NO\n");
	}
	
	
    return 0;
}
