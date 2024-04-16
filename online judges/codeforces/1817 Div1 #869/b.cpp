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



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<vi> adj(n);

        for(int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            u--; v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        bool find = 0;
        
        vii ans;

        for(int i = 0; i < n; i++) {
            if(find) break;
            int src = i;
            if((int) adj[src].size() < 4) continue;

            vector<bool> vis(n, 0);
            
            vis[src] = 1;

            vi par(n, -1);
            vi id(n, -1);

            queue<int> q;

            for(int to : adj[src]) {
                par[to] = src;
                id[to] = to;
                q.push(to);
                vis[to] = 1;
            }

            while(!q.empty()) {
                if(find) break;
                int u = q.front(); q.pop();

                for(int to : adj[u]) {
                    if(par[u] == to) continue;
                    if(vis[to]) {
                        if(id[to] == id[u]) continue;
                        
                        if(find) break;
                        find = 1;

                        for(int y : adj[src]) {
                            if(id[y] != id[to] and id[y] != id[u] and (int) ans.size() < 2) {
                                ans.pb({src+1, y+1});
                            }
                        }

                        int curr = u;

                        while(curr != src) {
                            ans.pb({curr+1, par[curr]+1});
                            curr = par[curr];
                        }

                        curr = to;

                        while(curr != src) {
                            ans.pb({curr+1, par[curr]+1});
                            curr = par[curr];
                        }

                        ans.pb({to+1, u+1});

                        break;
                    }
                    else {
                        vis[to] = 1;
                        q.push(to);
                        par[to] = u;
                        id[to] = id[u];
                    }
                }
            }
        }

        if(!find) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
            cout << ans.size() << "\n";
            for(auto e : ans) cout << e.first << " " << e.second << "\n";
        }
    }

	
    return 0;
}


