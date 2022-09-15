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

const int maxn = 2e5+5;
const int INF = 1e9;

vi adj[maxn];
vi l(maxn, INF), r(maxn, -INF);
int ind = 1;

void dfs(int v, int p) {
    int children = 0;
    
    for(int to : adj[v]) {
        if(to == p) continue;

        children++;
        dfs(to, v);

        l[v] = min(l[v], l[to]);
        r[v] = max(r[v], r[to]);
    }

    if(children == 0) {
        l[v] = r[v] = ind++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin >> n;

    for(int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;

        adj[a].pb(b);
        adj[b].pb(a);
    }
	
    dfs(0, 0);

    for(int i = 0; i < n; i++) {
        cout << l[i] << " " << r[i] << "\n";
    }
	
	return 0;
}

