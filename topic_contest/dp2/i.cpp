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

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, m, k, q; cin >> n >> m >> k >> q;
    vector<vi> rows(n);

	for(int i = 0; i < k; i++) {
        int r, c; cin >> r >> c;
        r--; c--;

        rows[r].pb(c);
    }

    while(rows[n-1].empty())
        n--;

    for(int i = 0; i < n; i++)
        sort(all(rows[i]));

    vi b(q);

    for(int i = 0; i < q; i++) {
        cin >> b[i];
        b[i]--;
    }

    sort(all(b));

    int dp[q];
    int ans = INF;

    if(rows[0].empty()) {
        for(int i = 0; i < q; i++)
            dp[i] = b[i];
    }
    else {
        int L = rows[0][0], R = rows[0].back();
        int dL = R + R - L, dR = R;

        ans = min(dL, dR);

        for(int i = 0; i < q; i++) 
            dp[i] = min(dR + abs(dR-b[i]), dL + abs(dL-b[i]));
    }

    for(int i = 0; i < q; i++)
        dp[i]++;

    for(int r = 1; r < n; r++) {
        if(!rows[r].empty()) {
           int L = rows[r][0], R = rows[r].back();
           int dL = INF, dR = INF;

            for(int i = 0; i < q; i++) {
                dL = min(dL, dp[i] + abs(b[i]-R) + abs(R-L));
                dR = min(dR, dp[i] + abs(b[i]-L) + abs(R-L));
            }

            ans = min(dL, dR);

            for(int i = 0; i < q; i++) 
                dp[i] = min(dR + abs(R-b[i]), dL + abs(L-b[i]));
        }

        if(r+1 < n) {
            for(int i = 0; i < q; i++)
                dp[i]++;
        }

        // for(int i = 0; i < q; i++)
        //     cout << dp[i] << " ";
        // cout << "\n";
    }

    cout << ans << "\n";

    return 0;
}

