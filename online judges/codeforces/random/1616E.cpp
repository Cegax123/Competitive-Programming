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
string s, t;
int ft[maxn];
 
int LSO(int x) {
	return x-(x&(x-1));
}
 
void add(int pos, int val) {
	pos++;
 
	while(pos <= n) {
		ft[pos] += val;
		pos += LSO(pos);
	}
}
 
int index(int pos) {
	pos++;
	int res = 0;
 
	while(pos > 0) {
		res += ft[pos];
		pos -= LSO(pos);
	}
	return res;
}
 
const ll INF = (ll) 1e18;
const int E = 26;
 
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int q; cin >> q;
	while(q--) {
		cin >> n;
		cin >> s >> t;
		
		string r = s;
		sort(all(r));
 
		if(r >= t) {
			cout << "-1\n";
			continue;
		}
 
		deque<int> pos[E];
 
		for(int i = 0; i < n; i++) {
			pos[s[i]-'a'].pb(i);
			add(i, 1);
		}
 
		ll ans = INF;
		ll acumm = 0;
 
		for(int i = 0; i < n; i++) {
			int curr = t[i]-'a';
 
			for(int j = 0; j < curr; j++) {
				if(pos[j].empty()) continue;
 
				int ans_j = index(pos[j][0]);
				ans_j--;
 
				ans = min(acumm + ans_j, ans);
			}
 
			if(pos[curr].empty()) break;
 
			int ans_curr = index(pos[curr][0]);
			ans_curr--;
 
			acumm += ans_curr;
			add(pos[curr][0], -1);
 
			pos[curr].pop_front();
		}
 
		cout << ans << "\n";
 
		for(int i = 0; i <= n; i++)
			ft[i] = 0;
	}
	
	
	return 0;
}
 
