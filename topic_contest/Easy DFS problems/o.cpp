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

const int maxn = 105;
bool vis[maxn];
vector<int> adj[maxn];
int g[maxn][maxn];
bool reachable[maxn];

int blocked;

void dfs(int v) {
    if(v == blocked) return;
    vis[v] = true;

    for(int to : adj[v]) {
        if(!vis[to]) dfs(to);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        int n; cin >> n;
        for(int i = 0; i < n; i++) adj[i].clear();


        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int x; cin >> x;
                if(x) adj[i].push_back(j);
            }
        }

        memset(vis, 0, sizeof(vis));
        blocked = -1;
        dfs(0);

        for(int i = 0; i < n; i++) {
            reachable[i] = vis[i];
        }

        memset(g, 0, sizeof(g));

        for(int i = 0; i < n; i++) {
            if(!reachable[i]) continue;
            memset(vis, 0, sizeof(vis));
            blocked = i;

            dfs(0);

            for(int j = 0; j < n; j++) {
                if(!vis[j] and reachable[j]) {
                    g[i][j] = 1;
                }
            }
        }
        
        cout << "Case " << tc << ":\n";

        string line = "+" + string(2 * n - 1, '-') + "+";
        cout << line << "\n";
        for(int i = 0; i < n; i++) {
            cout << "|";
            for(int j = 0; j < n; j++) {
                cout << (g[i][j] ? 'Y' : 'N') << "|";
            }
            cout << "\n" << line << "\n";
        }


    }

	
    return 0;
}


