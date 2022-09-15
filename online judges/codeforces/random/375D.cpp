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

const int maxn = 1e5+5;

int n, m; 
int c[maxn], t[4*maxn];
vi adj[maxn];


void build(int v, int tl, int tr) {
    if(tl == tr) {
        if(tl == 0) t[v] = n;
        else t[v] = 0;

        return;
    }
    else {
        int tm = (tl+tr)/2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);

        t[v] = t[v*2] + t[v*2+1];
    }
}

void update(int v, int tl, int tr, int pos, int x) {
    if(tl == tr and pos == tl) {
        t[v] += x;  
        return;
    }
    else {
        int tm = (tl+tr)/2;

        if(pos <= tm) update(v*2, tl, tm, pos, x);
        else update(v*2+1, tm+1, tr, pos, x);

        t[v] = t[v*2]+t[v*2+1];
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if(l > tr or r < tl)
        return 0;
    if(l == tl and r == tr) {
        return t[v];
    }
    else {
        int tm = (tl+tr)/2;
        return query(v*2, tl, tm, l, min(r, tm)) + query(v*2+1, tm+1, tr, max(tm+1, l), r); 
    }
}

int sz[maxn], st[maxn], ft[maxn], ver[maxn];
int T = 0;

void calc_sz(int v, int p) {
    sz[v] = 1, st[v] = T++, ver[st[v]] = v;

    for(auto to : adj[v]) {
        if(to == p) continue;
        calc_sz(to, v);
        sz[v] += sz[to];
    }

    ft[v] = T;
}

struct Query {
    int k, ans, id;
};

vector<Query> queries[maxn];
int fr[maxn];

void dfs(int v, int p, bool keep) {
    int mx = -1, bigChild = -1;
    for(auto to : adj[v]) {
        if(to == p) continue;
        if(sz[to] > mx) {
            mx = sz[to];
            bigChild = to;
        }
    }

    for(auto to : adj[v]) {
        if(to == p or to == bigChild) {
            continue;
        }
        dfs(to, v, 0);
    }

    if(bigChild != -1) 
        dfs(bigChild, v, 1);



    update(1, 0, n, fr[c[v]], -1);
    fr[c[v]]++;
    update(1, 0, n, fr[c[v]], 1);

    for(auto to : adj[v]) {
        if(to == p or to == bigChild) continue;
        for(int i = st[to]; i < ft[to]; i++) {
            int x = ver[i];
            update(1, 0, n, fr[c[x]], -1);
            fr[c[x]]++;
            update(1, 0, n, fr[c[x]], 1);
        }
    }

    for(auto& q : queries[v]) {
        q.ans = query(1, 0, n, q.k, n);
    }

    if(keep == 0) {
        for(int i = st[v]; i < ft[v]; i++) {
            int x = ver[i];
            update(1, 0, n, fr[c[x]], -1);
            fr[c[x]]--;
            update(1, 0, n, fr[c[x]], 1);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
	
    for(int i = 0; i < n; i++)
        cin >> c[i];

    memset(fr, 0, sizeof(fr));
    
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for(int i = 0; i < m; i++) {
        int v, k; cin >> v >> k;
        v--;

        queries[v].pb({k,0,i});
    }

    build(1, 0, n);


    calc_sz(0, -1);
    dfs(0, -1, 0);

    vi res(m);
    for(int i = 0; i < n; i++) {
        for(auto q : queries[i]) {
            res[q.id] = q.ans;
        }
    }

    for(int i = 0; i < m; i++)
        cout << res[i] << "\n";
	
	return 0;
}
