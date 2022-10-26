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

const int mod = 1e9+7;

ll sum(ll x,ll y){
	return (x+y)%mod;
}

ll mul(ll x,ll y){
	return ((x*y)%mod+mod)%mod;
}

ll er(ll b,ll exp){
	if(exp==0)return 1;
	ll mi = er(b,exp/2);
	ll ret =mul(mi,mi);
	if(exp%2) ret=mul(ret,b);
	return ret;
}

const int maxn = 1e5 + 5;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n, m; cin >> n >> m;
    ll cnt[maxn];

    memset(cnt, 0, sizeof(cnt));

    int maxX = 0;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
        maxX = max(maxX, x);
    }

    const ll INF = (ll) 1e8;

    ll holes = 0;
    ll ans = 0;

    for(int x = maxX; x >= 0; x--) {
        holes = min(holes * 2, INF);
        if(holes < cnt[x]) {
            cnt[x] -= holes;
            holes = 0;

            ll f = (cnt[x] + m - 1) / m;
            ans = sum(ans, mul(f, er(2, x)));

            holes = m - (cnt[x] % m);
            holes %= m;
        }
        else {
            holes -= cnt[x];
        }
    }

    cout << ans << "\n";
	
    return 0;
}


