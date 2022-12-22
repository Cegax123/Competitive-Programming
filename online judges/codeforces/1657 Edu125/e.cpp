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

const ll mod = 998244353;
const int maxn = 300;

ll mul(ll a, ll b) {
    return a * b % mod;
}

ll sum(ll a, ll b) {
    return (a + b) % mod;
}

ll ex(ll a, ll b, ll c) {
	ll ans = 1;

	while(b > 0) {
		if(b&1) ans = (ans * a) % c;
		a = (a * a) % c;
		b >>= 1;
	}

	return ans;
}

ll fact[maxn], ifact[maxn];

ll comb(ll x, ll y) {
    return mul(fact[x], mul(ifact[y], ifact[x-y]));
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    fact[0] = 1;

    for(int i = 1; i < maxn; i++)
        fact[i] = mul(fact[i-1], i);

    ifact[maxn-1] = ex(fact[maxn-1], mod-2, mod);

    for(int i = maxn-2; i >= 0; i--) {
        ifact[i] = mul(ifact[i+1], i+1);
    }

    int n, k; cin >> n >> k;

    ll dp[n+1][k+1];
    memset(dp, 0, sizeof(dp));

    for(int c = 0; c <= k; c++)
        dp[0][c] = 1;

    for(int c = 1; c <= k; c++) {
        for(int i = 1; i <= n; i++) {
            for(int t = 0; t <= i; t++) {
                ll f1 = mul(comb(i, t), dp[i-t][c-1]);
                ll f2 = ex(k-c+1, (i-t) * t + t * (t-1) / 2, mod);
                ll add = mul(f1, f2);

                //if(i == 2 and c == 2 and t == 0) {
                    //cout << f1 << " " << f2 << endl;
                //}

                dp[i][c] = sum(dp[i][c], add);
            }
        }
    }

    //for(int i = 1; i <= n; i++) {
        //for(int c = 1; c <= k; c++) {
            //cout << "i : " << i << ", c: " << c << " ==> ";
            //cout << dp[i][c] << "\n";
        //}
    //}

    cout << dp[n-1][k] << "\n";
	
    return 0;
}


