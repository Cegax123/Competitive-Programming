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

ii par[maxn];
bool marked[maxn], is_blue[maxn];
bool vis_edge[maxn];
int n, m;
vii adj[maxn];
int c[maxn];
int cnt;
ii edge;
int id_edge;

void init() {
    cnt = 0;

    edge = {-1, -1};

    for(int i = 0; i < n; i++) {
        par[i] = {-1, -1};
        is_blue[i] = marked[i] = 0;
        adj[i].clear();
    }

    for(int i = 0; i < m; i++) {
        c[i] = 0;
        vis_edge[i] = 0;
    }
}

void dfs(int u, int p = -1) {
    marked[u] = 1;

    for(auto e : adj[u]) {
        int to = e.first, id = e.second;
        if(to == p or vis_edge[id]) continue;

        vis_edge[id] = 1;
        if(marked[to]) {
            if(cnt == 2) {
                edge = {to, u};
                id_edge = id;
            }
            else {
                cnt++;
                c[id] = 1;
                is_blue[to] = is_blue[u] = 1;
            }
            continue;
        }
        par[to] = {u, id};
        dfs(to, u);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        init();

        for(int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            u--; v--;
            adj[u].pb({v, i});
            adj[v].pb({u, i});
        }

        dfs(0);

        if(edge.first != -1) {
            if(!is_blue[edge.first] or !is_blue[edge.second]) {
                c[id_edge] = 1;
            }
            else {
                int u = edge.first, v = edge.second;
                bool found = 0;

                if(!is_blue[par[v].first]) {
                    c[par[v].second] = 1;
                    found = 1;
                }

                if(!found) {
                    vii pat;
                    pat.pb({v, par[v].second});

                    while(par[pat.back().first].first != u) {
                        int x = par[pat.back().first].first;
                        pat.pb({x, par[x].second});
                    }

                    if(!is_blue[pat.back().first]) {
                        c[pat.back().second] = 1;
                        found = 1;
                    }
                }

                if(!found) {
                    c[id_edge] = 1;
                }
            }
        }
        
        for(int i = 0; i < m; i++)
            cout << c[i];
        cout << "\n";
    }

	
    return 0;
}


