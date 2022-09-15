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

const int maxn = 2e5 + 5;
const ll INF = (ll) 1e18;

ll t[4 * maxn], lazy[4 * maxn];
ll pref[maxn], a[maxn];

void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = pref[tl];
    }
    else {
        int tm = (tl + tr) >> 1;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm+1, tr);

        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}

void apply(int v, ll x) {
    t[v] += x;
    lazy[v] += x;
}

void push(int v) {
    apply(v * 2, lazy[v]);
    apply(v * 2 + 1, lazy[v]);

    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, ll x) {
    if(tr < l or r < tl) return;
    if(tl == l and tr == r) {
        apply(v, x);
    }
    else {
        push(v);
        int tm = (tl + tr) >> 1;
        update(v * 2, tl, tm, l, min(r, tm), x);
        update(v * 2 + 1, tm + 1, tr, max(tm+1, l), r, x);

        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}

ll query(int v, int tl, int tr, int l, int r) {
    if(tr < l or r < tl) return -INF;
    if(tl == l and tr == r) {
        return t[v];
    }
    else {
        push(v);
        int tm = (tl + tr) >> 1;
        return max(query(v * 2, tl, tm, l, min(r, tm)), 
            query(v * 2 + 1, tm + 1, tr, max(tm+1, l), r));
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q; cin >> n >> q;
    
    for(int i = 0; i < n; i++)
        cin >> a[i];

    pref[0] = a[0];

    for(int i = 1; i < n; i++)
        pref[i] = pref[i-1] + a[i];

    build(1, 0, n-1);

    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int k, u; cin >> k >> u;
            k--;

            update(1, 0, n-1, k, n-1, u-a[k]);
            a[k] = u;
        }
        else {
            int l, r; cin >> l >> r;
            l--; r--;

            ll ans = query(1, 0, n-1, l, r);
            if(l) ans -= query(1, 0, n-1, l-1, l-1);

            ans = max(ans, 0ll);

            cout << ans << "\n";
        }
    }
	
    return 0;
}


