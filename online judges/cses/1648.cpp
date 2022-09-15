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

const int maxn = 2e5+5;

ll t[4*maxn];
int a[maxn];

void build(int v, int tl, int tr) {
    if(tl == tr)
        t[v] = a[tl];
    else {
        int tm = (tl+tr) >> 1;

        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);

        t[v] = t[v*2] + t[v*2+1];
    }
}

void update(int v, int tl, int tr, int pos, int k) {
    if(tl == tr)
        t[v] = k;
    else {
        int tm = (tl+tr) >> 1;

        if(pos <= tm) update(v*2, tl, tm, pos, k);
        else update(v*2+1, tm+1, tr, pos, k);

        t[v] = t[v*2] + t[v*2+1];
    }
}

ll query(int v, int tl, int tr, int l, int r) {
    if(r < tl or tr < l) return 0ll;

    if(l == tl and r == tr) {
        return t[v];
    }
    else {
        int tm = (tl+tr) >> 1;

        return query(v*2, tl, tm, l, min(r, tm)) +
                query(v*2+1, tm+1, tr, max(l, tm+1), r);
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, q; cin >> n >> q;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    build(1, 0, n-1);

    for(int i = 0; i < q; i++) {
        int op; cin >> op;

        if(op == 1) {
            int pos, k; cin >> pos >> k;
            pos--;

            update(1, 0, n-1, pos, k);
        }
        else {
            int l, r; cin >> l >> r;
            l--; r--;

            cout << query(1, 0, n-1, l, r) << "\n";
        }
    }
	
	
	return 0;
}

