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

int n, m, q;

vii adj[maxn]; // adjacency list of graph
bool isBridge[maxn];

vector<bool> vis;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    vis[v] = true;
    tin[v] = low[v] = timer++;
    for (auto e : adj[v]) {
        int to = e.first, id = e.second;
        if (to == p) continue;
        if (vis[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                isBridge[id] = true;
        }
    }
}

void find_bridges() {
    timer = 0;
    vis.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!vis[i])
            dfs(i);
    }
}

// BUILD TREE

vi idv;
vector<vi> tree;

void assign_id(int v, int ind) {
    idv[v] = ind;
    for(auto e : adj[v]) {
        int to = e.first, id = e.second;
        if(idv[to] != -1 or isBridge[id]) continue;

        assign_id(to, ind);
    }
}

vii edges;

void build_tree() {
    idv.clear(); idv.resize(n, -1);
    
    int ind = 0;
    for(int i = 0; i < n; i++) {
        if(idv[i] == -1) {
            assign_id(i, ind);
            ind++;
        }
    }

    tree.clear(); tree.resize(ind);

    //for(int i = 0; i < n; i++) {
        //for(auto e : adj[i]) {
            //int to = e.first, id = e.second;

            //if(isBridge[id] and idv[i] != idv[to]) {
                //tree[idv[i]].pb(idv[to]);
            //}
        //}
    //}

    for(int i = 0; i < m; i++) {
        int x = edges[i].first, y = edges[i].second;

        if(isBridge[i] and idv[x] != idv[y]) {
            tree[idv[x]].pb(idv[y]);
            tree[idv[y]].pb(idv[x]);
        }
    }

}

const int LOGN = 20;

int st[maxn], fin[maxn];
int p[maxn][LOGN];

int x = 0;
int cc[maxn];

void dfs_tree(int v, int par) {
    cc[v] = x;
    st[v] = timer++;

    p[v][0] = par;

    for(int i = 1; i < LOGN; i++) {
        p[v][i] = p[p[v][i-1]][i-1];
    }

    for(int to : tree[v]) {
        if(to == par) continue;
        dfs_tree(to, v);
    }

    fin[v] = timer++;
}

bool is_parent(int u, int v) {
    if(st[u] <= st[v] and fin[v] <= fin[u])
        return true;
    return false;
}

int lca(int u, int v) {
    if(is_parent(u, v)) return u;
    if(is_parent(v, u)) return v;

    for(int i = LOGN-1; i >= 0; i--) {
        if(!is_parent(p[u][i], v)) 
            u = p[u][i];
    }

    return p[u][0];
}

int ls[maxn], lf[maxn], lp[maxn];
bool cmp = true;

void dfs_tree2(int u, int par) {
    for(int to : tree[u]) {
        if(to == par) continue;
        dfs_tree2(to, u);
        ls[u] += ls[to];
        lf[u] += lf[to];
        lp[u] += lp[to];
    }

    if((ls[u] - lp[u] > 0) and (lf[u] - lp[u] > 0)) cmp = false;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> q;

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb({v, i});
        adj[v].pb({u, i});
        edges.pb({u, v});
    }

    find_bridges();
    build_tree();

    int k = tree.size();

    vi roots;

    for(int i = 0; i < k; i++) {
        if(!cc[i]) { 
            x++;
            roots.pb(i);
            dfs_tree(i, i);
        }
    }

    timer = 0;


    //for(int i = 0; i < k; i++) {
        //cout << i  << ": ";
        //for(int to : tree[i]) cout << to << " ";
        //cout << endl;
    //}

    while(q--) {
        int u, v; cin >> u >> v;
        u--; v--;
        u = idv[u]; v = idv[v];

        if(u == v) continue;
        if(cc[u] != cc[v]) {
            cmp = 0;
            break;
        }

        int puv = lca(u, v);

        lp[puv]++;
        ls[u]++;
        lf[v]++;
    }

    for(int v : roots)
        dfs_tree2(v, v);

    //for(int i = 0; i < k; i++) {
        //cout << lp[i] << " " << ls[i] << " " << lf[i] << "\n";
    //}
    cout << (cmp ? "Yes\n" : "No\n");
	
    return 0;
}


