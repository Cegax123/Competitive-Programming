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

const int SUML = 1e4 + 5;
const int E = 26;
const int MAXL = 100+5;

int L, n;
ll k;
int nodes = 1;
int suf[SUML];
int term[SUML];
int trie[SUML][E];
int super[SUML];
int go[SUML][E];
bool contain_terminal[SUML];

void insert(const string& s) {
    int pos = 0;
    for(int i = 0; i < (int) s.size(); i++) {
        int nxt = s[i]-'a';
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

        if(super[u] or term[u]) contain_terminal[u] = 1;

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

ll dp[MAXL][SUML];
ll p[MAXL];

ll call(int pos, int u) {
    if(pos == L)
        return dp[pos][u] = contain_terminal[u];

    if(dp[pos][u] != -1)
        return dp[pos][u];

    if(contain_terminal[u]) 
        return dp[pos][u] = p[L-pos];
    
    dp[pos][u] = contain_terminal[u];
    for(int c = 0; c < E; c++) {
        ll res = call(pos+1, go[u][c]);
        if(res >= 0) dp[pos][u] = min(k+1, dp[pos][u] + res);
    }

    return dp[pos][u];
}

string find(ll x, int len) {
    string ans = "";
    for(int i = 0; i < len; i++) {
        ll curr = 0;

        for(int c = 0; c < E; c++) {
            if(x <= p[len-i-1] + curr) {
                ans += 'a'+c;
                break;
            }
            curr += p[len-i-1];
        }

        x -= curr;
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> L >> k >> n;

    p[0] = 1;

    for(int i = 1; i <= L; i++) {
        if((k+27ll)/26ll <= p[i-1]) p[i] = k+1;
        else p[i] = p[i-1] * 26ll;
    }

    for(int i = 0; i < n; i++){
        string s; cin >> s;
        insert(s);
    }

    build(0);

    memset(dp, -1, sizeof(dp));

    ll total = call(0, 0);

    // for(int i = 0; i <= L; i++) {
    //     for(int j = 0; j < nodes; j++)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }
    
    if(total < k) {
        cout << "unnamed baby :(\n";
        return 0;
    }

    string ans = "";

    int pos = 0;
    for(int i = 1; i <= L; i++) {
        if(contain_terminal[pos]) {
            string suf_ans = find(k, L-i+1);
            ans += suf_ans;

            break;
        }

        ll curr = 0;
        for(int c = 0; c < E; c++) {
            int to = go[pos][c];
            if(dp[i][to] == -1) continue;

            if(k <= curr + dp[i][to]) {
                ans += 'a'+c;
                pos = to;
                break;
            }
            curr += dp[i][to];
        }
        k -= curr;
    }

    cout << ans << "\n";
	
    return 0;
}
