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

const int maxn = 1e5+5;

int c[maxn], sz[maxn], st[maxn];
vi adj[maxn], A;


void dfs(int v, int p = -1) {
    st[v] = A.size();
    A.pb(v);

    sz[v] = 1;

    for(int to : adj[v]) {
        if(to == p) continue;
        dfs(to, v);
        sz[v] += sz[to];
    }
}

const int B = 375;

struct Query {
    int l, r, k, id;

    bool operator < (Query other) const {
        return make_pair(l / B, r) < make_pair(other.l / B, other.r);
    }
};

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m; cin >> n >> m;
    int c[n];

    for(int i = 0; i < n; i++)
        cin >> c[i];

    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(0);


    vector<Query> queries;

    for(int i = 0; i < m; i++) {
        int v, k; cin >> v >> k;
        v--;

        queries.pb({st[v], st[v] + sz[v]-1, k, i});
    }

    sort(all(queries));

    int cnt[maxn];
    int ans[maxn];
    int res[m];

    memset(cnt, 0, sizeof(cnt));
    memset(ans, 0, sizeof(ans));

    int l = 0, r = -1;

    for(Query Q : queries) {
        while(l > Q.l) {
            l--;
            int v = c[A[l]];
            
            cnt[v]++;
            ans[cnt[v]]++;
        }
        while(r < Q.r) {
            r++;
            int v = c[A[r]];

            cnt[v]++;
            ans[cnt[v]]++;
        }
        while(l < Q.l) {
            int v = c[A[l]];
            ans[cnt[v]]--;
            cnt[v]--;

            l++;
        }
        while(r > Q.r) {
            int v = c[A[r]];
            ans[cnt[v]]--;
            cnt[v]--;

            r--;
        }

        res[Q.id] = ans[Q.k];
    }

    for(int i = 0; i < m; i++)
        cout << res[i] << "\n";
	
    return 0;
}


