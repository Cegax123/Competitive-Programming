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
    const int INF = 1e9;

    int n, m; cin >> n >> m;
    string s[n];

    vi adj[n], radj[n];

    for(int i = 0; i < n; i++) {
        cin >> s[i];

        for(int j = 0; j < m; j++) {
            if(s[i][j] == '1') {
                int to = i + j + 1;
                adj[i].pb(to);
                radj[to].pb(i);
            }
        }
    }

    int dp[n], rdp[n];

    for(int i = 0; i < n; i++)
        dp[i] = rdp[i] = INF;

    dp[0] = 0;

    for(int i = 0; i < n; i++) {
        for(int to : adj[i]) {
            dp[to] = min(dp[to], dp[i] + 1);
        }
    }

    rdp[n-1] = 0;

    for(int i = n-1; i >= 0; i--) {
        for(int to : radj[i]) {
            rdp[to] = min(rdp[to], rdp[i] + 1);
        }
    }

    int ans[n];

    for(int i = 0; i < n; i++) ans[i] = INF;

    for(int i = 1; i < n-1; i++) {
        for(int j = max(0, i-10); j < i; j++) {
            for(int to : adj[j]) {
                if(to > i) ans[i] = min(ans[i], dp[j] + rdp[to] + 1);
            }
        }
        if(ans[i] == INF) cout << "-1 ";
        else cout << ans[i] << " ";
    }

	
    return 0;
}


