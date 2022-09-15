#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back 
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
typedef int64_t ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
//cout << setprecision(12) << fixed;

const int maxn = 2e5+5;

vi adj[maxn];

struct Node {
    ll s[2] = {0, 0}, c[2] = {0, 0};
};

Node nodes[maxn];
ll global = 0;

ll f(ll sum, ll cnt) {
    return (sum+cnt)/2ll;
}

void dfs(int v, int p) {
    nodes[v].c[0]++;

    vector<ll> sumh[2], cnth[2];
    
    for(int to : adj[v]) {
        if(to == p) continue;

        dfs(to, v);
        
        swap(nodes[to].s[0], nodes[to].s[1]);
        swap(nodes[to].c[0], nodes[to].c[1]);

        nodes[to].s[0] += nodes[to].c[0];
        nodes[to].s[1] += nodes[to].c[1];

        nodes[v].s[0] += nodes[to].s[0];
        nodes[v].c[0] += nodes[to].c[0];
        nodes[v].s[1] += nodes[to].s[1];
        nodes[v].c[1] += nodes[to].c[1];

        sumh[0].pb(nodes[to].s[0]);
        sumh[1].pb(nodes[to].s[1]);

        cnth[0].pb(nodes[to].c[0]);
        cnth[1].pb(nodes[to].c[1]);
    }

    int k = sumh[0].size();
    ll Ss = 0, Sf = 0, St = 0, Sc = 0; 

    for(int i = 0; i < k; i++) {
        global += (ll) sumh[0][i]/2 + f(sumh[1][i], cnth[1][i]);

        Ss += (ll) sumh[0][i]/2;
        Sf += (ll) f(sumh[1][i], cnth[1][i]);
        St += (ll) cnth[0][i] + cnth[1][i];
        // Sst += (sumh[0][i]/2) * (cnth[0][i] + cnth[1][i]);
        // Sft += f(sumh[1][i], cnth[1][i])  * (cnth[0][i] + cnth[1][i]);
        Sc += cnth[1][i];
        // Scc += cnth[1][i] * cnth[1][i];
    }

    ll t1 = Ss * St, t2 = Sf * St, t3 = Sc * Sc;

    for(int i = 0; i < k; i++) {
        t1 -= (ll) (sumh[0][i]/2) * (cnth[0][i] + cnth[1][i]);
        t2 -= (ll) f(sumh[1][i], cnth[1][i])  * (cnth[0][i] + cnth[1][i]);
        t3 -= (ll) cnth[1][i] * cnth[1][i];
    }

    global += t1+t2-t3/2ll;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(0, -1);

    cout << global << "\n";

	return 0;
}

