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

const int maxn = 2e4 + 5;
const int L = 30;
const int mask = (1 << L) - 1;

int n, k;
int a[maxn];
vi adj[maxn];
int v[maxn];
int cnt;

void pre(int u, int p) {

    for(int to : adj[u]) {
        if(to == p) continue;
        pre(to, u);
        a[u] ^= a[to];
    }
}

int dfs(int u, int p, int x) {
    int contr = 0;

    for(int to : adj[u]) {
        if(to == p) continue;

        contr ^= dfs(to, u, x);
    }
    
    //cout << u << " " << curr << endl;
    v[u] ^= contr;

    cnt += v[u] == x;

    //cout << u << " " << curr << endl;

    if(v[u] == x) return x;
    return contr;
}

bool cmp(int x) {
    if(x == 0) return true;

    for(int i = 0; i < n; i++) {
        v[i] = a[i] & x;
        //cout << i << " " << v[i] << endl;
    }

    cnt = 0;

    dfs(0, -1, x);

    //cout << cnt << "\n";

    if((v[0] == x or v[0] == 0) and cnt >= k and (cnt-k) % 2 == 0) return true;
    return false;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> n >> k;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < n-1; i++) {
            int u, v; cin >> u >> v;
            u--; v--;

            adj[u].pb(v);
            adj[v].pb(u);
        }

        pre(0, -1);

        //cout << cmp(7) << endl;

        int ans = 0;

        for(int i = L-1; i >= 0; i--) {
            int nxt = (ans | (1 << i));

            if(cmp(nxt)) ans = nxt;
        }

        cout << ans << "\n";

        for(int i = 0; i < n; i++)
            adj[i].clear();
    }

	
    return 0;
}


