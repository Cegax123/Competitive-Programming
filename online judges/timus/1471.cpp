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

const int maxn = 5e4+5;

vii adj[maxn];
ll d[maxn];
int h[maxn];

void dfs(int v, int p) {
    for(auto e : adj[v]) {
        int to = e.first, w = e.second;
        if(to == p) continue;

        h[to] = h[v]+1;
        d[to] = d[v] + w;
        dfs(to, v);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n-1; i++) {
        int a, b, w; cin >> a >> b >> w;
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }

    dfs(0, 0);
    
    int m; cin >> m;
    while(m--) {
        int a, b;
        
    }
	
	return 0;
}

