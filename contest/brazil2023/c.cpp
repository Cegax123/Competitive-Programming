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

const int maxn = 1e5 + 5;
int v[maxn];
vi adj[maxn];
vi a;
int ans[maxn];

void dfs(int u, int p) {
    int op = 0;
    int ind = 0, val = 0;
    if(u == 0 or a.back() < v[u]) {
        a.pb(v[u]);
        op = 1;
    }
    else {
        int l = 0, r = a.size()-1;
        while(l < r) {
            int m = (l+r) >> 1;
            if(a[m] > v[u]) r = m;
            else l = m+1;
        }

        if(a[l] > v[u]) {
            op = 2;
            ind = l;
            val = a[ind];
            a[ind] = v[u];
        }
    }

    ans[u] = a.size();

    for(int to : adj[u]) {
        if(to == p) continue;
        dfs(to, u);
    }

    if(op == 1) a.pop_back();
    else a[ind] = val;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for(int i = 1; i < n; i++) {
        int p; cin >> p; p--;
        adj[p].pb(i);
        adj[i].pb(p);
    }

    for(int i = 0; i < n; i++) cin >> v[i];

    dfs(0, 0);

    for(int i = 1; i < n; i++)
        cout << ans[i] << " ";
	
    return 0;
}


