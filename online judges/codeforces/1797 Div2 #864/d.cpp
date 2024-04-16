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

ll imp[maxn];
int sz[maxn], fa[maxn];
vi adj[maxn];
set<ii> son[maxn];

void dfs(int u, int p=-1) {
    sz[u] = 1;
    if(p != -1) fa[u] = p;
    else fa[u] = u;
    for(int to : adj[u]) {
        if(to == p) continue;
        dfs(to, u);

        sz[u] += sz[to];

        son[u].insert({-sz[to], to});
        imp[u] += imp[to];
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> imp[i];

    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(0);

    for(int i = 0; i < m; i++) {
        int op; cin >> op;
        int x; cin >> x;
        x--;
        if(op == 1) {
            cout << imp[x] << "\n";
        }
        else {
            if(son[x].empty()) {
                continue;
            }
            int fax = fa[x];
            int sonx = (*son[x].begin()).second;

            son[x].erase({-sz[sonx], sonx});
            son[fax].erase({-sz[x], x});
            
            imp[x] -= imp[sonx];
            imp[sonx] += imp[x];

            sz[x] -= sz[sonx];
            sz[sonx] += sz[x];

            son[sonx].insert({-sz[x], x});
            son[fax].insert({-sz[sonx], sonx});

            fa[sonx] = fax;
            fa[x] = sonx;
        }
    }
	
    return 0;
}


