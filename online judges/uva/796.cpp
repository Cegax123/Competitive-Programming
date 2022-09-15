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

int n;

vector<vii> adj;
vi tin, low;
vector<bool> vis;
int timer;

struct Edge {
    int v, u, id;
    bool isBridge = 0;
};

vector<Edge> edges;

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
                edges[id].isBridge = 1;
        }
    }
}

void find_bridges() {
    for (int i = 0; i < n; ++i) {
        if (!vis[i])
            dfs(i);
    }
}

void init() {
    adj.clear(); adj.resize(n);
    tin.clear(); tin.resize(n, -1);
    low.clear(); low.resize(n, -1);
    vis.clear(); vis.resize(n, 0);
    edges.clear();

    timer = 0;
}

int get_k(string s) {
    int k = 0;

    for(int i = 1; i < (int) s.size()-1; i++) {
        k = k * 10 + (s[i]-'0');
    }

    return k;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
    while(cin >> n) {
        if(n == 0) {
            cout << "0 critical links\n\n";
            continue;
        }

        init();

        int ind = 0;
        for(int i = 0; i < n; i++) {
            int v; cin >> v;
            string s; cin >> s;

            int k = get_k(s);
            
            for(int j = 0; j < k; j++) {
                int u; cin >> u;
                if(v < u) {
                    adj[v].pb({u, ind});
                    adj[u].pb({v, ind});

                    Edge tmp;
                    tmp.v = v, tmp.u = u, tmp.id = ind;

                    edges.pb(tmp);

                    ind++;
                }
            }
        }

        find_bridges();

        vii ans;
        for(int i = 0; i < (int) edges.size(); i++) {
            if(edges[i].isBridge) {
                ans.pb({edges[i].v, edges[i].u});
            }
        }

        sort(all(ans));

        cout << ans.size() << " critical links\n";
        for(int i = 0; i < (int) ans.size(); i++) {
            cout << ans[i].first << " - " << ans[i].second << "\n";
        }

        cout << "\n";
    }
	
	
	return 0;
}

