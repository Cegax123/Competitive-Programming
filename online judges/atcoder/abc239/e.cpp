#include <bits/stdc++.h>
#include <math.h>
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

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;

typedef tree<
ii,
null_type,
less<ii>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

const int maxn = 1e5+5;

int n, q;

struct Query {
    int k, ind;
};

vector<Query> queries[maxn];
int ans[maxn];
vi adj[maxn];
int x[maxn];
ordered_set s;

int tin[maxn], tout[maxn], timer = 0;
int ver[maxn];

void preprocess(int v, int p) {
    tin[v] = timer++, ver[tin[v]] = v;

    for(int to : adj[v]) {
        if(to == p) continue;

        preprocess(to, v);
    }

    tout[v] = timer-1;
}

void dfs(int v, int p, bool keep) {
    int bigChild = -1, mx = 0;

    for(int to : adj[v]) {
        if(to == p) continue;

        int sz_to = tout[to]-tin[to]+1;
        if(sz_to > mx) {
            mx = sz_to;
            bigChild = to;
        }
    }

    for(int to : adj[v]) {
        if(to == p or to == bigChild) continue;

        dfs(to, v, 0);
    }

    if(bigChild != -1)
        dfs(bigChild, v, 1);

    s.insert({x[v], v});

    for(int to : adj[v]) {
        if(to == p or to == bigChild) continue;

        for(int i = tin[to]; i <= tout[to]; i++)
            s.insert({x[ver[i]], ver[i]});
    }

    for(Query Q : queries[v]) {
        ans[Q.ind] = (*s.find_by_order(s.size()-Q.k)).first;
    }

    if(keep == 0) {
        for(int i = tin[v]; i <= tout[v]; i++)
            s.erase({x[ver[i]], ver[i]});
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
    cin >> n >> q;

    for(int i = 0; i < n; i++)
        cin >> x[i];

    for(int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;

        adj[a].pb(b);
        adj[b].pb(a);
	}

    for(int i = 0; i < q; i++) {
        int v, k; cin >> v >> k;
        v--;

        queries[v].pb({k, i});
    }

    preprocess(0, 0);
    dfs(0, 0, 0);


    for(int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
	
	return 0;
}
