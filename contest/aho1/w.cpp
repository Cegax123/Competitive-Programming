// UNSOLVED

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

const int SUML = 1e5 + 5;
const int E = 260;

int n;
int nodes;
int suf[SUML];
bool term[SUML];
int super[SUML];
int len[SUML];
int trie[SUML][E];
int go[SUML][E];

void insert(const string& s){
	int pos = 0;
	for(unsigned char c : s){
		int nxt = c;
		if(trie[pos][nxt] == 0){
			trie[pos][nxt] = nodes++;
		}
		len[trie[pos][nxt]] = len[pos]+1;
		pos = trie[pos][nxt];
	}
	term[pos]=1;
}

void BFS(int src){
	queue<int> Q;
	Q.emplace(src);
	while(!Q.empty()){
		int u = Q.front(); Q.pop();

		if(term[suf[u]]) super[u] = suf[u];
		else super[u] = super[suf[u]];

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

int process(const string& line) {
	int ans = line.size();
	int pos = 0;
	for(int i = 0; i < (int) line.size(); i++) {
		unsigned char c = line[i];
		int nxt = c;
		pos = go[pos][nxt];

		if(pos and term[pos]) 
			ans = min(ans, i-len[pos]+1);
		else if(super[pos]) 
			ans = min(ans, i-len[super[pos]]+1);
	}
	return (ans == (int) line.size() ? -1 : ans);
}

int main(){
	int n; cin >> n;
	nodes = 1;

	string s; getline(cin, s);
	for(int i = 1; i <= n; i++){
		getline(cin, s);
		insert(s);
	}
	BFS(0);

	int q; cin >> q;
	bool found = 0;

	string line; getline(cin, line);
	for(int i = 1; i <= q; i++) {
		getline(cin, line);

		int ans = process(line);

		if(ans==-1) continue;

		found = 1;
		cout << i << " " << ans+1 << "\n";
		break;
	}

	if(found == 0) cout << "Passed\n";
	
	return 0;
}