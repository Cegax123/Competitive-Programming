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

const int maxn = 1e6 + 5;
const int LOGN = 20;
vi adj[maxn];
int c[maxn];
int p[maxn][LOGN];

void dfs(int v, int par = -1) {
    if(par == -1) p[v][0] = v;
    else p[v][0] = par;

    for(int i = 1; i < LOGN; i++) {
        p[v][i] = p[p[v][i-1]][i-1];
    }

    for(int to : adj[v]) {
        if(to == par) continue;
        dfs(to, v);
    }
}

int get_val(int v, int up) {
    for(int i = 0; i < LOGN; i++) {
        if((up >> i)&1)
            v = p[v][i];
    }
    return c[v];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q; cin >> n >> q;

    for(int i = 1; i <= n; i++) {
        char x; cin >> x;
        c[i] = x;

        int p; cin >> p;
        adj[p].pb(i);
        adj[i].pb(p);
    }

    dfs(0);

    vi a(n+1);
    vi mapeo(n+1);

    iota(all(a), 0);

    sort(all(a), [&] (int i, int j) {
        return c[i] < c[j];
    });

    mapeo[a[0]] = 0;
    for(int i = 1; i <= n; i++)
        mapeo[a[i]] = mapeo[a[i-1]] + (c[a[i]] != c[a[i-1]]);

    int k = 0;
    while((1 << k) <= n) {
        vii id(n+1);
        for(int i = 0; i <= n; i++) {
            id[i] = {mapeo[i], mapeo[p[i][k]]};
        }

        sort(all(a), [&] (int i, int j) {
            return id[i] < id[j];
        });

        mapeo[a[0]] = 0;

        for(int i = 1; i <= n; i++) {
            mapeo[a[i]] = mapeo[a[i-1]] + (id[a[i]] != id[a[i-1]]);
        }
        
        k++;
    }

    while(q--) {
        string s; cin >> s;
        int sl = 0, sr = n;
        for(int i = 0; i < (int) s.size(); i++) {
            int x = s[i];

            int l = sl, r = sr;
            while(l < r) {
                int m = (l + r) >> 1;
                if(get_val(a[m], i) >= x) r = m;
                else l = m + 1;
            }

            int L = (get_val(a[l], i) == x ? l : -1);

            l = sl, r=  sr;
            while(l < r) {
                int m = (l + r + 1) >> 1;
                if(get_val(a[m], i) <= x) l = m;
                else r = m - 1;
            }

            int R = (get_val(a[l], i) == x ? l : -1);

            sl = L;
            sr = R;

            if(sl == -1) break;
        }

        if(sl == -1) cout << 0 << "\n";
        else cout << sr-sl+1 << "\n";
    }
	
    return 0;
}


