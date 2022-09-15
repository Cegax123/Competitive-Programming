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

const int maxn = 1e5+5;

vi adj[maxn];
int p[maxn];
bool vis[maxn];
int d[maxn];

void bfs(int src) {
    queue<int> q;

    q.push(src);
    vis[src] = 1;
    p[src] = src;

    while(!q.empty()) {
        int v = q.front(); q.pop();

        for(auto to : adj[v]) {
            if(vis[to]) continue;
            vis[to] = 1;
            d[to] = d[v]+1;
            p[to] = v;

            q.push(to);
        }
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

    bfs(0);


    if(vis[n-1] == 0) cout << "IMPOSSIBLE\n";
    else {
        vi a(1, n);

        int c = n-1;
        while(c) {
            c = p[c];
            a.pb(c+1);
        }

        reverse(all(a));

        cout << a.size() << "\n";
        for(auto x : a)
            cout << x << " ";
    }
	
	return 0;
}

