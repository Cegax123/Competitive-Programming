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

ll lazy[4*maxn];
int a[maxn];

void push(int v) {
    lazy[v*2] += lazy[v];
    lazy[v*2+1] += lazy[v];

    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int k) {
    if(r < tl or tr < l) return;

    if(tl == l and tr == r) {
        lazy[v] += k;
    }
    else {
        push(v);
        int tm = (tl+tr) >> 1;

        update(v*2, tl, tm, l, min(r, tm), k);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, k);
    }
}

ll query(int v, int tl, int tr, int pos) {
    if(tl == tr) 
        return lazy[v];
    else {
        push(v);

        int tm = (tl+tr) >> 1;

        if(pos <= tm) return query(v*2, tl, tm, pos);
        else return query(v*2+1, tm+1, tr, pos);
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, q; cin >> n >> q;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < q; i++) {
        int op; cin >> op;

        if(op == 1) {
            int l, r, k; cin >> l >> r >> k;
            l--; r--;

            update(1, 0, n-1, l, r, k);
        }
        else {
            int pos; cin >> pos;
            pos--;

            cout << (ll) a[pos] + query(1, 0, n-1, pos) << "\n";
        }
    }
	
	
	return 0;
}


