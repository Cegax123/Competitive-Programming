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
int parent[maxn];
int sz[maxn];
int val[maxn];
int cit[maxn];

int n, m, e;

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
    val[v] = v >= n;
    cit[v] = v < n;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];

        val[a] += val[b];
        cit[a] += cit[b];
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> e;

    for(int i = 0; i < n+m; i++)
        make_set(i);

    vii edges;

    for(int i = 0; i < e; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        
        edges.pb(make_pair(u, v));
    }

    int used[e];
    memset(used, 1, sizeof(used));
    
    vi queries;
    int q; cin >> q;
    for(int i = 0; i < q; i++) {
        int x; cin >> x;
        x--;
        used[x] = 0;
        queries.pb(x);
    }

    reverse(all(queries));
    vi res;
    int ans = 0;

    auto add_edge = [&] (int ind) {
        int a = edges[ind].first, b = edges[ind].second;

        a = find_set(a);
        b = find_set(b);

        if(a == b) return;

        if(val[a] == 0 and val[b] == 0) {
        }
        else if(val[a] == 0 or val[b] == 0) {
            if(val[a] == 0) ans += cit[a];
            else ans += cit[b];
        }
        
        union_sets(a, b);
    };

    for(int i = 0; i < e; i++) {
        if(used[i]) {
            add_edge(i);
        }
    }

    res.pb(ans);
    
    for(int Q : queries) {
        add_edge(Q);
        res.pb(ans);
    }

    for(int i = q-1; i >= 0; i--)
        cout << res[i] << "\n";
	
    return 0;
}


