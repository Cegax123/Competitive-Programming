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

const int maxn = 5e5 + 5;
vector<pair<int, int>> adj[maxn];
int col[maxn];
vector<int> cycle;
vector<pair<int, int>> st;

void dfs(int v) {
    col[v] = 1;

    for(auto e : adj[v]) {
        int to = e.first; 
        int id = e.second;

        if(col[to] == 2) continue;
        else if(col[to] == 0) {
            st.push_back({v, id});
            dfs(to);
            st.pop_back();
        }
        else {
            if(!cycle.empty()) continue;
            cycle.push_back(id);
            for(int i = st.size()-1; i >= 0; i--) {
                cycle.push_back(st[i].second);
                if(st[i].first == to) break;
            }
            
            reverse(cycle.begin(), cycle.end());
        }
    }

    col[v] = 2;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back({v, i});
    }

    for(int i = 0; i < n; i++) {
        if(col[i] == 0) dfs(i);
    }

    if(cycle.empty()) cout << "-1\n";
    else {
        cout << cycle.size() << "\n";
        for(int x : cycle) cout << x << "\n";
    }
	
    return 0;
}


