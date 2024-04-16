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

int n, m;
int a[maxn];
vi adj[maxn], q[maxn];
int p[maxn][LOGN];

void dfs(int v, int par) {
    p[v][0] = par;

    for(int i = 1; i < LOGN; i++) 
        p[v][i] = p[p[v][i-1]][i-1];

    for(int to : adj[v]) {
        if(to == par) continue;
        dfs(to, v);
    }
}

struct BIT {
    vector<int> bit;  // binary indexed tree
    int n;

    BIT(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    BIT(vector<int> a) : BIT(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        if(l > r) return 0;
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

BIT ft(maxn);
int ans[maxn];

void dfs2(int v, int par) {
    for(int x : q[v]) {
        ft.add(x, 1);
    }

    ans[v] = ft.sum(0, a[v]);

    for(int to : adj[v]) {
        if(to == par) continue;
        dfs2(to, v);
    }

    for(int x : q[v]) {
        ft.add(x, -1);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        int b; cin >> b;
        b--;
        if(i) {
            adj[i].pb(b);
            adj[b].pb(i);
        }
    }
    
    dfs(0, 0);

    while(m--) {
        int o; cin >> o; o--;
        int l, r; cin >> l >> r;

        for(int i = LOGN-1; i >= 0; i--) {
            int nxt = p[o][i];
            if(a[nxt] <= r) o = nxt;
        }

        //cout << o << " " << l << endl;

        q[o].pb(l);
    }

    dfs2(0, 0);

    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
	
    return 0;
}


