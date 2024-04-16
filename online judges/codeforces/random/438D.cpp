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
int a[maxn];
int t[4 * maxn];
ll sum[4 * maxn];

void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = a[tl];
        sum[v] = a[tl];
    }
    else {
        int tm = (tl + tr) >> 1;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm+1, tr);

        t[v] = max(t[v * 2], t[v * 2 + 1]);
        sum[v] = sum[v * 2] + sum[v * 2 + 1];
    }
}

void update(int v, int tl, int tr, int pos, int x) {
    if(tl == tr) {
        t[v] = x;
        sum[v] = x;
    }
    else {
        int tm = (tl + tr) >> 1;
        if(pos <= tm) update(v * 2, tl, tm, pos, x);
        else update(v * 2 + 1, tm+1, tr, pos, x);

        t[v] = max(t[v * 2], t[v * 2 + 1]);
        sum[v] = sum[v * 2] + sum[v * 2 + 1];
    }
}

void update_mod(int v, int tl, int tr, int l, int r, int x) {
    if(r < tl or tr < l) return;
    if(t[v] < x) return;
    if(tl == tr) {
        t[v] %= x;
        sum[v] %= x;
    }
    else {
        int tm = (tl + tr) >> 1;
        update_mod(v * 2, tl, tm, l, min(r, tm), x);
        update_mod(v * 2 + 1, tm+1, tr, max(tm+1, l), r, x);

        t[v] = max(t[v * 2], t[v * 2 + 1]);
        sum[v] = sum[v * 2] + sum[v * 2 + 1];
    }
}

ll query(int v, int tl, int tr, int l, int r) {
    if(r < tl or tr < l) return 0;
    if(tl == l and tr == r) {
        return sum[v];
    }
    else {
        int tm = (tl + tr) >> 1;

        ll L = query(v * 2, tl, tm, l, min(r, tm));
        ll R = query(v * 2 + 1, tm+1, tr, max(tm+1, l), r);

        return L + R;
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];

    build(1, 0, n-1);

    for(int i = 0; i < m; i++) {
        int t; cin >> t;
        if(t == 1) {
            int l, r; cin >> l >> r;
            l--; r--;

            cout << query(1, 0, n-1, l, r) << "\n";
        }
        else if(t == 2) {
            int l, r, x; cin >> l >> r >> x;
            l--; r--;

            update_mod(1, 0, n-1, l, r, x);
        }
        else {
            int k, x; cin >> k >> x;
            k--;

            update(1, 0, n-1, k, x);
        }
    }
	
    return 0;
}


