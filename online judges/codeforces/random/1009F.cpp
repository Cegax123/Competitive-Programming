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
int n;
int h[maxn];
int st[maxn], fin[maxn], ver[maxn], sz[maxn];
int cnt[maxn];
int T = 0;
vi adj[maxn];
int ans[maxn];

ii t[4 * maxn];

ii combine(const ii& a, const ii& b) {
    if(a.first > b.first) return a;
    else if(a.first < b.first) return b;
    return {a.first, min(a.second, b.second)};
}

void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = {0, tl};
    }
    else {
        int tm = (tl + tr) >> 1;

        build(v * 2, tl, tm);
        build(v * 2 + 1, tm+1, tr);

        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}

void update(int v, int tl, int tr, int pos, int x) {
    if(tl == tr) {
        t[v].first += x;
    }
    else {
        int tm = (tl + tr) >> 1;
        if(pos <= tm) update(v * 2, tl, tm, pos, x);
        else update(v * 2 + 1, tm+1, tr, pos, x);

        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}

void pre(int v, int p=-1) {
    if(p == -1) h[v] = 0;
    else h[v] = h[p] + 1;

    st[v] = T++;
    ver[st[v]] = v;
    sz[v] = 1;

    for(int to : adj[v]) {
        if(to == p) continue;
        pre(to, v);
        sz[v] += sz[to];
    }

    fin[v] = T;
}

void dfs(int v, int p=-1, bool keep=0) {
    int mx = -1, bigChild = -1;

    for(auto to : adj[v]) {
        if(to == p) continue;

        if(sz[to] > mx) {
            bigChild = to;
            mx = sz[to];
        }
    }

    for(auto to : adj[v]) {
        if(to == p) continue;

        if(to != bigChild)
            dfs(to, v, 0);
    }

    if(bigChild != -1)
        dfs(bigChild, v, 1);

    for(auto to : adj[v]) {
        if(to == p) continue;

        if(to != bigChild) {
            for(int u = st[to]; u < fin[to]; u++) {
                update(1, 0, n-1, h[ver[u]], 1);
            }
        }
    }

    update(1, 0, n-1, h[v], 1);
    //if(v == 0) {
        //for(auto e : s) {
            //cout << e.first << " " << e.second << endl;
        //}
    //}

    //cout << v << " " << t[0].first << " " << t[0].second << endl;

    ans[v] = t[1].second - h[v];

    if(keep == 0) {
        for(int u = st[v]; u < fin[v]; u++) {
            update(1, 0, n-1, h[ver[u]], -1);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;

    build(1, 0, n-1);

    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    pre(0);
    dfs(0);

    for(int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }
	
    return 0;
}


