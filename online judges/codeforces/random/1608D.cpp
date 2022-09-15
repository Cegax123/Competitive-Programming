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

string s[maxn];
vi poss[maxn];

bool comp(string a, string b) {
	if(a[1] == b[0]) return 0;
	return 1;
}

void obtain(int pos) {
	if(s[pos][0] == '?') {
		poss[pos].pb(0);
		poss[pos].pb(2);
	}
	else {
		poss[pos].pb(2*(s[pos][0]-'0'));
	}

	if(s[pos][1] == '?') {
		int k = poss[pos].size();
		for(int i = 0; i < k; i++) {
			poss[pos].pb(poss[pos][i]+1);
		}
	}
	else {
		for(int i = 0; i < (int) poss[pos].size(); i++)
			poss[pos][i] += s[pos][1]-'0';
	}
}

bool poss_mask(int pos, int mask) {
	for(auto x : poss[pos])
		if(mask == x) return 1;
	return 0;
}

const ll mod = 998244353;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> s[i];

		if(s[i][0] == 'W') s[i][0] = '0';
		if(s[i][0] == 'B') s[i][0] = '1';
		if(s[i][1] == 'W') s[i][1] = '0';
		if(s[i][1] == 'B') s[i][1] = '1';

		obtain(i);
	}

	ll ans = 0;
	
	bool comp01=1, comp10=1;
	
	for(int i = 0; i < n; i++) {
		if(!poss_mask(i, 1)) comp01 = 0;
		if(!poss_mask(i, 2)) comp10 = 0;
	}

	ans += comp01 + comp10;

	

	return 0;
}
