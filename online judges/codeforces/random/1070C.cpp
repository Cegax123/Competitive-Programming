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

const int maxn = 1e6;
const ll INF = 1e15;

ll cnt[4*maxn+5], acc[4*maxn+5];

void update_cnt(int v, int tl, int tr, int p, int c) {
    if(tl == tr) {
        cnt[v] += c;
    }
    else {
        int tm = (tl+tr) >> 1;

        if(p <= tm) update_cnt(v*2, tl, tm, p, c);
        else update_cnt(v*2+1, tm+1, tr, p, c);

        cnt[v] = cnt[v*2] + cnt[v*2+1];
    }
}

int query_cnt(int v, int tl, int tr, int l, int r) {
    if(r < tl or tr < l) return 0;
    if(tl == l and tr == r) {
        return cnt[v];
    }
    else {
        int tm = (tl+tr) >> 1;

        return query_cnt(v*2, tl, tm, l, min(r, tm)) +
            query_cnt(v*2+1, tm+1, tr, max(tm+1, l), r);
    }
}

void update_acc(int v, int tl, int tr, int p, int c) {
    if(tl == tr) {
        acc[v] += (ll) p * c;
    }
    else {
        int tm = (tl+tr) >> 1;

        if(p <= tm) update_acc(v*2, tl, tm, p, c);
        else update_acc(v*2+1, tm+1, tr, p, c);

        acc[v] = acc[v*2] + acc[v*2+1];
    }
}

ll query_acc(int v, int tl, int tr, int l, int r) {
    if(r < tl or tr < l) return 0;
    if(tl == l and tr == r) {
        return min(INF, acc[v]);
    }
    else {
        int tm = (tl+tr) >> 1;

        return min(INF, query_acc(v*2, tl, tm, l, min(r, tm)) +
            query_acc(v*2+1, tm+1, tr, max(tm+1, l), r));
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, k, m; cin >> n >> k >> m;
	
    vii L[n+1], R[n+1];
    ll ans = 0;

    for(int i = 0; i < m; i++) {
        int l, r, c, p; cin >> l >> r >> c >> p;

        L[l].pb({c, p});
        if(r+1 <= n) R[r+1].pb({c, p});
    }

    for(int i = 1; i <= n; i++) {
        for(auto e : L[i]) {
            int c = e.first, p = e.second;

            update_cnt(1, 0, maxn, p, c);
            update_acc(1, 0, maxn, p, c);
        }
        for(auto e : R[i]) {
            int c = e.first, p = e.second;

            update_cnt(1, 0, maxn, p, -c);
            update_acc(1, 0, maxn, p, -c);
        }
        
        int l = 0, r = maxn;

        while(l < r) {
            int m = (l+r) >> 1;
            
            if(query_cnt(1, 0, maxn, 0, m) >= k) r = m;
            else l = m+1;
        }

        ll tot = query_cnt(1, 0, maxn, 0, l);

        if(tot < k) {
            ans += query_acc(1, 0, maxn, 0, maxn);
        }
        else {
            ans += query_acc(1, 0, maxn, 0, l) - (ll) l * (tot-k);
        }
    }

    cout << ans << "\n";
	
	return 0;
}

