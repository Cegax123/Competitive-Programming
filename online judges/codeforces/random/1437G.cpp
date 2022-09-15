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

const int SUML = 3e5 + 5;
const int E = 26;
const int maxn = 3e5+5;

int n;
int nodes;
int suf[SUML];
bool term[SUML];
int trie[SUML][E];
int super[SUML];
int go[SUML][E];
set<ii> susp[SUML];
int node[maxn], val[maxn];

void insert(const string& s, int j){
	int pos = 0;
	for(int i = 0; i < (int) s.size(); i++){
		int nxt = s[i] - 'a';
		if(trie[pos][nxt] == 0){
			trie[pos][nxt] = nodes++;
		}
		pos = trie[pos][nxt];
	}
	term[pos] = 1;
	node[j] = pos;
}

void BFS(int src){
	queue<int> Q;
	Q.emplace(src);
	while(!Q.empty()){
		int u = Q.front(); Q.pop();

		if(term[suf[u]]) super[u] = suf[u];
		else super[u] = super[suf[u]];

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

int query(const string& s) {
	int pos = 0;
	int ans = -1;

	for(int i = 0; i < (int) s.size(); i++) {
		int nxt = s[i]-'a';
		pos = go[pos][nxt];

		int tmp = term[pos] ? pos : super[pos];

		while(tmp) {
			ans = max(ans, (*susp[tmp].rbegin()).first);
			tmp = super[tmp];
		}
	}	

	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, m; cin >> n >> m;
	nodes = 1;

	for(int i = 0; i < n; i++) {
		string s; cin >> s;
		insert(s, i);

		int v = node[i];
		susp[v].insert({0, i});
	}

	BFS(0);

	for(int i = 0; i < m; i++) {
		int op; cin >> op;
		if(op == 1) {
			int j, x; cin >> j >> x;
			int v = node[j-1];

			susp[v].erase({val[j-1], j-1});
			susp[v].insert({x, j-1});
		
			val[j-1] = x;
		}
		else {
			string s; cin >> s;
			cout << query(s) << "\n";
		}
	}
	
	return 0;
}
