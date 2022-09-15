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

const int maxn = 5e5;
const int L = 60;
const ll mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    vector<vector<int> > mul(maxn+1, vector<int> (L, 0));

    for(int i = 1; i <= maxn; i++) {
        for(int j = 0; j < L; j++) {
            mul[i][j] = (mul[i-1][j] + (1ll << j)) % mod;
        }
    }

	int t; cin >> t;
    while(t--) {
        int n; cin >> n;

        ll x[n];
        vi cnt(L, 0);

        for(int i = 0; i < n; i++) {
            cin >> x[i];

            for(int j = 0; j < L; j++) 
                if((x[i] >> j)&1ll) cnt[j]++;
        }

        ll ans = 0;

        for(int i = 0; i < n; i++) {
            ll sum_and = 0, sum_or = 0;
            for(int j = 0; j < L; j++) {
                if((x[i] >> j)&1) {
                    sum_and = (sum_and + mul[cnt[j]][j])%mod;
                    sum_or = (sum_or + mul[n][j])%mod;
                }
                else {
                    sum_or = (sum_or + mul[cnt[j]][j])%mod;
                }
            }

            ll add = sum_and * sum_or % mod;
            ans = (ans+add)%mod;
        }

        cout << ans << "\n";
    }
	
	
	return 0;
}


