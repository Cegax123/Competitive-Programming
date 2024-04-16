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
const int maxk = 7;

vi adj[maxn];
ll sz[maxn];
ll dp[maxn][maxk];

void dfs(int u) {
    sz[u] = 1;

    for(int to : adj[u]) {
        dfs(to);
        sz[u] += sz[to];
    }

    for(int i = 0; i < maxk; i++)
        dp[u][i] = 0;

    dp[u][1] = sz[u]-1;

    for(int to : adj[u]) {
        vector<ll> curr(maxk, 0);
        for(int i = 1; i < maxk; i++)
            curr[i] = dp[u][i];

        for(int i = 0; i < maxk; i++) {
            for(int j = i; j < maxk; j++) {
                if(j-i >= 1) curr[j] = max(curr[j], dp[to][i] + dp[u][j-i]);
            }
        }

        for(int i = 1; i < maxk; i++)
            dp[u][i] = curr[i];
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int k; cin >> k;
        string s; cin >> s;

        int n = s.size();

        for(int i = 0; i < n; i++) {
            adj[i].clear();
            sz[i] = 0;
        }

        vi ord;
        ord.pb(0);

        int ind = 1;

        for(int i = 0; i < (int) s.size(); i++) {
            if(s[i] == '(') {
                adj[ord.back()].pb(ind);
                ord.pb(ind);
                ind++;
            }
            else {
                ord.pop_back();
            }
        }

        dfs(0);

        ll ans = 0;

        for(int i = 1; i < ind; i++)
            ans += sz[i]-1;

        ll mx = 0;
        for(int i = 0; i <= k+1; i++) {
            mx = max(mx, dp[0][i]);
        }

        ans -= mx;
        ans += sz[0]-1;

        cout << ans << "\n";
    }

	
    return 0;
}


