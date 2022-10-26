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

const int maxn = 1e5 + 5;
const int SUML = 1e5 + 5;
const int E = 26;

int n;
string s[maxn];
int nodes;
int suf[SUML];
int term[SUML];
int trie[SUML][E];
int go[SUML][E];
int h[SUML], cnt[SUML], maxA[SUML], deg[SUML], p[SUML];
vector<vi> A;

void init() {
    nodes = 1;

    A.clear(); A.resize(n);
    h[0] = 0;
	memset(trie, 0, sizeof(trie));
	memset(term, 0, sizeof(term));
	memset(go, 0, sizeof(go));
	memset(suf, 0, sizeof(suf));
    memset(cnt, 0, sizeof(cnt));
    memset(maxA, 0, sizeof(maxA));
    memset(deg, 0, sizeof(deg));
}

void insert(const string& s, int ind){
	int pos = 0;
	for(int i = 0; i < (int) s.size(); i++){
        int nxt = s[i] - 'a';
        if(trie[pos][nxt] == 0){
            trie[pos][nxt] = nodes++;
            p[trie[pos][nxt]] = pos;
            h[trie[pos][nxt]] = h[pos]+1;
        }
        pos = trie[pos][nxt];
        cnt[pos]++;
        maxA[pos] = max(maxA[pos], A[ind][i]);
	}
	term[pos]++;
}

void build(int src=0){
	queue<int> Q;
	Q.emplace(src);
	while(!Q.empty()){
		int u = Q.front(); Q.pop();

		// cout << u << endl;
		for(int c = 0; c < E; c++){
			if(trie[u][c]){
                deg[u]++;

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

    ifstream in;
    in.open("exciting.in");

    int t; in >> t;
    while(t--) {
        in >> n;
        
        init();
    
        for(int i = 0; i < n; i++) 
            in >> s[i];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < (int) s[i].size(); j++) {
                int x; in >> x;
                A[i].pb(x);
            }
        }

        for(int i = 0; i < n; i++)
            insert(s[i], i);

        build();

        ll ans = 0;

        queue<int> q;
        for(int i = 0; i < nodes; i++) 
            if(deg[i] == 0) {
                q.push(i);
            }

        while(!q.empty()) {
            int u = q.front(); q.pop();

            ans = max(ans, cnt[u] * 1ll * maxA[u] * h[u]);

            if(u == 0) continue;

            maxA[suf[u]] = max(maxA[suf[u]], maxA[u]);

            deg[p[u]]--;
            if(deg[p[u]] == 0) q.push(p[u]);
        }

        cout << ans << "\n";
    }

	
	return 0;
}
