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
        set<pair<int, ii>> s;

        int n; cin >> n;
        vector<bool> used_nodes(n+1, 0);
        vector<bool> used_edges(n+1, 0);
        vector<ii> edges[n+1];

        for(int i = 1; i < n; i++) {
            int u, v; cin >> u >> v;
            edges[u].pb({v, i});
            edges[v].pb({u, i});
        }

        used_nodes[1] = 1;

        for(auto e : edges[1]) {
            s.insert({e.second, {1, e.first}});
            used_edges[e.second] = 1;
        }

        int pos = 0;
        int ans = 1;
        while(!s.empty()) {

            s.insert({pos, {0, 0}});

            auto it = s.find({pos, {0, 0}});
            it++;

            int u, v;

            if(it == s.end()) {
                it = s.begin();
                ans++;
            }

            s.erase({pos, {0, 0}});

            pos = it->first;
            u = it->second.first;
            v = it->second.second;

            s.erase(it);

            if(!used_nodes[u]) {
                used_nodes[u] = 1;
                for(auto e : edges[u]) {
                    if(!used_edges[e.second]) {
                        s.insert({e.second, {min(e.first, u), max(e.first, u)}});
                        used_edges[e.second] = 1;
                    }
                }
            }

            if(!used_nodes[v]) {
                used_nodes[v] = 1;
                for(auto e : edges[v]) {
                    if(!used_edges[e.second]) {
                        s.insert({e.second, {min(e.first, v), max(e.first, v)}});
                        used_edges[e.second] = 1;
                    }
                }
            }
        }
        cout << ans << "\n";
    }

	
    return 0;
}


