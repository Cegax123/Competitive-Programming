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

const int maxn = 3e5+5;

vii adj[maxn];
vii p(maxn, {-1, -1});
int d[maxn];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m; cin >> n >> m;
    queue<int> q;
    vector<bool> vis(maxn, 0);
    for(int i = 0; i < n; i++) {
        cin >> d[i];
        if(d[i] == -1) {
            q.push(i);
            vis[i] = 1;
        }
    }

    if(q.empty()) {
        q.push(0);
        vis[0] = 1;
    }

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].pb({b, i});
        adj[b].pb({a, i});
    }

    int child[maxn];
    memset(child, 0, sizeof(child));

    while(!q.empty()) {
        int u = q.front(); q.pop();

        for(auto e : adj[u]) {
            int to = e.first, id = e.second;
            if(vis[to]) continue;
            vis[to] = 1;
            p[to] = {u, id};
            q.push(to);
            child[u]++;
        }
    }

    for(int i = 0; i < n; i++)
        if(child[i] == 0)
            q.push(i);

    bool cmp = 1;
    vi ans;
    vi curr(n, 0);

    while(!q.empty()) {
        int u = q.front(); q.pop();
        if(d[u] == -1) continue;

        int v = p[u].first, id = p[u].second;

        if(curr[u]-d[u]) {
            if(v == -1) {
                cmp = 0;
            }
            else {
                ans.pb(id+1);
                curr[u] ^= 1;
                curr[v] ^= 1;
            }
        }

        child[v]--;
        if(child[v] == 0)
            q.push(v);
    }

    if(cmp == 0) {
        cout << "-1\n";
        return 0;
    }

    for(int i = 0; i < n; i++) 
        assert(d[i] == -1 or d[i] == curr[i]);

    cout << ans.size() << "\n";

    for(auto x : ans)
        cout << x << "\n";
   
    return 0;
}


