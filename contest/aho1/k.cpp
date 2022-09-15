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

const int SUML = 40 * 20 + 5;
const int E = 70;

string sigma;
map<char, int> id;
double p[100];

int n;
int nodes;
int suf[SUML];
int term[SUML];
int trie[SUML][E];
int super[SUML];
int go[SUML][E];
bool fin[SUML];

void init() {
    nodes = 1;
    memset(suf, 0, sizeof(suf));
    memset(term, 0, sizeof(term));
    memset(trie, 0, sizeof(trie));
    memset(super, 0, sizeof(super));
    memset(go, 0, sizeof(go));
    memset(fin, 0, sizeof(fin));
}

void insert(const string& s){
	int pos = 0;
	for(int i = 0; i < (int) s.size(); i++){
		int nxt = id[s[i]];
		if(trie[pos][nxt] == 0){
			trie[pos][nxt] = nodes++;
		}
		pos = trie[pos][nxt];
	}
	term[pos]++;
}

void build(int src=0){
	queue<int> Q;
	Q.emplace(src);
	while(!Q.empty()){
		int u = Q.front(); Q.pop();

		if(term[suf[u]]) super[u] = suf[u];
		else super[u] = super[suf[u]];

        if(term[u] or super[u]) fin[u] = 1;

		// cout << u << endl;
		for(char x : sigma) {
            int c = id[x];
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

    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        init();

        int k; cin >> k;
        string s[k];

        for(int i = 0; i < k; i++) 
            cin >> s[i];

        int n; cin >> n;
        
        sigma.clear();
        for(int i = 0; i < n; i++) {
            char c; cin >> c >> p[i];
            sigma += c;
            id[c] = i;
        }

        for(int i = 0; i < k; i++)
            insert(s[i]);

        build();

        int l; cin >> l;
        double dp[l+1][nodes];

        for(int i = 0; i <= l; i++)
            for(int j = 0; j < nodes; j++)
                dp[i][j] = 0.0;

        dp[0][0] = 1;

        for(int i = 1; i <= l; i++) {
            for(int j = 0; j < nodes; j++) {
                if(fin[j]) continue;
                for(char c : sigma) {
                    int nxt = id[c];
                    int q = go[j][nxt];
                    dp[i][q] += dp[i-1][j] * p[nxt];
                }
            }
        }

        double ans = 0;
        for(int i = 1; i <= l; i++) 
            for(int j = 0; j < nodes; j++) 
                if(fin[j]) ans += dp[i][j];

        cout << "Case #" << tc << ": ";
        cout << setprecision(6) << fixed << 1.0-ans << "\n";
    }

	return 0;
}

