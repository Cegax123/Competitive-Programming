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

int n;
vi adj[maxn];
int p[maxn];
int sz[maxn];
bool marked[maxn];
int st[maxn], fin[maxn];
int T;

void clear() {
    T = 0;
    for(int i = 0; i <= n; i++) {
        adj[i].clear();
        sz[i] = 0;
        marked[i] = 0;
        st[i] = fin[i] = 0;
    }
}

void dfs(int u, int par) {
    p[u] = par;
    sz[u] = 1;

    st[u] = T++;
    
    for(int to : adj[u]) {
        if(to == par) continue;
        dfs(to, u);
        sz[u] += sz[to];
    }

    fin[u] = T++;
}

bool is_ancestor(int u, int v) {
    if(u >= n or v >= n) return false;
    return st[u] <= st[v] and fin[v] <= fin[u];
}

ll get_ans_1(int v, int p) {
    vector<int> curr;
    int sz = 1;
    
    for(int to : adj[v]) {
        if(to == p or to == 1) continue;

        int obt = get_ans_1(to, v);

        if(v == 0) curr.pb(obt);
        sz += obt;
    }

    if(v) return sz;

    ll ans = 0;

    for(int i = 0; i < (int) curr.size(); i++) {
        ans += curr[i] * 1ll * (sz-curr[i]-1);
    }

    ans /= 2;

    ans += sz-1;

    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n-1; i++) {
            int u, v; cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        dfs(0, 0);

        ll ans = 0;

        // k = 0
        for(int to : adj[0])
            ans += sz[to] * 1ll * (sz[to]-1) / 2;

        cout << ans << " ";

        cout << get_ans_1(0, 0) << " ";

        marked[0] = 1;
        int l = 0, r = 0;

        bool cmp = 1;
        int dir = -1;

        for(int i = 1; i < n; i++) {
            if(!marked[i]) {
                int bef;
                int v = i;
                while(!marked[v]) {
                    marked[v] = 1;
                    bef = v;
                    v = p[v];
                }

                if(l == v) {
                    l = i;
                    if(r == 0 and dir == -1) dir = bef;
                }
                else if(r == v) r = i;
                else cmp = 0;
            }

            if(!cmp) {
                cout << 0 << " ";
                continue;
            }

            if(i+1 < n and marked[i+1]) {
                cout << 0 << " ";
                continue;
            }

            int szl = sz[l] - (is_ancestor(l, i+1) ? sz[i+1] : 0);
            int szr = sz[r];

            if(r == 0) {
                szr -= sz[dir];
                if(!is_ancestor(dir, i+1)) szr -= sz[i+1];
            }
            else szr -= (is_ancestor(r, i+1) ? sz[i+1] : 0);

            cout << szl * 1ll * szr << " ";
        }

        cout << "\n";

        clear();
    }

	
    return 0;
}


