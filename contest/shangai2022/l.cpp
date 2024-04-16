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

const ll mod = 998244353;
const int E = 26;

struct AC {
    int nodes;
    vector<vi> go;
    vi suf, term, super, val, h;

    AC(): nodes(0) {node();}

    int node() {
        go.emplace_back(E, 0);
        suf.emplace_back(0);
        term.emplace_back(0);
        super.emplace_back(0);
        val.emplace_back(0);
        h.emplace_back(0);

        return nodes++;
    }

    void insert(const string& s, int v) {
        int pos = 0;

        for(int i = 0; i < (int) s.size(); i++) {
            int nxt = s[i]-'a';

            if(go[pos][nxt] == 0)
                go[pos][nxt] = node();

            h[go[pos][nxt]] = h[pos] + 1;

            pos = go[pos][nxt];
        }

        term[pos]++;
        val[pos] = v;
    }

    void build(int src=0) {
        queue<int> Q;
        Q.emplace(src);
        while(!Q.empty()) {
            int u = Q.front(); Q.pop();

            if(term[suf[u]]) super[u] = suf[u];
            else super[u] = super[suf[u]];

            for(int c = 0; c < E; c++) {
                if(go[u][c]) {
                    int v = go[u][c];
                    Q.emplace(v);

                    suf[v] = u == 0 ? 0 : go[suf[u]][c];
                }
                else {
                    go[u][c] = u == 0 ? 0 : go[suf[u]][c];
                }
            }
        }
    }

    void clear() {
        go.clear();
        suf.clear();
        term.clear();
        super.clear();

        nodes = 0;
        node();
    }
};


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s; cin >> s;
    s = "." + s;

    int n = s.size();

    AC aho;
    int m; cin >> m;

    for(int i = 0; i < m; i++) {
        string t; cin >> t;
        int v; cin >> v;
        aho.insert(t, v);
    }

    aho.build(0);

    ll dp[n];

    dp[0] = 1;

    auto sum =[&](ll a, ll b) {
        return (a+b) % mod;
    };

    auto mul = [&] (ll a, ll b) {
        return (a * b) % mod;
    };

    int pos = 0;
    for(int i = 1; i < n; i++) {
        dp[i] = dp[i-1];

        int nxt = s[i] - 'a';
        pos = aho.go[pos][nxt];

        int curr = pos;

        while(curr) {
            dp[i] = sum(dp[i], mul(dp[i-aho.h[curr]], aho.val[curr]));
            curr = aho.super[curr];
        }
        cout << dp[i] << " ";
    }


	
    return 0;
}


