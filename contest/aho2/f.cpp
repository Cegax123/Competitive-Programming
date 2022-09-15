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

const int SUML = 12 * 50 + 5;
const int E = 26;

int n;
int nodes = 1;
int suf[SUML];
int term[SUML];
int trie[SUML][E];
int super[SUML];
int go[SUML][E];
int ind[SUML];

void insert(const string& s, int j) {
    int pos = 0;
    for(int i = 0; i < (int) s.size(); i++) {
        int nxt = s[i]-'A';
        if(trie[pos][nxt] == 0) {
            trie[pos][nxt] = nodes++;
        }
        pos = trie[pos][nxt];
    }
    term[pos]++;
    ind[pos] = j;
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

int get_next_mask(int mask, int to) {
    int n_mask = mask;
    int tmp = term[to] ? to : super[to];

    while(tmp) {
        n_mask |= (1 << ind[tmp]);
        tmp = super[tmp];
    }

    return n_mask;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n;

    set<string> s;

    for(int i = 0; i < n; i++) {
        string x; cin >> x;
        s.insert(x);
    }

    int cnt = 0;

    for(string x : s) {
        insert(x, cnt);
        cnt++;
    }

    n = cnt;

    build();

    int dp[1 << n][nodes];
    memset(dp, -1, sizeof(dp));

    dp[0][0] = 0;

    queue<ii> q;
    q.push({0, 0});

    while(!q.empty()) {
        int mask = q.front().first, v = q.front().second; q.pop();

        for(int c = 0; c < E; c++) {
            int to = go[v][c];
            int n_mask = get_next_mask(mask, to);

            if(dp[n_mask][to] == -1) {
                dp[n_mask][to] = dp[mask][v]+1;
                q.push({n_mask, to});
            }
        }
    }

    const int INF = -1;

    int ans = INF;

    for(int i = 0; i < nodes; i++) {
        if(dp[(1 << n)-1][i] == -1) continue;
        if(ans == -1) ans = dp[(1 << n)-1][i];
        ans = min(ans, dp[(1 << n)-1][i]);
    }

    vii pos[ans+1];

    bool cmp[1 << n][nodes];
    memset(cmp, 0, sizeof(cmp));

    for(int mask = 0; mask < (1 << n); mask++) {
        for(int v = 0; v < nodes; v++) {
            if(dp[mask][v] == -1 or dp[mask][v] > ans) continue;

            pos[dp[mask][v]].pb({mask, v});
            if(dp[mask][v] == ans and mask == (1 << n)-1) cmp[mask][v] = 1;
        }
    }

    for(int i = ans-1; i >= 0; i--) {
        for(auto x : pos[i]) {
            int mask = x.first, v = x.second;

            for(int c = 0; c < E; c++) {
                int to = go[v][c];
                int n_mask = get_next_mask(mask, to);

                if(dp[mask][v] + 1 == dp[n_mask][to]) cmp[mask][v] |= cmp[n_mask][to];
            }
        }
    }

    // for(int i = 0; i < (1 << n); i++) {
    //     for(int j = 0; j < nodes; j++) {
    //         cout << cmp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    int mask = 0, v = 0;
    int x = 0;
    string word;

    for(int i = 0; i < ans; i++) {
        for(int c = 0; c < E; c++) {
            int to = go[v][c];
            int n_mask = get_next_mask(mask, to);

            if(cmp[n_mask][to] and dp[n_mask][to] == x+1) {
                word += 'A'+c;
                v = to;
                mask = n_mask;
                x++;
                break;
            }
        }
    }

    cout << word << "\n";
    
    return 0;
}

