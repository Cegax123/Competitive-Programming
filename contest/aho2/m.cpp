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

const int INF = 1e9;
const int SUML = 1000 + 5;
const int E = 4;

int nodes = 1;
int suf[SUML];
int term[SUML];
int trie[SUML][E];
int super[SUML];
int go[SUML][E];

void init() {
    nodes = 1;

    memset(trie, 0, sizeof(trie));
    memset(term, 0, sizeof(term));
    memset(go, 0, sizeof(go));
    memset(suf, 0, sizeof(suf));
    memset(super, 0, sizeof(super));
}

int get_val(char x) {
    if(x == 'A') return 0;
    if(x == 'G') return 1;
    if(x == 'T') return 2;
    return 3;
}

void insert(const string& s) {
    int pos = 0;
    for(int i = 0; i < (int) s.size(); i++) {
        int nxt = get_val(s[i]);
        if(trie[pos][nxt] == 0) {
            trie[pos][nxt] = nodes++;
        }
        pos = trie[pos][nxt];
    }
    term[pos]++;
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
    for(int tc = 1; tc <= t; tc++) {
        int n; cin >> n;

        init();

        for(int i = 0; i < n; i++) {
            string s; cin >> s;
            insert(s);
        }

        build();

        string t; cin >> t;
        int m = t.size();

        int dp[m+1][nodes];
        memset(dp, -1, sizeof(dp));

        dp[0][0] = 0;
        
        for(int pos = 0; pos < m; pos++) {
            for(int st = 0; st < nodes; st++) {
                int tmp = term[st] ? st : super[st];
                if(dp[pos][st] == -1 or tmp) continue;

                for(int c = 0; c < E; c++) {
                    int to = go[st][c];

                    if(dp[pos+1][to] == -1) dp[pos+1][to] = dp[pos][st] + (get_val(t[pos]) != c);
                    dp[pos+1][to] = min(dp[pos+1][to], dp[pos][st] + (get_val(t[pos]) != c));
                }
            }
        }

        int ans = -1;

        for(int st = 0; st < nodes; st++) {
            int tmp = term[st] ? st : super[st];
            if(dp[m][st] == -1 or tmp) continue;
            
            if(ans == -1) ans = dp[m][st];
            ans = min(ans, dp[m][st]);
        }

        cout << "Case " << tc << ": ";
        cout << ans << "\n";
    }

    
    return 0;
}
