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
 
const int maxn = 50 + 5;
const int maxm = 100 + 5;
 
const int SUML = maxm * 10 + 5;
const int E = 26;
 
int n, m;
int nodes;
int suf[SUML];
int term[SUML];
int trie[SUML][E];
int super[SUML];
int go[SUML][E];
int val[SUML];
int dp[maxn][SUML];
 
string s[maxm];
int h[maxm];
 
void init() {
    nodes = 1;
 
    memset(dp, -1, sizeof(dp));
    memset(trie, 0, sizeof(trie));
    memset(term, 0, sizeof(term));
    memset(go, 0, sizeof(go));
    memset(suf, 0, sizeof(suf));
    memset(super, 0, sizeof(super));
    memset(val, 0, sizeof(val));
}
 
void insert(const string& s, int x) {
    int pos = 0;
    for(int i = 0; i < (int) s.size(); i++) {
        int nxt = s[i]-'a';
        if(trie[pos][nxt] == 0) {
            trie[pos][nxt] = nodes++;
        }
        pos = trie[pos][nxt];
    }
    val[pos] += x;
    term[pos]++;
}
 
void build(int src=0) {
    queue<int> Q;
    Q.emplace(src);
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
 
        if(term[suf[u]]) super[u] = suf[u];
        else super[u] = super[suf[u]];
 
        val[u] += val[super[u]];
 
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
 
int call(int pos, int state) {
    if(pos == n) 
        return dp[pos][state] = val[state];
 
    if(dp[pos][state] != -1)
        return dp[pos][state];
 
    if(state == nodes-1)    
        return dp[pos][state] = max(call(pos+1, state), call(pos+1, 0));
 
    dp[pos][state] = 0;
    for(int c = 0; c < E; c++) 
        dp[pos][state] = max(dp[pos][state], call(pos+1, go[state][c]));
 
    int x = val[term[state] ? state : super[state]];
    dp[pos][state] += x;
 
    return dp[pos][state];
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        n++;
 
        init();
 
        for(int i = 0; i < m; i++) 
            cin >> s[i];
 
        for(int i = 0; i < m; i++)
            cin >> h[i];
 
        for(int i = 0; i < m; i++) 
            insert(s[i], h[i]);
 
        build();
        nodes++;
 
        call(0, nodes-1);
 
        int ans = 0;
        int st = 0;

        for(int i = 1; i <= n; i++) {
            if(dp[i][0] >= ans) {
                ans = dp[i][0];
                st = i;
            }
        }
 
        string word;
        int pos = 0;
 
        for(int i = st; i < n; i++) {
            int curr = -1;
            char x;
 
            for(int c = 0; c < E; c++) {
                int n_pos = go[pos][c];
 
                if(dp[i+1][n_pos] > curr) {
                    curr = dp[i+1][n_pos];
                    x = 'a'+c;
                }
            }
 
            word += x;
            pos = go[pos][x-'a'];
        }
 
        cout << word << "\n";
    }
	
    return 0;
}

