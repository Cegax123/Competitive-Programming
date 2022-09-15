// SOLVED

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

const int SUML = 1e6 + 5;
const int E = 26;

int n;
int nodes;
int suf[SUML];
bool term[SUML];
int trie[SUML][E];
int super[SUML];
int go[SUML][E];
vi T(SUML, 1e9);

void insert(const string& s, int time){
	int pos = 0;
	for(int i = 0; i < (int) s.size(); i++){
		int nxt = s[i] - 'a';
		if(trie[pos][nxt] == 0){
			trie[pos][nxt] = nodes++;
		}
		pos = trie[pos][nxt];
	}
	T[pos] = min(T[pos], time);
	term[pos] = 1;
}

void build(int src){
	queue<int> Q;
	Q.emplace(src);
	while(!Q.empty()){
		int u = Q.front(); Q.pop();

		if(term[suf[u]]) super[u] = suf[u];
		else super[u] = super[suf[u]];

		T[u] = min(T[u], T[super[u]]);

		// cout << u << endl;
		for(int c = 0; c < E; c++){
			if(trie[u][c]){
				int v = trie[u][c];
				Q.emplace(v);
				
				go[u][c] = trie[u][c];
				suf[v] = u == 0 ? 0 : go[suf[u]][c];
			}
			else{
				go[u][c] = u == 0 ? 0 : go[suf[u]][c];
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	nodes = 1;

	int n; cin >> n;
	vector<pair<int, string>> queries;

	for(int i = 0; i < n; i++) {
		int tp; cin >> tp;
		string s; cin >> s;

		if(tp == 0) insert(s, i);
		else queries.pb({i, s});
	}
	
	build(0);

	for(auto query : queries) {
		int time = query.first; string s = query.second;
		int pos = 0;
		bool ans = 0;

		for(int i = 0; i < (int) s.size(); i++) {
			int nxt = s[i] - 'a';
			pos = go[pos][nxt];

			if(term[pos] and T[pos] < time) ans = 1;
			else if(term[super[pos]] and T[super[pos]] < time) ans = 1;
		}

		if(ans) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}
