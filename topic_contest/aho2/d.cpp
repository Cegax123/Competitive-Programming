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
const int E = 26;

int nodes = 1;
int suf[SUML];
int term[SUML];
int trie[SUML][E];
int super[SUML];
int go[SUML][E];
ll val[SUML];

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

        if(term[u]) val[u] = (ll) term[u] + val[super[u]];

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

const int maxn = 1e5+5;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n; cin >> n;

    int qu[n][E];
    memset(qu, 0, sizeof(qu));

    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        for(int j = 0; j < k; j++) {
            int u; cin >> u;
            char x; cin >> x;
            
            u--;
            qu[i][x-'a'] = u;
        }
    }

    int m; cin >> m;

    for(int i = 0; i < m; i++) {
        string s; cin >> s;
        insert(s);
    }

    build();

    ll ans = 0;
    
    queue<ii> q;
    q.push({0, 0});

    while(!q.empty()) {
        int u = q.front().first, pos = q.front().second; q.pop();
        ans += val[term[pos] ? pos : super[pos]];

        for(int c = 0; c < E; c++) {
            if(qu[u][c]) 
                q.push({qu[u][c], go[pos][c]});
        }
    }

    cout << ans << "\n";

    return 0;
}

