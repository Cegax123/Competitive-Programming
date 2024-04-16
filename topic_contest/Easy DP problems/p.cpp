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
    int n; cin >> n;

    const ll INF = (ll) 1e10;

    ll c[2][3];

    for(int i = 0; i < 2; i++)
        for(int k = 0; k < 3; k++)
            c[i][k] = -INF;

    c[0][0] = 0;

    for(int i = 1; i <= n; i++) {
        int a; cin >> a;

        ll nc[2][3];

        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 3; k++)
                nc[j][k] = c[j][k];

        // BUY

        for(int t = 0; t < 2; t++) {
            nc[1][t] = max(c[1][t], c[0][t] - a);
        }

        // SELL
        //
        for(int t = 0; t < 2; t++) {
            nc[0][t+1] = max(c[0][t+1], c[1][t] + a);
        }

        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 3; k++)
                c[j][k] = nc[j][k];
    }

    ll ans = 0;
    for(int j = 0; j < 2; j++)
        for(int k = 0; k < 3; k++)
            ans = max(ans, c[j][k]);

    cout << ans << "\n";
	
    return 0;
}


