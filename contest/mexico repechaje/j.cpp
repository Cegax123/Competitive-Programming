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

const int maxn = 3e5 + 5;
vi adj[maxn];
ll dp[maxn][2];
int b[maxn];

void dfs(int v, int p=-1) {
    dp[v][0] = b[0];
    dp[v][1] = b[1];

    vector<ll> curr;

    ll sum = 0;

    for(int to : adj[v]) {
        if(to == p) continue;
        dfs(to, v);

        curr.pb(dp[to][0]-dp[to][1]);
        sum += dp[to][1];
    }

    dp[v][0] += sum;
    dp[v][1] += sum;

    sort(all(curr));
    reverse(all(curr));

    if(!curr.empty()) curr[0] += sum;

    for(int i = 1; i < (int) curr.size(); i++) 
        curr[i] += curr[i-1];

    for(int i = 0; i < (int) curr.size(); i++) {
        dp[v][0] = max(dp[v][0], b[i+1] + curr[i]);
        dp[v][1] = max(dp[v][1], b[i+2] + curr[i]);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;

    for(int i = 0; i < n; i++)
        cin >> b[i];

    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(0);

    cout << dp[0][0] << "\n";
	
    return 0;
}


