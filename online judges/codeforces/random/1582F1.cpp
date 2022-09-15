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

const int maxa = 8192;
const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    vi pos[maxa];

    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        pos[a].pb(i);
    }
    
    vi dp(maxa, INF);
    dp[0] = -1;

    for(int x = 1; x < maxa; x++) {
        if(pos[x].empty()) continue;
        for(int i = 0; i < maxa; i++) {
            auto it = upper_bound(all(pos[x]), dp[x^i]);
            if(it == pos[x].end()) continue;
            dp[i] = min(dp[i], *it);
        }
    }

    int ans = 0;
    for(int i = 0; i < maxa; i++)
        ans += dp[i] < INF;

    cout << ans << "\n";
    for(int i = 0; i < maxa; i++)
        if(dp[i] < INF) cout << i << " ";
    cout << "\n";
   
    return 0;
}


