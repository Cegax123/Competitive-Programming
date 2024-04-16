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

struct Segment {
    int i, f, o;
};

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;

    vector<Segment> segs[n];
    vi d;

    for(int t = 0; t < n; t++) {
        int m; cin >> m;

        for(int j = 0; j < m; j++) {
            int i, f, o; cin >> i >> f >> o;
            segs[t].pb({i, f, o});
            d.pb(i);
            d.pb(f);
        }
    }

    sort(d.begin(), d.end());
    d.resize(unique(d.begin(), d.end()) - d.begin());
    for(int i = 0; i < n; i++) {
        for(auto& e : segs[i]) {
            e.i = lower_bound(d.begin(), d.end(), e.i) - d.begin() + 1;
            e.f = lower_bound(d.begin(), d.end(), e.f) - d.begin() + 1;
        }
    }

    struct Segment2 {
        int i, o, id;
    };

    const int maxn = 2005;
    vector<Segment2> r[maxn];

    for(int i = 0; i < n; i++) {
        for(auto e : segs[i]) {
            r[e.f].pb({e.i, e.o, i});
        }
    }

    int dp[maxn][1 << n];

    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < (1 << n); j++)
            dp[i][j] = -2e9;
    }

    dp[0][0] = 0;

    int ans = -2e9;

    for(int i = 1; i < maxn; i++) {
        for(int j = 0; j < (1 << n); j++) 
            dp[i][j] = dp[i-1][j];

        for(auto e : r[i]) {
            for(int j = 0; j < (1 << n); j++) {
                if(((j >> e.id)&1) == 0) continue;
                dp[i][j] = max({dp[i][j], dp[e.i][j] + e.o, dp[e.i][j ^ (1 << e.id)] + e.o});
            }
        }

        ans = max(ans, dp[i][(1 << n) - 1]);
    }

    if(ans <= 0) cout << -1 << "\n";
    else cout << ans << "\n";
	
    return 0;
}


