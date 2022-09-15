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

const int E = 26;

struct AC {
    int nodes;
    vector<vi> go;
    vi suf, term, super, h;

    AC(): nodes(0) {node();}

    int node() {
        go.emplace_back(E, 0);
        suf.emplace_back(0);
        term.emplace_back(0);
        super.emplace_back(0);
        h.emplace_back(0);

        return nodes++;
    }

    void insert(const string& s) {
        int pos = 0;

        for(int i = 0; i < (int) s.size(); i++) {
            int nxt = s[i]-'a';

            if(go[pos][nxt] == 0) {
                go[pos][nxt] = node();
                h[go[pos][nxt]] = h[pos] + 1;
            }

            pos = go[pos][nxt];
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
    int n; cin >> n;
    set<string> temp;

    for(int i = 0; i < n; i++) {
        string a; cin >> a;
        temp.insert(a);
    }

    vector<string> s;
    for(const string& a : temp)
        s.pb(a);

    n = s.size();

    AC aho;

    for(int i = 0; i < n; i++) 
        aho.insert(s[i]);

    aho.build();
    int ans = 0;

    for(int i = 0; i < n; i++) {
        int k = s[i].size();
        int dp[k+1];
        int pos = 0;

        dp[0] = 1;

        for(int j = 1; j <= k; j++) {
            dp[j] = 0;

            int nxt = s[i][j-1]-'a';
            pos = aho.go[pos][nxt];

            int temp = aho.term[pos] ? pos : aho.super[pos];
            if(j == k) temp = aho.super[pos];

            while(temp) {
                if(dp[j-aho.h[temp]]) dp[j] = 1;
                temp = aho.super[temp];
            }
        }


        if(!dp[k]) ans++;
    }

    cout << ans << "\n";
	
    return 0;
}


