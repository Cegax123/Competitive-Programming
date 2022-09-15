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
int c[maxn], cnt[maxn];
ll sum[maxn], ans[maxn];
vector<vi> adj(maxn);
int sz[maxn], st[maxn], ft[maxn], ver[maxn];
int T = 0, fr[maxn];

void calc_sz(int v, int p) {
    sz[v] = 1, st[v] = T++, ver[st[v]] = v;

    for(auto to : adj[v]) {
        if(to  == p) continue;
        calc_sz(to, v);
        sz[v] += sz[to];
    }

    ft[v] = T;
}

void dfs(int v, int p, bool keep) {
    int mx = -1, bigChild = -1;
    for(auto to : adj[v]) 
        if(to != p and sz[to] > mx) 
            mx = sz[to], bigChild = to;
    
    for(auto to : adj[v]) 
        if(to != p and to != bigChild)
            dfs(to, v, 0);

    int tmp = 0;
    if(bigChild != -1) {
        dfs(bigChild, v, 1);
        tmp = fr[bigChild];
    }
    else tmp = 1;

    sum[cnt[c[v]]] -= c[v];
    cnt[c[v]]++;
    sum[cnt[c[v]]] += c[v];

    tmp = max(tmp, cnt[c[v]]);

    for(auto to : adj[v]) {
        if(to != p and to != bigChild) {
            for(int i = st[to]; i  < ft[to]; i++) {
                int x = ver[i];
                sum[cnt[c[x]]] -= c[x];
                cnt[c[x]]++;
                sum[cnt[c[x]]] += c[x];

                tmp = max(tmp, cnt[c[x]]);
            }
        }
    }

    ans[v] = sum[tmp];
    fr[v] = tmp;

    if(keep==0) {
        for(int i = st[v]; i < ft[v]; i++) {
            int x = ver[i];
            sum[cnt[c[x]]] -= c[x];
            cnt[c[x]]--;
            sum[cnt[c[x]]] += c[x];
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
        
    sum[0] = (n*(n-1))/2;

    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    memset(cnt, 0, sizeof(cnt));
    memset(sum, 0, sizeof(sum));

    calc_sz(0, -1);
    dfs(0, -1, 0);

    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";

	return 0;
}