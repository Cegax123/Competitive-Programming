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

int n, m;

const int maxn = 5e5+10;
vi adj[maxn];
string s;

struct Query {
    int h, ans, id;
};

vector<Query> ans[maxn];

int T = 0;
int st[maxn], ft[maxn], ver[maxn], sz[maxn];
int h[maxn];

void calc_sz(int v, int p) {
    if(p!=-1) h[v] = h[p]+1;

    sz[v] = 1, st[v] = T++, ver[st[v]] = v;
    for(auto to : adj[v]) {
        if(to==p) continue;
        calc_sz(to, v);
        sz[v] += sz[to];
    }

    ft[v] = T;
}

int fr[maxn][30];

void dfs(int v, int p, bool keep) {
    int mx = -1, bigChild = -1;
    for(auto to : adj[v]) {
        if(p == to) continue;
        if(sz[to] > mx) {
            mx = sz[to];
            bigChild = to;
        }
    }

    for(auto to : adj[v]) {
        if(p == to) continue;
        if(to != bigChild)
            dfs(to, v, 0);
    }

    if(bigChild != -1)
        dfs(bigChild, v, 1);

    fr[h[v]][s[v]-'a']++;

    for(auto to : adj[v]) {
        if(to == p or to == bigChild) continue;
        for(int i = st[to]; i < ft[to]; i++) {
            int x = ver[i];
            fr[h[x]][s[x]-'a']++;
        }
    }


    for(auto& q : ans[v]) {
        int rh = q.h-1;

        int cnt = 0;
        for(int i = 0; i < 30; i++)
            cnt += (fr[rh][i]&1);
        
        q.ans = cnt <= 1;
    }

    if(keep == 0) {
        for(int i = st[v]; i < ft[v]; i++) {
            int x = ver[i];
            fr[h[x]][s[x]-'a']--;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;

    for(int i = 1; i < n; i++) {
        int p; cin >> p;
        p--;

        adj[i].pb(p);
        adj[p].pb(i);
    }

    cin >> s;

    for(int i = 0; i < m; i++) {
        int v,h; cin >> v >> h;
        v--;
        ans[v].pb({h, 0, i});
    }

    h[0] = 0;
    calc_sz(0, -1);
    dfs(0, -1, 0);

    vi res(m);

    for(int i = 0; i < n; i++){
        for(auto q : ans[i])
            res[q.id] = q.ans;
    }

    for(int i = 0; i < m; i++) {
        if(res[i]) cout << "Yes\n";
        else cout << "No\n";
    }
	
	return 0;
}
