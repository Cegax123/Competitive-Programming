#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define all(c) (c).begin(), (c).end()
#define pb push_back 

const int maxn = 2e5 + 5;
const int LOGN = 20;
 
vector<int> adj[maxn];
int c[maxn];
int par[maxn][LOGN];
 
int timer = 0, st[maxn], fin[maxn];
int h[maxn];
 
void dfs(int v, int p=-1) {
    if(p == -1) {
        par[v][0] = v;
        h[v] = 0;
    }
    else {
        par[v][0] = p;
        h[v] = h[p]+1;
    }
 
    st[v] = timer++;
 
    for(int i = 1; i < LOGN; i++) {
        par[v][i] = par[par[v][i-1]][i-1];
    }
 
    for(int to : adj[v]) {
        if(to == p) continue;
        dfs(to, v);
    }
 
    fin[v] = timer++;
}
 
bool is_ancestor(int u, int v) {
    return st[u] <= st[v] and fin[v] <= fin[u];
}
 
int lca(int u, int v) {
    if(is_ancestor(u, v)) return u;
    if(is_ancestor(v, u)) return v;
 
    for(int i = LOGN-1; i >= 0; i--) {
        if(!is_ancestor(par[u][i], v)) {
            u = par[u][i];
        }
    }
 
    return par[u][0];
}

vi adj_vt[maxn];
int cnt[maxn];
long long ans = 0;
int curr;

void dfs_vt(int v, int p = -1) {
    for(int to : adj_vt[v]) if(to != p) {
        dfs_vt(to, v);

        if(c[v] == curr) ans += cnt[to];
        else ans += cnt[v] * 1ll * cnt[to];

        if(c[v] != curr) cnt[v] += cnt[to];
    }

    if(c[v] == curr) cnt[v] = 1;
}

void solve(vi& v) {
    sort(all(v), [&](int x, int y) {
            return st[x] < st[y];
            });
 
    vi sv = v;
 
    int k = v.size();
 
    for(int i = 0; i + 1 < k; i++) {
        v.pb(lca(v[i], v[i+1]));
    }
 
    sort(all(v), [&](int x, int y) {
            return st[x] < st[y];
        });
 
    v.erase(unique(all(v)), v.end());
 
    for(int x : v) {
        adj_vt[x].clear();
        cnt[x] = 0;
    }
 
    stack<int> st;
    st.push(v[0]);
 
    for(int i = 1; i < (int) v.size(); i++) {
        while(!is_ancestor(st.top(), v[i])) st.pop();
 
        adj_vt[st.top()].pb(v[i]);
        adj_vt[v[i]].pb(st.top());
 
        st.push(v[i]);
    }

    dfs_vt(v[0]);
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> col[n];
        for(int i = 0; i < n; i++) {
            cin >> c[i];
            c[i]--;
            col[c[i]].push_back(i);
        }

        for(int i = 0; i < n-1; i++) {
            int u, v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        timer = 0;
        dfs(0);

        ans = 0;

        for(int i = 0; i < n; i++) {
            if(!col[i].empty()) {
                curr = i;
                solve(col[i]);
            }
        }

        cout << ans << "\n";

        for(int i = 0; i < n; i++) col[i].clear();
        for(int i = 0; i < n; i++) adj[i].clear();
    }


    return 0;
}

//917059525
