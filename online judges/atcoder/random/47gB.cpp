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

const int SUML = 1e6;
const int E = 26;

int trie[SUML+5][E];
int cnt[SUML+5][E];
int nodes = 1;

int process(const string& s) {
	int pos = 0;

	for(int i = 0; i < (int) s.size()-1; i++) {
		int nxt = s[i]-'a';
		pos = trie[pos][nxt];

		if(pos == 0) return 0;
	}

	int last = s.back()-'a';
	return cnt[pos][last];
}

void insert(const string& s) {
	vi curr(E, 0);

	for(char c : s)
		curr[c-'a']++;

	for(int c = 0; c < E; c++) 
		if(curr[c]) cnt[0][c]++;

	int pos = 0;
	for(int i = 0; i < (int) s.size(); i++) {
		int nxt = s[i]-'a';
		curr[nxt]--;

		if(trie[pos][nxt] == 0) {
			trie[pos][nxt] = nodes++;
		}

		pos = trie[pos][nxt];

		for(int c = 0; c < E; c++) 
			if(curr[c]) cnt[pos][c]++;
	}
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    vector<string> s[SUML+1];

	for(int i = 0; i < n; i++) {
		string x; cin >> x;
		reverse(all(x));

		s[x.size()].pb(x);
	}

	ll ans = 0;
	for(int i = SUML; i >= 0; i--) {
		for(const string& x : s[i]) {
			ans += process(x);
			insert(x);
		}
	}

	cout << ans << "\n";
	
    return 0;
}
