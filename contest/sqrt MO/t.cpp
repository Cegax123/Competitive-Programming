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

const int maxn = 1e5 + 5;
const int B = 375;

int val[maxn];
int t[4 * maxn];

void build(int v, int tl, int tr) {
    if(tl == tr)
        t[v] = 0;
    else {
        int tm = (tl + tr) >> 1;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm+1, tr);
        t[v] = 0;
    }
}

void push(int v) {
    if(t[v]) {
        t[v * 2] = t[v];
        t[v * 2 + 1] = t[v];
    }
    t[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int x) {
    if(r < tl or tr < l) return;
    if(tl == l and tr == r) {
        t[v] = x;
    }
    else {
        int tm = (tl + tr) >> 1;
        update(v * 2, tl, tm, l, min(r, tm), x);
        update(v * 2 + 1, tm + 1, tr, max(l, tm+1), r, x);
    }
}

int query(int v, int tl, int tr, int pos) {
    if(tl == tr)
        return t[v];
    else {
        int tm = (tl + tr) >> 1;
        if(pos <= tm) return query(v * 2, tl, tm, pos);
        else return query(v * 2 + 1, tm + 1, tr, pos);
    }
}

struct Change {
    int l, r, x;
};

struct BIT {
    vector<ll> bit;  // binary indexed tree
    int n;

    BIT(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    BIT(vector<ll> a) : BIT(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    ll sum(int r) {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    ll sum(int l, int r) {
        if(l > r) return 0;
        return sum(r) - sum(l - 1);
    }

    void add(int idx, ll delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m; cin >> n >> m;

    for(int i = 1; i <= n; i++)
        val[i] = i;

    vector<Change> changes;
    BIT ft(n+1);

    for(int cq = 0; cq < m; cq++) {
        if(cq % B == 0) {
            build(1, 0, n);

            for(Change c : changes) 
                update(1, 0, n, c.l, c.r, c.x);

            for(int i = 1; i <= n; i++) {
                int new_val = query(1, 0, n-1, i);
                ll delta = 0;
                if(new_val) {
                    delta = new_val - val[i];
                    ft.add(i, delta);
                    val[i] = new_val;
                }
            }

            changes.clear();
        }

        int op; cin >> op;
        if(op == 1) {
            int l, r, x; cin >> l >> r >> x;
            changes.pb({l, r, x});
        }
        else {
            int l, r; cin >> l >> r;
            
        }
    }
	
    return 0;
}


