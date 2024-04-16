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

map<ll, int> dis;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	const int L = 11;
	ll pL[L+1];
	
	pL[0] = 1;
	for(int i = 1; i <= L; i++) pL[i] = pL[i-1] * L;
	
	ll init = 0;
	for(int i = 1; i < L; i++) init = init * L + i;
	
	auto swap_index = [&](ll x, int i, int j) {
		int di = (x / pL[i]) % L, dj = (x / pL[j]) % L;
		x -= di * pL[i] + dj * pL[j];
		x += di * pL[j] + dj * pL[i];
	
		return x;
	};
	
	dis[init] = 0;
	
	queue<ll> q;
	q.push(init);
	
	while(!q.empty()) {
		ll v = q.front(); q.pop();
		
		//cout << v << ":\n";
		
		for(int i = 0; i < L-1; i++) {
			int l = i-1, r = i+1;
			
			ll x = v;
			
			while(l >= 0 and r < L-1) {
				x = swap_index(x, l, r);
				l--; r++;
				
				if(x == init or dis[x]) continue;
				
				dis[x] = dis[v] + 1;
				q.push(x);
			}
		}
		
		for(int i = 0; i+1 < L-1; i++) {
			int l = i, r = i+1;
			
			ll x = v;
			
			while(l >= 0 and r < L-1) {
				x = swap_index(x, l, r);
				l--; r++;
				
				if(x == init or dis[x]) continue;
				
				dis[x] = dis[v] + 1;
				q.push(x);
			}
		}
	}
	
	int t; cin >> t;
	while(t--) {
		string c, d; cin >> c >> d;
		map<char, int> id;
		for(int i = 0; i < L-1; i++)
			id[c[i]] = i+1;
			
		ll num = 0;
		
		for(int i = 0; i < L-1; i++)
			num = num * L + id[d[i]];
			
		cout << dis[num] << "\n";
	}
	
	return 0;
}

