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

vi adj[maxn];
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
bool marked[maxn];
const int INF = (int) 1e9;
int ans;

void get(int v, int p) {
    if(marked[v]) {
        for(int to : adj_vt[v]) {
            if(to == p) continue;

            get(to, v);

            if(marked[to]) {
                if(h[v]+1 == h[to]) ans = -INF;
                else ans++;
            }
            else if(cnt[to]) ans++;
        }
    }
    else {
        vi tmp;
        for(int to : adj_vt[v]) {
            if(to == p) continue;

            get(to, v);
            
            if(cnt[to]) tmp.pb(cnt[to]);
        }

        if((int) tmp.size() >= 2) ans++;
        else if((int) tmp.size() == 1) cnt[v] = tmp[0];
    }
}

void solve(vi v) {
    ans = 0;
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
        marked[x] = 0;
    }


    for(int x: sv) {
        cnt[x] = 1;
        marked[x] = 1;
    }

    stack<int> st;
    st.push(v[0]);

    for(int i = 1; i < (int) v.size(); i++) {
        while(!is_ancestor(st.top(), v[i])) st.pop();

        adj_vt[st.top()].pb(v[i]);
        adj_vt[v[i]].pb(st.top());

        st.push(v[i]);
    }

    //for(int x : v) {
        //cout << x << ": ";
        //for(int y : adj_vt[x]) {
            //cout << y << " ";
        //}
        //cout << endl;
    //}

    get(v[0], -1);

    if(ans < 0) cout << -1 << "\n";
    else cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;

    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(0);

    int q; cin >> q;
    while(q--) {
        int k; cin >> k;
        vi a(k);

        for(int i = 0; i < k; i++) {
            cin >> a[i];
            a[i]--;
        }

        solve(a);
    }
	
    return 0;
}


