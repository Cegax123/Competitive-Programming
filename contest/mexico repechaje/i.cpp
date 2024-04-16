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

const int maxn = 5e5 + 5;

int n;
int a[maxn];
int t[4 * maxn];

void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = a[tl];
    }
    else {
        int tm = (tl + tr) >> 1;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm+1, tr);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if(tr < l or r < tl) return 0;
    if(tl == l and tr == r) 
        return t[v];
    else {
        int tm = (tl + tr) >> 1;
        return max(query(v * 2, tl, tm, l, min(r, tm)),
                    query(v * 2 + 1, tm+1, tr, max(tm+1, l), r));
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    build(1, 0, n-1);
    
    int q; cin >> q;
    while(q--) {
        int m; cin >> m;
        int ind[m];
        ll ans = 0;

        for(int i = 0; i < m; i++) {
            cin >> ind[i];
            ind[i]--;
            ans += a[ind[i]];
        }

        vi b;
        
        for(int i = 0; i+1 < m; i++) {
            b.pb(query(1, 0, n-1, ind[i], ind[i+1]));
        }

        vii ord;

        for(int i = 0; i < m-1; i++) {
            ord.pb({b[i], i});
        }

        sort(all(ord));

        int nxt[m-1], bef[m-1];

        for(int i = 0; i < m-1; i++) {
            nxt[i] = i+1;
            bef[i] = i-1;
        }

        for(int i = 0; i < m-1; i++) {
            int j = ord[i].second;
            ans += (ll) (nxt[j]-j) * (j-bef[j]) * ord[i].first;
            int r = nxt[j], l = bef[j];
            if(l >= 0) nxt[l] = nxt[j];
            if(r < m-1) bef[r] = bef[j];
        }

        cout << ans << "\n";
    }
	
    return 0;
}


