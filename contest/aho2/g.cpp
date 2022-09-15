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

const int SUML = 100 + 5;
const int mod = 20090717;
const int E = 26;

int n, m, k;
int nodes = 1;
int suf[SUML];
int term[SUML];
int trie[SUML][E];
int super[SUML];
int go[SUML][E];
vi id[SUML];

void init() {
    for(int i = 0; i < nodes; i++)
        id[i].clear();

    nodes = 1;

    memset(trie, 0, sizeof(trie));
    memset(term, 0, sizeof(term));
    memset(go, 0, sizeof(go));
    memset(suf, 0, sizeof(suf));
    memset(super, 0, sizeof(super));
}

void insert(const string& s, int j) {
    int pos = 0;
    for(int i = 0; i < (int) s.size(); i++) {
        int nxt = s[i]-'a';
        if(trie[pos][nxt] == 0) {
            trie[pos][nxt] = nodes++;
        }
        pos = trie[pos][nxt];
    }
    term[pos]++;
    id[pos].pb(j);
}

void build(int src=0) {
    queue<int> Q;
    Q.emplace(src);
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();

        if(term[suf[u]]) super[u] = suf[u];
        else super[u] = super[suf[u]];

        for(int c = 0; c < E; c++) {
            if(trie[u][c]) {
                int v = trie[u][c];
                Q.emplace(v);

                go[u][c] = trie[u][c];
                suf[v] = u == 0 ? 0 : go[suf[u]][c];
            }
            else {
                go[u][c] = u == 0 ? 0 : go[suf[u]][c];
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        cin >> n >> m >> k;

        init();

        for(int i = 0; i < m; i++) {
            string s; cin >> s;
            insert(s, i);
        }

        build();

        int dp[n+1][nodes][1 << m];
        memset(dp, -1, sizeof(dp));
        
        dp[0][0][0] = 1;

        for(int ind = 0; ind < n; ind++) {
            for(int pos = 0; pos < nodes; pos++) {
                for(int mask = 0; mask < (1 << m); mask++) {
                    if(dp[ind][pos][mask] == -1) continue;

                    for(int c = 0; c < E; c++) {
                        int to = go[pos][c];
                        int n_mask = mask;
                        
                        int tmp = term[to] ? to : super[to];
                        while(tmp) {
                            for(int p : id[tmp])
                                n_mask |= (1 << p);
                            tmp = super[tmp];
                        }

                        if(dp[ind+1][to][n_mask] == -1) dp[ind+1][to][n_mask] = dp[ind][pos][mask];
                        else dp[ind+1][to][n_mask] = (dp[ind+1][to][n_mask] + dp[ind][pos][mask])%mod;
                    }
                }
            }
        }

        ll ans = 0;
        for(int pos = 0; pos < nodes; pos++) {
            for(int mask = 0; mask < (1 << m); mask++) {
                if(dp[n][pos][mask] == -1) continue;

                int cnt = 0;
                for(int i = 0; i < m; i++) 
                    cnt += ((mask >> i)&1);
                if(cnt >= k) ans = (ans+dp[n][pos][mask])%mod;
            }
        }

        cout << ans << "\n";
    }
	
    return 0;
}
