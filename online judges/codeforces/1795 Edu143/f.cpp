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

const int maxn = 2e5 + 5;

vi adj[maxn];
int chips[maxn];
int par[maxn];

int n, k;

bool marked[maxn], up[maxn];
int h[maxn];
int need[maxn];

void dfs(int v, int p = -1) {
    //cout << v << "\n";

    if(p >= 0) {
        h[v] = h[p] + 1; par[v] = p;
    }
    else h[v] = 0;

    for(int to : adj[v]) {
        if(to == p) continue;
        dfs(to, v);
    }
}

int get_max_d(int v) {
    int ans = 0;

    for(int to : adj[v]) {
        if(to == par[v] or marked[to]) continue;

        ans = max(ans, get_max_d(to)+1);
    }

    return ans;
}

bool cmp(int x) {
    for(int i = 0; i < n; i++)
        marked[i] = 0;

    for(int i = 0; i < k; i++) {
        if(i < x % k) need[chips[i]] = (x + k - 1) / k;
        else need[chips[i]] = x / k;

        //cout << chips[i] << " " << need[chips[i]] << "\n";
    }

    set<ii> s;

    for(int i = 0; i < n; i++)
        up[i] = 0;

    for(int i = 0; i < k; i++) {
        marked[chips[i]] = true;
        if(need[chips[i]]) s.insert({h[chips[i]], chips[i]});
    }


    while(!s.empty()) {
        auto e = *s.rbegin(); s.erase(e);

        int v = e.second;
        bool can = false;

        //cout << v << endl;

        int d = get_max_d(v);
        if(d >= need[v]) {
            can = true;
        }

        if(!can) {
            if(v == 0 or marked[par[v]]) {
                return false;
            }
            else {
                need[par[v]] = need[v];
                v = par[v];
                need[v]--;
                marked[v] = 1;
                if(need[v]) s.insert({h[v], v});
            }
        }
    }

    return true;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> n;

        for(int i = 0; i < n-1; i++) {
            int u, v; cin >> u >> v;
            u--; v--;

            adj[u].pb(v);
            adj[v].pb(u);
        }

        dfs(0);

        cin >> k;

        for(int i = 0; i < k; i++) {
            cin >> chips[i];
            chips[i]--;
        }

        //cout << cmp(9) << endl;

        int l = 0, r = n;

        while(l < r) {
            int m = (l+r+1) >> 1;
            if(cmp(m)) l = m;
            else r = m-1;
        }

        cout << l << "\n";

        for(int i = 0; i < n; i++)
            adj[i].clear();
    }

	
    return 0;
}


