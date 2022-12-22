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


const int maxn = 2e5 + 5;
const int LOGN = 20;

int n, d;
vi adj[maxn];
int h[maxn], st[maxn], fin[maxn];
int p[maxn][LOGN];
int T = 0;

void process(int v, int par) {
    if(v) h[v] = h[par] + 1;
    p[v][0] = par;
    
    for(int i = 1; i < LOGN; i++) {
        p[v][i] = p[p[v][i-1]][i-1];
    }

    st[v] = T++;

    for(int to : adj[v]) 
        if(to != par) process(to, v);

    fin[v] = T++;
}

int get_k_parent(int u, int k) {
    for(int i = 0; i < LOGN; i++) {
        if((k >> i)&1) u = p[u][i];
    }
    return u;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> d;
    
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    process(0, 0);

    vector<vector<bool>> marked(2, vector<bool> (n, 0));

    vi pat[2];

    priority_queue<pair<int, ii>> pq;

    int m; cin >> m;

    for(int i = 0; i < m; i++) {
        int v; cin >> v; v--;
        pq.push({h[v], {v, 0}});
    }

    cin >> m;

    for(int i = 0; i < m; i++) {
        int v; cin >> v; v--;
        pq.push({h[v], {v, 1}});
    }

    while(!pq.empty()) {
        auto e = pq.top(); pq.pop();

        int hv = e.first, v = e.second.first, c = e.second.second;

        if(marked[c][v]) continue;

        marked[c][v] = 1;
        pat[c].pb(v);

        int u = get_k_parent(v, d);
        pq.push({h[u], {u, 1-c}});
    }

    auto f = [&](const vector<int>& cam) {
        priority_queue<ii> sq;

        for(int x : cam) {
            sq.push({h[x], x});
        }

        bool vis[n];
        memset(vis, 0, sizeof(vis));

        int ans = 0;

        while(!sq.empty()) {
            int v = sq.top().second; sq.pop();
            if(vis[v]) continue;
            if(v == 0) continue;

            vis[v] = 1;
            ans += 2;
            sq.push({h[p[v][0]], p[v][0]});
        }

        return ans;
    };

    cout << f(pat[0]) + f(pat[1]) << "\n";
	
    return 0;
}


