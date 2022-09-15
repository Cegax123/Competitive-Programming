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
const int maxl = 20;

int r[maxn], par[maxn][maxl];
vi adj[maxn];
int n;

// g++ -std=c++17 -Wshadow -Wall -o "%e" "%f" -O2 -Wno-unused-result

void get_par(int v, int p) {
    par[v][0] = p;
    for(int i = 1; i < maxl; i++) {
        par[v][i] = par[par[v][i-1]][i-1];
    }
    for(auto to : adj[v]) {
        if(to == p) continue;
        get_par(to, v);
    }
}

int k_par(int v, int k) {

    for(int bit = 0; bit < maxl; bit++) {
        if((k>>bit)&1) {
      
            v = par[v][bit];       
        }
    }

    return v;
}

struct Query {
    int h, ans, id;
};

vector<Query> queries[maxn];

int T = 0;
int sz[maxn], h[maxn], st[maxn], ft[maxn], ver[maxn];

void calc_sz(int v, int p) {
    sz[v] = 1, st[v] = T++, ver[st[v]] = v;
    
    if(p!=-1) h[v] = h[p]+1;

    for(auto to : adj[v]) {
        if(p==to) continue;
        calc_sz(to, v);
        sz[v] += sz[to];
    }

    ft[v] = T;
}

int cnth[maxn];

void dfs(int v, int p, bool keep) {
    int mx = -1, bigChild = -1;

    for(auto to : adj[v]) {
        if(p == to) continue;
        if(sz[to] > mx) {
            mx = sz[to];
            bigChild = to;
        }
    }

    for(auto to : adj[v]) 
        if(p!=to and to != bigChild)
            dfs(to, v, 0);
    
    if(bigChild!=-1)
        dfs(bigChild, v, 1);

    cnth[h[v]]++;

    for(auto to : adj[v]) {
        if(p!=to and to!=bigChild) {
            for(int i = st[to]; i < ft[to]; i++) {
                cnth[h[ver[i]]]++;
            }
        }
    }

    for(auto& q : queries[v]) {
        if(v == 0) q.ans = 0;
        else q.ans = cnth[q.h]-1;
    }

    if(keep == 0) {
        for(int i = st[v]; i < ft[v]; i++) {
            cnth[h[ver[i]]]--;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
    
    for(int i = 1; i <= n; i++) {
        int r; cin >> r;    
        adj[r].pb(i);
        adj[i].pb(r);
    }

    memset(cnth, 0, sizeof(cnth));

    get_par(0, 0);
    h[0] = 0;
    calc_sz(0, -1);

    int q; cin >> q;
    for(int i = 0; i < q; i++) {
        int v, p; cin >> v >> p;
        int parv = k_par(v, p);
        queries[parv].pb({h[v], 0, i});
    }


    dfs(0, -1, 0);

    vi res(q);
    for(int i = 0; i <= n; i++) {
        for(auto Q : queries[i]) {
            res[Q.id] = Q.ans;
        }
    }

    for(int i = 0; i < q; i++) 
        cout << res[i] << " ";

	return 0;
}
