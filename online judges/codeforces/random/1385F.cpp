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
        int n, k; cin >> n >> k;

        vector<set<int>> adj(n);

        for(int i = 0; i < n-1; i++) {
            int a, b; cin >> a >> b;
            a--; b--;

            adj[a].insert(b);
            adj[b].insert(a);
        }

        if(k == 1) {
            cout << n-1 << "\n";
            continue;
        }

        auto is_leave = [&](int v) {
            return (int) adj[v].size() == 1;
        };

        vector<int> leaves(n, 0), total(n, 0);

        auto to_queue = [&](int v) {
            return leaves[v] % k == 0 and total[v]-leaves[v] == 1;
        };
        queue<int> q;
        
        for(int i = 0; i < n; i++) {
            total[i] = adj[i].size();
            for(int to : adj[i]) {
                if(is_leave(to)) {
                    leaves[i]++;
                }
            }

            if(to_queue(i) and !is_leave(i)) {
                q.push(i);
            }
        }

        int ans = 0;
        while(!q.empty()) {
            int v = q.front(); q.pop();
            vector<int> curr_leaves;

            for(int to : adj[v])
                if(is_leave(to)) curr_leaves.pb(to);

            for(int x : curr_leaves)
                adj[v].erase(x);

            ans += leaves[v] / k;

            total[v] = adj[v].size();
            leaves[v] = 0;

            int to = *adj[v].begin();

            leaves[to]++;

            if(to_queue(to)) {
                q.push(to);
            }
        }

        for(int i = 0; i < n; i++) {
            ans += leaves[i] / k;
        }

        cout << ans << "\n";
    }

	
    return 0;
}


