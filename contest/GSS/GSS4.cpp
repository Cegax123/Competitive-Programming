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
ll t[4 * maxn];
ll a[maxn];

void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = a[tl];
    }
    else {
        int tm = (tl + tr) >> 1;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm+1, tr);

        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

void update(int v, int tl, int tr, int l, int r) {
    if(tr < l or r < tl) return;
    if(t[v] == tr-tl+1) return;

    if(tl == tr) {
        t[v] = sqrt(t[v]);
    }

    else {
        int tm = (tl + tr) >> 1;
        
        update(v * 2, tl, tm, l, min(r, tm));
        update(v * 2 + 1, tm+1, tr, max(tm+1, l), r);

        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

ll query(int v, int tl, int tr, int l, int r) {
    if(tr < l or r < tl) return 0ll;
    if(tl == l and tr == r) {
        return t[v];
    }
    else {
        int tm = (tl + tr) >> 1;
        return query(v * 2, tl, tm, l, min(r, tm)) + 
            query(v * 2 + 1, tm+1, tr, max(tm+1, l), r);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc = 1;

    int n;
    while(cin >> n) {
        cout << "Case #" << tc++ << ":\n";

        for(int i = 0; i < n; i++) 
            cin >> a[i];

        build(1, 0, n-1);

        int q; cin >> q;

        while(q--) {
            int op; cin >> op;

            int l, r; cin >> l >> r;

            if(l > r) swap(l, r);

            l--; r--;

            if(op == 0) {
                update(1, 0, n-1, l, r);
            }
            else {
                cout << query(1, 0, n-1, l, r) << "\n";
            }
        }

        cout << "\n";
    }

    
	
    return 0;
}


