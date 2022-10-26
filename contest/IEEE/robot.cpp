#include<bits/stdc++.h>
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

ll bezout(ll a, ll b, ll& x_0, ll& y_0) {
  if (b == 0) { //solucion base a 1 + b 0 = a
    x_0 = 1;
    y_0 = 0;
    return a;
  }  
  ll x_1, y_1;
  ll g = bezout(b, a%b, x_1, y_1);
  x_0 = y_1;
  y_0 = x_1 - (a/b) * y_1;
  return g;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while(t--) {
		int r; cin >> r;
		string rob[r];
		for(int i = 0; i < r; i++) cin >> rob[i];

		bool vis[r][r];
		memset(vis, 0, sizeof(vis));

		vii seq;

		seq.pb({0, 0});
		vector<bool> in_cycle(1, 0);

		int L = 0;
		
		while(1) {
			int a = seq.back().first, b = seq.back().second;
			
			in_cycle.pb(0);
			vis[a][b] = 1;

			if(rob[a][b] == '>') b++;
			else if(rob[a][b] == '<') b--;
			else if(rob[a][b] == 'v') a++; 
			else if(rob[a][b] == '^') a--;

			if(!vis[a][b]) {
				seq.pb({a, b});
				continue;
			}

			for(int i = (int) seq.size()-1; i >= 0; i--) {
				in_cycle[i] = 1;
				L++;
				if(seq[i] == make_pair(a, b)) break;
			}

			break;
		}

		int k; cin >> k;
		map<ii, int> mp;

		for(int i = 0; i < k; i++) {
			int x, y; cin >> x >> y;
			mp[{x, y}] = (i == 0 ? k : i);
		}

		const ll INF = (ll) 1e18;
		ll ans = INF;

		int g = __gcd(L, k);
		
		ll X = L / g, Y = k / g;
		ll r1 = 0, r2 = 0;
		
		ll rx = abs(Y) / g, ry = abs(X) / g;

		bezout(X, -Y, r1, r2);

		for(int i = 0; i < (int) seq.size(); i++) {
			int x = mp[{seq[i].first, seq[i].second}];
			
			
			if(x == 0) continue;

			x %= k;

			if(!in_cycle[i]) {
				if((i-x) % k == 0) {
					ans = min(ans, (ll) i);
				}
			}
			else {
				if(abs(x-i) % g) {
					continue;
				}
				
				ll R1 = r1 * ((x-i) / g), R2 = r2 * ((x-i) / g);
				ll tmp = R1;
				R1 = abs(R1), R2 = abs(R2);
				
				ll t = max((R1 + rx - 1) / rx, (R2 + ry - 1)/ ry);
				
				tmp += t * rx;
				
				ans = min(ans, L * tmp + i);
			}
		}
		
		if(ans == INF) cout << "never\n";
		else cout << ans << "\n";
	}


	return 0;
}

