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
const int maxn = 1e5+10;

ll p2[maxn];

ll ex(ll a, ll b) {
	ll ans = 1;

	while(b > 0) {
		if(b&1) ans = (ans * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}

	return ans;
}

ll mul(ll a, ll b) {
    return (a*b) % mod;
}

ll add(ll a, ll b) {
    a = (a+b)%mod;
    if(a < 0) a += mod;
    return a;
}

ll fact[maxn];

ll comb(ll x, ll y) {
    return mul(fact[x], ex(mul(fact[y], fact[x-y]), mod-2));
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    p2[0] = 1;

    for(int i = 1; i < maxn; i++)
        p2[i] = mul(p2[i-1], 2);

    fact[0] = 1;

    for(int i = 1; i < maxn; i++)
        fact[i] = mul(fact[i-1], i);

    int t; cin >> t;

    while(t--) {
        int n; cin >> n;
        vi a(n);
        vii b;

        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i]) b.pb({a[i], i});
        }

        if(b.empty()) {
            cout << p2[n-1] << "\n";
            continue;
        }
        
        int k = b.size();
        ll sumL[k], sumR[k];
        
        sumL[0] = b[0].first;

        for(int i = 1; i < k; i++)
            sumL[i] = sumL[i-1] + b[i].first;

        sumR[k-1] = b[k-1].first;
        for(int i = k-2; i >= 0; i--)
            sumR[i] = sumR[i+1] + b[i].first;

        int r = k-1;
        vii inter;
        int lasti = -1, lastr = k;

        for(int i = 0; i < k; i++) {
            while(sumR[r] < sumL[i]) {
                r--;
            }
            if(i < r and sumR[r] == sumL[i]) {
                inter.pb({b[lasti+1].second, b[i].second});
                inter.pb({b[r].second, b[lastr-1].second});

                lasti = i;
                lastr = r;
            }
        }

        if(lasti + 1 < lastr) {
            inter.pb({b[lasti+1].second, b[lastr-1].second});
        }

        inter.pb({-1, -1});
        inter.pb({n, n});
        sort(all(inter));
        
        vi c;

        for(int i = 1; i < (int) inter.size(); i++) {
            int cnt = 0;
            for(int j = inter[i-1].second+1; j <= inter[i].first-1; j++) {
                cnt += a[j] == 0;
            }
            c.pb(cnt);
        }

        ll ans = 1;
        int m = c.size();

        ll curr = 0;
        for(int i = 0; i <= min(c[0], c[m-1]); i++) {
            curr = add(curr, mul(comb(c[0], i), comb(c[m-1], i)));
        }

        ans = mul(ans, curr);

        for(int i = 1; i < m; i++) {
            int j = m-1-i;
            if(j < i) break;

            if(i == j) {
                ll curr = p2[c[i]+1];

                //for(int k = 1; k <= c[i]; k++) {
                    //curr = add(curr, comb(c[i], k));
                //}
                ans = mul(ans, curr);
            }
            else {
                ll curr = 0;

                for(int k = 0; k <= min(c[i]+1, c[j]+1); k++) {
                    curr = add(curr, mul(comb(c[i]+1, k), comb(c[j]+1, k)));
                }

                ans = mul(ans, curr);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}

