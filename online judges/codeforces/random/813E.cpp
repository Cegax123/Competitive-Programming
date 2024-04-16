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
const int LOGN = 20;

int n, k;
int bef[maxn][LOGN];
vector<int> t[4 * maxn];

void build(int v, int tl, int tr) {
    if(tl == tr) {
        int x = tl;

        for(int j = LOGN-1; j >= 0; j--) {
            if((k >> j)&1) {
                x = bef[x][j];
            }
        }

        t[v].pb(x);
    }
    else {
        int tm = (tl+tr) >> 1;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm+1, tr);

        t[v].resize(tr-tl+1);

        merge(all(t[v * 2]), all(t[v * 2 + 1]), t[v].begin());
    }
}

int query(int v, int tl, int tr, int l, int r, int pos) {
    if(tr < l or r < tl) return 0;
    if(tl == l and r == tr) {
        int L = 0, R = t[v].size()-1;

        while(L < R) {
            int M = (L+R+1) >> 1;
            if(t[v][M] < pos) L = M;
            else R = M-1;
        }

        if(t[v][L] < pos) return L+1;
        return 0;
    }
    else {
        int tm = (tl + tr) >> 1;
        return query(v * 2, tl, tm, l, min(r, tm), pos) + query(v * 2 + 1, tm+1, tr, max(tm+1, l), r, pos);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;

    map<int, int> last;

    for(int i = 0; i < LOGN; i++)
        bef[0][i] = 0;

    for(int i = 1; i <= n; i++) {
        int a; cin >> a;
        bef[i][0] = last[a];

        for(int j = 1; j < LOGN; j++) 
            bef[i][j] = bef[bef[i][j-1]][j-1];

        last[a] = i;
    }

    build(1, 1, n);

    int q; cin >> q;
    int ans = 0;
    while(q--) {
        int x, y; cin >> x >> y;
        int l = ((x + ans) % n) + 1;
        int r = ((y + ans) % n) + 1;

        if(l > r) swap(l, r);

        ans = query(1, 1, n, l, r, l); 
        cout << ans << "\n";
    }

    return 0;
}


