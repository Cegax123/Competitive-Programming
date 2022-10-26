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
    int n, x; cin >> n >> x;
    ll a[1 << n];

    for(int i = 0; i < n; i++) cin >> a[1 << i];

    const ll INF = 2e9;

    ll ans = 0;

    ll res[1 << n], cnt[1 << n];

    res[0] = 1;
    cnt[0] = 0;

    for(int i = 1; i < (1 << n); i++) {
        int bef = (i&(i-1));
        int lso = i - bef;

        ll rbef = res[bef];
        if(rbef == INF) res[i] = INF;
        else {
            res[i] = rbef * a[lso] / __gcd(rbef, a[lso]);
            res[i] = min(res[i], INF);
        }

        cnt[i] = cnt[bef] + 1;

        if(cnt[i]&1) ans += x/res[i];
        else ans -= x/res[i];
    }

    cout << ans << "\n";
	
    return 0;
}


