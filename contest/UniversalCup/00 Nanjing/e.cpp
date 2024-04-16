
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

const int maxn = 1e5 + 5;
const int LOGN = 20;

vector<vi> adj;
vi a;

int par[maxn][LOGN];
int timer;
vi st, fin, h;

void dfs(int v, int p=-1) {
    if(p == -1) par[v][0] = v;
    else par[v][0] = p;

    if(p == -1) h[v] = -1;
    else h[v] = h[p]+1;

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

bool is_parent(int u, int v) {
    return st[u] <= st[v] and fin[v] <= fin[u];
}

int lca(int u, int v) {
    if(is_parent(u, v)) return u;
    if(is_parent(v, u)) return v;

    for(int i = LOGN-1; i >= 0; i--) {
        if(!is_parent(par[u][i], v)) u = par[u][i];
    }
    return par[u][0];
}

int t[4 * maxn];

void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = a[tl];
    }
    else {
        int tm = (tl + tr) >> 1;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm+1, tr);
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if(tr < l or r < tl) return (int) 1e9+5;
    if(tl == l and tr == r) return t[v];
    else {
        int tm = (tl + tr) >> 1;
        return min(query(v * 2, tl, tm, l, min(r, tm)),
                    query(v * 2 + 1, tm+1, tr, max(tm+1, l), r));
    }
}

int n;
vector<vi> adj_vt;
vi p_vt;
int D;

ll f(int v) {
    ll ans = query(1, 0, n-1, D-h[v], D-(h[p_vt[v]]+1));
    ll sum = 0;
    
    for(int to : adj_vt[v]) {
        sum += f(to);
    }

    if(adj_vt[v].empty()) return ans;
    return min(ans, sum);
}

ll calc(vector<int> s) {
    if(s.empty()) return 0;

    sort(all(s), [&](int x, int y) {
            return st[x] < st[y];
            });

    int k = s.size();

    for(int i = 0; i < k-1; i++) {
        s.pb(lca(s[i], s[i+1]));
    }

    s.pb(0);


    sort(all(s), [&](int x, int y) {
            return st[x] < st[y];
            });

    s.erase(unique(all(s)), s.end());


    bool cmp = 1;

    for(int i = 0; i < (int) s.size()-1; i++) {
        if(s[i] == s[i+1]) cmp = 0;
    }

    assert(cmp);

    for(int x : s) {
        if(x < (int) adj_vt.size()) adj_vt[x].clear();
    }

    stack<int> q;
    q.push(s[0]);
    
    for(int i = 1; i < (int) s.size(); i++) {
        while(!is_parent(q.top(), s[i])) q.pop();


        adj_vt[q.top()].pb(s[i]);

        p_vt[s[i]] = q.top();

        q.push(s[i]);
    }

    //for(int i = 0; i < (int) s.size(); i++) {
        //cout << s[i] << ": ";
        //for(int x : adj_vt[s[i]]) cout << x << " ";
        //cout << endl;
    //}

    //cout << "===\n";

    //cout << f(s[1]) << endl;

    //return 0ll;

    return f(s[1]);
}

void solve() {
    cin >> n;

    adj_vt.clear(); adj_vt.resize(n+1);
    p_vt.clear(); p_vt.resize(n+1);

    adj.clear(); adj.resize(n+1);
    a.clear(); a.resize(n+1);

    st.clear(); st.resize(n+1);
    fin.clear(); fin.resize(n+1);
    h.clear(); h.resize(n+1);
    
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    adj[0].pb(1);
    adj[1].pb(0);

    timer = 0;

    dfs(0);
    build(1, 0, n-1);

    vector<vi> queries(n);

    for(int i = 1; i <= n; i++) {
        queries[h[i]].pb(i);
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        D = i;
        ans += calc(queries[i]);
    }

    cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        solve();
    }

	
    return 0;
}



