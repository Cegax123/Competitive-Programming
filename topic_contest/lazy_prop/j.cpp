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

const int maxn = 1e5+5;

const ll b = 543;
const ll mod = 1e9+9;

ll pb[maxn];

ll t[4*maxn]; 
int lazy[4*maxn];
int n, m, k;
string s;

ll ex(ll a, ll b, ll c) {
	ll ans = 1;

	while(b > 0) {
		if(b&1) ans = (ans * a) % c;
		a = (a * a) % c;
		b >>= 1;
	}

	return ans;
}

const ll invb = ex(b-1, mod-2, mod);

void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = s[tl]-'0'+1;
        lazy[v] = -1;
    }
    else {
        int tm = (tl+tr) >> 1;

        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);

        t[v] = (ll) (t[v*2] * pb[tr-tm] + t[v*2+1]) % mod;
        lazy[v] = -1;
    }
}

ll all_equal(int k, ll d) {
    ll ans = d * (pb[k]-1) % mod;
    ans = ans * invb % mod;
    
    return (ans+mod)%mod;
}

void push(int v, int tl, int tr) {
    if(lazy[v] == -1) return;

    int tm = (tl+tr) >> 1;

    t[v*2] = all_equal(tm-tl+1, lazy[v]);
    t[v*2+1] = all_equal(tr-tm, lazy[v]);

    lazy[v*2] = lazy[v*2+1] = lazy[v];
    lazy[v] = -1;
}

void update(int v, int tl, int tr, int l, int r, int d) {
    if(r < tl or tr < l) return;

    if(tl == l and tr == r) {
        t[v] = all_equal(tr-tl+1, d);

        lazy[v] = d;
    }
    else {
        push(v, tl, tr);

        int tm = (tl+tr) >> 1;

        update(v*2, tl, tm, l, min(r, tm), d);
        update(v*2+1, tm+1, tr, max(tm+1, l), r, d);

        t[v] = (ll) (t[v*2] * pb[tr-tm] + t[v*2+1])%mod;
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if(r < tl or tr < l) return 0;
    if(tl == l and tr == r) {
        return t[v];
    }
    else {
        push(v, tl, tr);

        int tm = (tl+tr) >> 1;

        ll LEFT = query(v*2, tl, tm, l, min(r, tm));
        ll RIGHT = query(v*2+1, tm+1, tr, max(tm+1, l), r);

        return (ll) (LEFT * pb[max(0, r-max(tm+1, l)+1)] + RIGHT) % mod;
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    pb[0] = 1;
    pb[1] = b;

    for(int i = 2; i < maxn; i++)
        pb[i] = (ll) pb[i-1] * b % mod;

	cin >> n >> m >> k;
    cin >> s;

    build(1, 0, n-1);

    int q = m+k;

    while(q--) {
        int op; cin >> op;

        if(op == 1) {
            int l, r; char c; cin >> l >> r >> c;
            l--; r--; 
            int d = c-'0'+1;

            update(1, 0, n-1, l, r, d);
        }
        else {
            int l, r, x; cin >> l >> r >> x;
            l--; r--;

            int len_total = r-l+1;
            int len_ss = x;
            int len_rem = len_total % len_ss;

            ll total = query(1, 0, n-1, l, r);
            total = (total+mod)%mod;

            ll ss = query(1, 0, n-1, l, l+len_ss-1);
            ll rem = query(1, 0, n-1, l, l+len_rem-1);

            int q = len_total / len_ss;

            ll ans = ss * (pb[q * len_ss] - 1) % mod;
            ans = ans * ex(pb[len_ss]-1, mod-2, mod) % mod;

            ans = ans * pb[len_rem] % mod;
            ans = (ans + rem) % mod;

            ans = (ans+mod)%mod;

            if(ans == total) cout << "YES\n";
            else cout << "NO\n";
        }
    }

	return 0;
}

