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

vi adj[maxn];
string name[maxn];
int st[maxn], ft[maxn], h[maxn], sz[maxn], ver[maxn], T = 0;
int MAXH = -1;

void calc_sz(int v, int p) {
    st[v] = T++, sz[v] = 1, ver[st[v]] = v;
    if(p != -1) h[v] = h[p]+1; 

    for(auto to : adj[v]) {
        if(to != p) {
            calc_sz(to, v);
            sz[v] += sz[to];
        }
    }

    MAXH = max(MAXH, h[v]);
    ft[v] = T;
}

map<string, int> s[maxn];

struct Query {
    int h, ans, id;
};

vector<Query> queries[maxn];

void dfs(int v, int p, bool keep) {
    int mx = -1, bigChild = -1;

    for(auto to : adj[v]) {
        if(to == p) continue;
        if(sz[to] > mx) {
            mx = sz[to];
            bigChild = to;
        }
    }

    for(auto to : adj[v]) {
        if(to == p or to == bigChild) continue;
        else dfs(to, v, 0);
    }

    if(bigChild != -1)
        dfs(bigChild, v, 1);

    s[h[v]][name[v]]++;
    for(auto to : adj[v]) {
        if(to == p or to == bigChild) continue;

        for(int i = st[to]; i < ft[to]; i++) {
            int x = ver[i];
            s[h[x]][name[x]]++;
        }
    }


    for(auto& q : queries[v]) {
        if(q.h > MAXH) q.ans = 0;
        else q.ans = s[q.h].size();
    }
    
    if(keep == 0) {
        for(int i = st[v]; i < ft[v]; i++) {
            int x = ver[i];
            s[h[x]][name[x]]--;

            if(s[h[x]][name[x]] == 0)
                s[h[x]].erase(name[x]);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> name[i];
        int r; cin >> r;
    
        adj[r].pb(i);
        adj[i].pb(r);
    }

    calc_sz(0, -1);
    name[0] = "DrCarballo";

    int q; cin >> q;
    for(int i = 0; i < q; i++) {
        int v, k; cin >> v >> k;
        queries[v].pb({h[v]+k, 0, i});
    }

    dfs(0, -1, 0);

    vi res(q);

    for(int i = 0; i <= n; i++) {
        for(auto q : queries[i]) {
            res[q.id] = q.ans;
        }
    }

    for(int i = 0; i < q; i++)
        cout << res[i] << "\n";

	return 0;
}