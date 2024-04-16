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

vi adj[maxn];
vi curr;
bool vis[maxn];

void dfs(int v) {
    vis[v] = 1;
    curr.pb(v);

    for(int to : adj[v]) {
        if(!vis[to])
            dfs(to);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m; cin >> n >> m;


    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i);

            int cnt = 0;
            for(int x : curr) {
                cnt += adj[x].size();
            }
            cnt /= 2;
            int k = curr.size();

            if(cnt > k-1) {
                ans += cnt-(k-1);
            }

            curr.clear();
        }
    }
	
    cout << ans << "\n";

    return 0;
}


