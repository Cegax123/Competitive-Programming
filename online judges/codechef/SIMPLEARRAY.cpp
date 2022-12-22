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


ll ex(ll a, ll b, ll c) {
	ll ans = 1;

	while(b > 0) {
		if(b&1) ans = (ans * a) % c;
		a = (a * a) % c;
		b >>= 1;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        int cnt[k];
        memset(cnt, 0, sizeof(cnt));

        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            cnt[a%k]++;
        }

        const ll mod = (ll) 1e9+7;

        auto mul = [&](ll x, ll y) {
            return x * y % mod;
        };
        
        ll ans = 1;
        if(cnt[0]) ans = cnt[0] + 1;

        for(int i = 1; i < k; i++) {
            int j = k-i;
            if(i > j) continue;
            if(i == j) {
                if(cnt[i]) ans = mul(ans, cnt[i] + 1);
            }
            else {
                ll sum = ex(2, cnt[i], mod) + ex(2, cnt[j], mod) - 1;
                sum %= mod;
                if(sum < 0) sum += mod;
                ans = mul(ans, sum);
            }
        }

        cout << ans << "\n";
    }

	
    return 0;
}


