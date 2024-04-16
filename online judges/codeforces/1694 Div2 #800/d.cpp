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
        int n; cin >> n;
        int p[n];
        p[0] = -1;
        vi out(n, 0);
        vector<vi> adj(n);
        for(int i = 1; i < n; i++) {
            int x; cin >> x;
            x--;
            p[i] = x;
            out[x]++;

            adj[x].pb(i);
        }

        ll L[n], R[n];
        for(int i = 0; i < n; i++) cin >> L[i] >> R[i];

        ll curr[n];
        memset(curr, 0, sizeof(curr));

        queue<int> q;

        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(out[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int v = q.front(); q.pop();
            
            ll poss = 0;
            for(int to : adj[v]) {
                poss += curr[to];
            }
            if(poss < L[v]) {
                poss = R[v];
                ans++;
            }

            poss = min(poss, R[v]);

            curr[v] = poss;

            if(p[v] != -1) {
                out[p[v]]--;
                if(out[p[v]] == 0) q.push(p[v]);
            }
        }

        cout << ans << "\n";
    }

	
    return 0;
}


