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

const int maxn = 4e4+5;
const int LOGN = 20;
const int B = 750;

int n, m;
int a[maxn], st[maxn], en[maxn], T = 0;
int par[maxn][LOGN];
vi adj[maxn], ord;
int cnt[maxn], parity[maxn];
int curr_ans = 0;

void update(int v) {
    parity[v] ^= 1;

    if(parity[v]) {
        if(cnt[a[v]] == 0)
            curr_ans++;
        cnt[a[v]]++;
    }
    else {
        cnt[a[v]]--;
        if(cnt[a[v]] == 0)
            curr_ans--;
    }
}

void dfs(int v, int p = -1) {
    st[v] = T++;
    ord.pb(v);

    if(p == -1) par[v][0] = v;
    else par[v][0] = p;

    for(int i = 1; i < LOGN; i++) 
        par[v][i] = par[par[v][i-1]][i-1];

    for(int to : adj[v]) {
        if(to == p) continue;
        dfs(to, v);
    }

    en[v] = T++;
    ord.pb(v);
}

bool is_parent(int u, int v) {
    return st[u] <= st[v] and en[v] <= en[u];
}

int lca(int u, int v) {
    if(is_parent(u, v))
        return u;
    if(is_parent(v, u))
        return v;

    for(int i = LOGN-1; i >= 0; i--) {
        if(!is_parent(par[u][i], v))
            u = par[u][i];
    }

    return par[u][0];
}

struct Query {
    int l, r, x, id;

    bool operator < (Query other) const {
        return make_pair(l / B, r) < make_pair(other.l / B, other.r);
    }
};

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;

    set<int> tmp;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        tmp.insert(a[i]);
    }

    int id = 0;
    map<int, int> mp;

    for(int x : tmp)
        mp[x] = id++;

    for(int i = 0; i < n; i++)
        a[i] = mp[a[i]];

    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(0);

    vector<Query> queries;

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;

        int p = lca(u, v);

        if(st[u] > st[v])
            swap(u, v);

        if(u == p)
            queries.pb({st[u], st[v], -1, i});
        else 
            queries.pb({en[u], st[v], st[p], i});
    }

    sort(all(queries));
    
    int ans[m];

    int l = 0, r = -1;

    for(Query Q : queries) {
        while(l > Q.l) {
            l--;
            update(ord[l]);
        }
        while(r < Q.r) {
            r++;
            update(ord[r]);
        }
        while(l < Q.l) {
            update(ord[l]);
            l++;
        }
        while(r > Q.r) {
            update(ord[r]);
            r--;
        }

        ans[Q.id] = curr_ans;

        if(Q.x != -1) {
            int v = ord[Q.x];
            parity[v] ^= 1;

            if(parity[v]) {
                if(cnt[a[v]] == 0) ans[Q.id]++;
            }
            else {
                if(cnt[a[v]] == 1) ans[Q.id]--;
            }

            parity[v] ^= 1;
        }
    }

    for(int i = 0; i < m; i++)
        cout << ans[i] << "\n";

    return 0;
}


