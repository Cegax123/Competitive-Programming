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

const int maxk = 20;
ll f[(1 << maxk)];

string s; 

void build(int v = 1) {
	if((v << 1) > (int) s.size()) {
		if(s[v-1] == '0' or s[v-1] == '1') f[v] = 1;
		else f[v] = 2;
		return;
	}

	build(2*v);
	build(2*v+1);

	if(s[v-1] == '0') f[v] = f[2*v+1];
	else if(s[v-1] == '1') f[v] = f[2*v];
	else f[v] = f[v*2]+f[v*2+1];
}

void update(int v, char c) {
	if(v == 0) return;

	s[v-1] = c;

	if((v << 1) > (int) s.size()) {
		if(s[v-1] == '0' or s[v-1] == '1') f[v] = 1;
		else f[v] = 2;
	}
	else {
		if(s[v-1] == '0') f[v] = f[2*v+1];
		else if(s[v-1] == '1') f[v] = f[2*v];
		else f[v] = f[v*2]+f[v*2+1];
	}
	update(v/2, s[(v/2)-1]);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int k; cin >> k;

	cin >> s;
	int n = (int) s.size();
	reverse(all(s));

	build();

	int q; cin >> q;
	while(q--) {
		int pos; cin >> pos;
		char c; cin >> c;
		pos = n-pos+1;

		update(pos, c);

		cout << f[1] << "\n";
	}
	
	return 0;
}