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

vector<vi> adj;

vi val, comp, z, cont;
int timer, ncomps, ind;
vi roots;
vector<vi> adj_scc;

const int maxn = 1e5 + 5;

void init(int n) {
    adj.clear(); adj.resize(n);
    timer = ncomps = ind = 0;

    val.clear(); val.assign(n, 0);
    comp.clear(); comp.assign(n, -1);

    z.clear();
    roots.clear(); roots.resize(n);
}

int tarjan(int j) {
    int low = val[j] = ++timer, x; z.pb(j);

    for(int to : adj[j]) {
        if(comp[to] < 0) {
            low = min(low, val[to] ?: tarjan(to));
        }
    }

    if(low == val[j]) {
        do {
            x = z.back(); z.pop_back();
            comp[x] = ncomps;
            cont.pb(x);
        } while(x != j);

        // Procesar scc
        for(int v : cont) {
            roots[v] = ind;
        }
        ind++;

        cont.clear();
        ncomps++;
    }

    return val[j] = low;
}

int in[maxn];

void build_scc_dag(int n) {
    adj_scc.clear(); adj_scc.resize(ncomps);

    for(int i = 0; i < n; i++) {
        for(int to : adj[i]) if(roots[i] != roots[to]) {
            adj_scc[roots[i]].pb(roots[to]);
            in[roots[to]]++;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m; cin >> n >> m;
    init(n);
    int v[n];
    for(int i = 0; i < n; i++) cin >> v[i];

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
    }

    for(int i = 0; i < n; i++) {
        if(comp[i] < 0) tarjan(i);
    }

    build_scc_dag(n);

    ll v_scc[ncomps];
    memset(v_scc, 0, sizeof(v_scc));

    for(int i = 0; i < n; i++) 
        v_scc[roots[i]] += v[i];
    
    queue<int> q;

    ll dp[ncomps];
    memset(dp, 0, sizeof(dp));

    for(int i = 0; i < ncomps; i++) {
        if(in[i] == 0) q.push(i);
    }

    ll ans = 0;

    while(!q.empty()) {
        int u = q.front(); q.pop();

        dp[u] += v_scc[u];
        ans = max(ans, dp[u]);

        for(int to : adj_scc[u]) {
            dp[to] = max(dp[to], dp[u]);
            in[to]--;
            if(in[to] == 0) q.push(to);
        }
    }

    cout << ans << "\n";
	
    return 0;
}


