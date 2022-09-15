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

const int maxn = 5e5+5;
vi adj[maxn];
vii upd[maxn];

struct Query {
    int ans, id, rid;
};

vector<Query> queries[maxn];
int sz[maxn], st[maxn], ft[maxn], ver[maxn];
int T = 0;

void calc_sz(int v, int par) {
    sz[v] = 1, st[v] = T++, ver[st[v]] = v;

    for(auto to : adj[v]) {
        if(to == par) continue;
        calc_sz(to, v);

        sz[v] += sz[to];
    }

    ft[v] = T;
}

set<int> up, down;
void dfs(int v, int par, int keep) {
    int mx = -1, bigChild = -1;
    for(auto to : adj[v]) {
        if(to == par) continue;
        if(sz[to] > mx) {
            mx = sz[to];
            bigChild = to;
        }
    }

    for(auto e : upd[v]) {
        if(e.first == 1)
            up.insert(e.second);
    }

    for(auto to : adj[v]) {
        if(to == par or to == bigChild)  continue;
        dfs(to, v, 0);   
    }

    if(bigChild != -1) 
        dfs(bigChild, v, 1);

    for(auto to : adj[v]) {
        if(to == par or to == bigChild) continue;
        for(int i = st[to]; i < ft[to]; i++) {
            int x = ver[i];
            for(auto e : upd[x]) {
                if(e.first == 2)
                    down.insert(e.second);
            }
        }
    }

    for(auto e : upd[v]) {
        if(e.first == 2) 
            down.insert(e.second);
    }

    for(auto &q : queries[v]) {
        int last1 = -2, last2 = -1;


        auto it = up.upper_bound(q.rid);
        if(it != up.begin()) {
            it--;
            last1 = *it;
        }

        it = down.upper_bound(q.rid);
        if(it != down.begin()) {
            it--;
            last2 = *it;
        }

        q.ans = last1 > last2;
    }

    for(auto e : upd[v])
        if(e.first == 1)
            up.erase(e.second);

    if(keep == 0) {
        down.clear();   
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    
    for(int i = 0; i < n-1; i++) {
        int u,v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int q; cin >> q;
    int ind = 0;
    for(int i = 0; i < q; i++) {
        int t, v; cin >> t >> v;
        v--;
        
        if(t <= 2) upd[v].pb({t, i});
        else queries[v].pb({0, ind++, i});
    }
		
    calc_sz(0, -1);
    dfs(0, -1, 1);

    vi ans(ind);

    for(int i = 0; i < n; i++) {
        for(auto q : queries[i]) {
            ans[q.id] = q.ans;
        }
    }

    for(int i = 0; i < ind; i++) 
        cout << ans[i] << "\n";

	return 0;
}

