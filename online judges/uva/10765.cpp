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
vector<bool> isArticulation, vis;
int timer;
vi low, tin;

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
    isArticulation.clear(); isArticulation.resize(n, 0);
    vis.clear(); vis.resize(n, 0);
    low.clear(); low.resize(n, -1);
    tin.clear(); tin.resize(n, -1);
    timer = 0;
}

vector<vi> tree;

void obtain_tree() {
    vis.clear(); vis.resize(n, 0);

    for(int i = 0; i < n; i++) {
        if(
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	while(cin >> n >> m and n and m) {
        init();

        int a, b;
        while(cin >> a >> b and a != -1 and b != -1) {
            adj[a].pb(b);
            adj[b].pb(a);
        }

        find_cutpoints();
    }
	
	return 0;
}

