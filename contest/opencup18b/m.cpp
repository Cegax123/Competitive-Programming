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

const int maxn = 1000+5;

vi adj[maxn];
int ans[maxn];
bool vis[maxn];
int ind = 1;

void dfs(int v) {
    vis[v] = 1;
    ans[v] = ind;

    for(int to : adj[v]) {
        if(vis[to]) continue;
        dfs(to);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m; cin >> n >> m;

    int f[n+1][m+1];
    memset(f, 0, sizeof(f));

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> f[i][j];

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(f[i][j] == f[i-1][j-1] + 1 and f[i][j] != f[i-1][j] and f[i][j] != f[i][j-1]) {
                adj[i].pb(j+n);
                adj[j+n].pb(i);
            }
        }
    }

    for(int i = 1; i <= n + m; i++) {
        if(!vis[i]) {
            dfs(i);
            ind++;
        }
    }

    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";

    cout << "\n";

    for(int i = n+1; i <= n+m; i++)
        cout << ans[i] << " ";
	
    return 0;
}


