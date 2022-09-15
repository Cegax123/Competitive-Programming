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

const int maxn = 3e5 + 5;

int n;
vi adj[maxn];
int dele[maxn], infected[maxn];

void dfs1(int u, int p = -1) {
    dele[u] = 1;
    for(int to : adj[u]) {
        if(to == p) continue;
        dfs1(to, u);

        dele[u] += dele[to];
    }
}

void dfs2(int u, int p = -1) {
    infected[u] = 0;
    int child = 0;

    for(int to : adj[u]) {
        if(to == p) continue;
        dfs2(to, u);
        child++;
    }

    if(child == 0) return;

    if(child == 1) {
        for(int to : adj[u]) {
            if(to == p) continue;
            infected[u] = dele[to];
        }
    }
    else {
        int l = -1, r = -1;
        
        for(int to : adj[u]) {
            if(to == p) continue;
            if(l == -1) l = to;
            else r = to;
        }

        infected[u] = max(infected[l] + dele[r], dele[l] + infected[r]);
    }   
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

        dfs1(1);   

        for(int i = 1; i <= n; i++)
            dele[i]--;

        dfs2(1);
        cout << infected[1] << "\n";

        for(int i = 1; i <= n; i++)
            adj[i].clear();
    }
	
    return 0;
}


