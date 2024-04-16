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

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

const int maxn = 2e5 + 5;
const int k = 2;

//const ll mod[k] = {999727999, 1070777777, 1000000007};
const ll mod[k] = {999727999, 1070777777};
//const ll mod[k] = {999727999};
ll b[k];

vector<ll> shift(vector<ll> h) {
    for(int i = 0; i < k; i++) {
        h[i] = h[i] * b[i] % mod[i];
    }
    return h;
}

vector<ll> add(vector<ll> a, vector<ll> b) {
    vector<ll> res(3);
    for(int i = 0; i < k; i++)
        res[i] = (a[i] + b[i]) % mod[i];
    return res;
}

vector<ll> sub(vector<ll> a, vector<ll> b) {
    vector<ll> res(3);
    for(int i = 0; i < k; i++) {
        res[i] = (a[i] - b[i]) % mod[i];
        if(res[i] < 0) res[i] += mod[i];
    }
    return res;
}

vi adj[maxn];
vector<vector<ll>> dp;

void dfs(int v, int p) {
    dp[v] = {0, 0, 0};
    for(int to : adj[v]) {
        if(to == p) continue;
        dfs(to, v);
        dp[v] = add(dp[v], shift(dp[to]));
    }

    dp[v] = add(dp[v], {1, 1, 1});
}

vector<vector<ll>> r;

void rerooting(int v, int p) {
    r[v] = dp[v];

    //for(ll x : r[v]) cout << x << " ";
    //cout << endl;

    for(int to : adj[v]) {
        if(to == p) continue;

        vector<ll> sv = dp[to];
        dp[to] = add(dp[to], shift(sub(dp[v], shift(dp[to]))));
        rerooting(to, v);
        dp[to] = sv;
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    for(int i = 0; i < k; i++)
        b[i] = rng() % mod[i];

    int n; cin >> n;

    vi c(n, 0);

    for(int i = 0; i < n-1; i++) {
        int a; cin >> a;
        c[a]++;
    }
    
    vector<ll> h;
    h = {0, 0, 0};

    for(int i = n-1; i >= 0; i--) {
        h = add(shift(h), {c[i], c[i], c[i]});
    }

    set<vector<ll>> poss;

    vector<ll> lft = {1, 1, 1};

    for(int i = 0; i < n; i++) {
        poss.insert(add(h, lft));
        lft = shift(lft);
    }

    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dp.resize(n);
    r.resize(n);

    dfs(0, 0);
    rerooting(0, 0);

    vi ans;
    for(int i = 0; i < n; i++) {
        if(poss.count(r[i])) ans.pb(i+1);

    }

    cout << ans.size() << "\n";
    for(int x : ans) cout << x << " ";

    return 0;
}


