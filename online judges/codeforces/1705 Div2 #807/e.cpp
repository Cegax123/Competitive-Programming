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

const int maxn = 2e5 + 1000;

ll t[4 * maxn + 5], lazy[4 * maxn + 5];
int parity[4 * maxn + 5], changed[4 * maxn + 5];

int n, q;
ll a[maxn+5], cnt[maxn+5], b[maxn+5];

void push(int v, int tl, int tr) {
    int tm = (tl + tr) >> 1;
    ll L = tl-tm+1, R = tr-tm;

    lazy[v * 2] += lazy[v];
    lazy[v * 2 + 1] += lazy[v];

    t[v * 2] += lazy[v] * L;
    t[v * 2 + 1] += lazy[v] * R;

    lazy[v] = 0;
}

void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = b[tl];
    }
    else {
        int tm = (tl + tr) >> 1;

        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);

        t[v] = t[v*2] + t[v*2+1];
    }
}

void push_par(int v, int tl, int tr) {
    int tm = (tl + tr) >> 1;
    int L = tm-tl+1, R = tr-tm;

    if(changed[v]) {
        changed[v * 2] ^= 1;
        changed[v * 2 + 1] ^= 1;

        parity[v * 2] = L - parity[v * 2];
        parity[v * 2 + 1] = R - parity[v * 2 + 1];

        changed[v] = 0;
    }
}

void build_par(int v, int tl, int tr) {
    if(tl == tr) {
        parity[v] = (b[tl] & 1);
    }
    else {
        int tm = (tl + tr) >> 1;
        build_par(v*2, tl, tm);
        build_par(v*2+1, tm+1, tr);

        parity[v] = parity[v*2] + parity[v*2+1];
    }
}

void update_par(int v, int tl, int tr, int l, int r) {
    if(tr < l or r < tl) return;
    if(tl == l and tr == r) {
        parity[v] = tr-tl+1-parity[v];
        changed[v] ^= 1;
    }
    else {
        push_par(v, tl, tr);
        int tm = (tl+tr) >> 1;
        update_par(v*2, tl, tm, l, min(r, tm));
        update_par(v*2+1, tm+1, tr, max(l, tm+1), r);

        parity[v] = parity[v*2] + parity[v*2+1];
    }
}

int query_par(int v, int tl, int tr, int l, int r) {
    if(tr < l or r < tl) return 0;
    if(tl == l and tr == r) {
        return parity[v];
    }
    else {
        push_par(v, tl, tr);
        int tm = (tl + tr) >> 1;
        return query_par(v*2, tl, tm, l, min(r, tm)) +
                query_par(v*2+1, tm+1, tr, max(tm+1, l), r);
    }
}

void update(int v, int tl, int tr, int l, int r, int add) {
    if(tr < l or r < tl) return;
    if(tl == l and tr == r) {
        t[v] += (ll) add * (tr-tl+1);
        lazy[v] += (ll) add;
    }
    else {
        push(v, tl, tr);
        int tm = (tl + tr) >> 1;
        update(v * 2, tl, tm, l, min(r, tm), add);
        update(v * 2 + 1, tm + 1, tr, max(l, tm+1), r, add);

        t[v] = t[v*2] + t[v*2+1];
    }
}

ll query(int v, int tl, int tr, int l, int r) {
    if(tr < l or r < tl) return 0;
    if(tl == l and tr == r) {
        return t[v];
    }
    else {
        push(v, tl, tr);
        int tm = (tl + tr) >> 1;
        return query(v * 2, tl, tm, l, min(r, tm)) +
            query(v*2 + 1, tm+1, tr, max(l, tm+1), r);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    b[0] = cnt[0];
    for(int i = 1; i < maxn; i++) {
        b[i] = cnt[i] + b[i-1]/2;
    }

    build(1, 0, maxn);
    build_par(1, 0, maxn);

    while(q--) {
        int k, x; cin >> k >> x;

        int num = a[k];
        a[k] = x;

        int bnum = query_par(1, 0, maxn, num, num);

        if(bnum) {
            update_par(1, 0, maxn, num, num);
            update(1, 0, maxn, num, num, -1);
        }
        else {
            int l = num, r = maxn;
        
            while(l < r) {
                int m = (l+r+1) >> 1;
                if(query_par(1, 0, maxn, num, m) == 0) l = m;
                else r = m-1;
            }

            update_par(1, 0, maxn, num, l+1);
            update(1, 0, maxn, num, l+1, -1);
        }

        num = a[k];
        int bx = query_par(1, 0, maxn, num, num);

        if(bx) {
            int l = num, r = maxn;
            while(l < r) {
                int m = (l + r + 1) >> 1;
                if(query_par(1, 0, maxn, num, m) == m-num+1) l = m;
                else r = m-1;
            }

            update_par(1, 0, maxn, num, l+1);
            update(1, 0, maxn, num, l+1, 1);
        }
        else {
            update_par(1, 0, maxn, num, num);
            update(1, 0, maxn, num, num, 1);
        }

        int l = 0, r = maxn;

        while(l < r) {
            int m = (l+r) >> 1;
            if(query(1, 0, maxn, m, maxn) == 0) r = m;
            else l = m+1;
        }

        cout << l-1 << "\n";
    }
	
    return 0;
}


