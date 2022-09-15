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

const int maxn = 300;

int n;
vector<vi> adj;
vector<bool> vis;
ll x[maxn], y[maxn], p[maxn];

void dfs(int v) {
    vis[v] = 1;

    for(int to : adj[v]) {
        if(!vis[to])
            dfs(to);
    }
}

bool check(ll s) {
    adj.clear(); adj.resize(n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ll d = abs(x[i]-x[j]) + abs(y[i]-y[j]);

            if((d + p[i] - 1ll)/p[i] <= s) {
                adj[i].pb(j);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        vis.clear(); vis.resize(n, 0);

        dfs(i);

        bool cmp = 1;

        for(int i = 0; i < n; i++)
            if(!vis[i]) cmp = 0;

        if(cmp) return 1;
    }

    return 0;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++) 
        cin >> x[i] >> y[i] >> p[i];

    ll l = 0, r = (ll) 1e10;

    while(l < r) {
        ll m = (l+r)/2;

        if(check(m)) r = m;
        else l = m+1;
    }

    cout << l << endl;
   
    return 0;
}


