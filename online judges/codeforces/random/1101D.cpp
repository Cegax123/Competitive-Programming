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
//

const int maxn = 2e5;

int sieve[maxn+5];

void fill_sieve() {
    sieve[1] = 1;

    for(int i = 2; i <= maxn; i++) {
        if(sieve[i]) continue;
        sieve[i] = i;

        for(int j = 2; i*j <= maxn; j++) {
            if(sieve[i*j]) continue;
            sieve[i*j] = i;
        }
    }
}

vi find_div(int x) {
    vi ans;
    while(x != 1) {
        int d = sieve[x];
        ans.pb(d);
        
        while(x % d == 0) x /= d;
    }

    return ans;
}

struct Node {
    vi p, dp;
    int ans;
};

vi adj[maxn+5];
Node nodes[maxn+5];
int a[maxn+5];

void dfs(int v, int p) {
    vi div = find_div(a[v]);

    for(int d : div) {
        nodes[v].p.pb(d);
        nodes[v].dp.pb(0);
    }

    int k = nodes[v].p.size();
    vector<vi> mxD;

    if(k) mxD.resize(k, vi(3, -1));

    for(int to : adj[v]) {
        if(to == p) continue;

        dfs(to, v);

        for(int i = 0; i < k; i++) {
            int prime = nodes[v].p[i];

            for(int j = 0; j < (int) nodes[to].p.size(); j++) {
                if(prime == nodes[to].p[j]) {
                    nodes[v].dp[i] = max(nodes[v].dp[i], nodes[to].dp[j]+1);

                    mxD[i][0] = nodes[to].dp[j]+1;
                    sort(all(mxD[i]));
                }
            }
        }
    }

    nodes[v].ans = 0;

    for(int i = 0; i < k; i++) {
        nodes[v].ans = max(nodes[v].ans, nodes[v].dp[i]);
        if(mxD[i][2] != -1 and mxD[i][1] != -1)
            nodes[v].ans = max(nodes[v].ans, mxD[i][2]+mxD[i][1]);
    }


    nodes[v].ans++;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    fill_sieve();

 	int n; cin >> n;
    
    for(int i = 0; i < n; i++) 
        cin >> a[i];

    bool all1 = true;
    for(int i = 0; i < n; i++) 
        if(a[i] != 1) all1 = false;

    if(all1) {
        cout << "0\n";
        return 0;
    }

    for(int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y;
        x--; y--;

        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(0, -1);

    int ans = 0;
    for(int i = 0; i < n; i++) 
        ans = max(ans, nodes[i].ans);

    cout << ans << "\n";

	return 0;
}

