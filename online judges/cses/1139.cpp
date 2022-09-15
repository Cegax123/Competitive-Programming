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

int n, c[maxn];
int tin[maxn], tout[maxn], ver[maxn], T = 0;
vi adj[maxn];

map<int, int> cnt;

void preprocess(int v, int p = -1) {
    tin[v] = T++;
    ver[tin[v]] = v;

    for(int to : adj[v]) {
        if(to == p) continue;
        preprocess(to, v);
    }

    tout[v] = T-1;
}

int ans[maxn];

void dfs(int v, int p = -1, bool keep = 0) {
    int bigChild = -1, mx_sz = 0;

    for(int to : adj[v]) {
        if(to == p) continue;

        if(mx_sz < tout[to]-tin[to]+1) {
            mx_sz = tout[to]-tin[to]+1;
            bigChild = to;
        }
    }

    for(int to : adj[v]) {
        if(to == p or to == bigChild) continue;

        dfs(to, v, 0);
    }

    if(bigChild != -1)
        dfs(bigChild, v, 1);

    cnt[c[v]]++;

    for(int to : adj[v]) {
        if(to == p or to == bigChild) continue;

        for(int x = tin[to]; x <= tout[to]; x++) {
            int u = ver[x];

            cnt[c[u]]++;
        }
    }

    ans[v] = cnt.size();

    if(keep == 0) {
        for(int x = tin[v]; x <= tout[v]; x++) {
            int u = ver[x];

            cnt[c[u]]--;
            cnt.erase(c[u]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    
	for(int i = 0; i < n; i++) 
        cin >> c[i];

    for(int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    preprocess(0);
    dfs(0);

    for(int i = 0; i < n; i++) 
        cout << ans[i] << " ";

	return 0;
}

