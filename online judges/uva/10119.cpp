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

int n, m;

vector<vi> adj;
vi tin, low;
int timer;
vector<bool> vis, isArticulation;

void dfs(int v, int p = -1) {
    vis[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (vis[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
                isArticulation[v] = 1;
            ++children;
        }
    }
    if(p == -1 && children > 1)
        isArticulation[v] = 1;
}

void find_cutpoints() {
    for (int i = 0; i < n; ++i) {
        if (!vis[i])
            dfs (i);
    }
}

void init() {
    adj.clear(); adj.resize(n);
    tin.clear(); tin.resize(n, -1);
    low.clear(); low.resize(n, -1);
    vis.clear(); vis.resize(n, false);
    isArticulation.clear(); isArticulation.resize(n, 0);

    timer = 0;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
    int tc = 1;
    while(cin >> n and n) {
        if(tc > 1) cout << "\n";

        init();

        map<string, int> id;
        vector<string> names;

        for(int i = 0; i < n; i++) {
            string city; cin >> city;

            id[city] = i;
            names.pb(city);
        }

        cin >> m;

        for(int i = 0; i < m; i++) {
            string city1, city2; cin >> city1 >> city2;

            int u = id[city1], v = id[city2];

            adj[u].pb(v);
            adj[v].pb(u);
        }

        find_cutpoints();

        vector<string> ans;
        for(int i = 0; i < n; i++) {
            if(isArticulation[i]) ans.pb(names[i]);
        }

        sort(all(ans));

        cout << "City map #" << tc << ": " << ans.size() << " camera(s) found\n";

        for(string s : ans) 
            cout << s << "\n";

        tc++;
    }
	
	return 0;
}

