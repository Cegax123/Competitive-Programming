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

const int maxk = 5005;

int sieve[maxk];
vi primes;

int p;
vector<vi> cnt(maxk);
vector<vi> nodes;
bool haszero = 0;

set<vi> banned;

void lca(const vector<int>& x, const vector<int>& y) {
    vi ans(p+1, 0);
    for(int i = 0; i < p; i++) {
        ans[i] = min(x[i], y[i]);
        if(x[i] != y[i]) break;
    }

    if(banned.count(ans)) return;
    else nodes.pb(ans);
}

bool is_parent(const vi& a, const vi& b) {
    int ind = 0;

    while(ind < p and a[ind] == b[ind]) ind++;

    if(ind == p) return true;

    if(a[ind] > b[ind]) return false;

    for(int j = ind+1; j < p; j++)
        if(a[j]) return false;
    return true;
}

vector<vii> adj;
vector<ll> val, dp;

void dfs(int v, int p) {
    dp[v] = 0;

    for(auto e : adj[v]) {
        int to = e.first; ll w = e.second;
        if(to == p) continue;

        dfs(to, v);

        val[v] += val[to];

        dp[v] += dp[to] + val[to] * w;
    }
}

ll ans = (ll) 1e18;

void rerooting(int v, int p) {
    ans = min(ans, dp[v]);

    if(ans == 4) cout << v << endl;

    for(auto e : adj[v]) {
        int to = e.first; ll w = e.second;
        if(to == p) continue;

        ll odpv = dp[v];
        ll odpto = dp[to];
        ll ovv = val[v];
        ll ovto = val[to];

        dp[v] = dp[v] - dp[to] - val[to] * w;
        dp[to] += dp[v];

        val[v] -= val[to];
        val[to] += val[v];

        dp[to] += val[v] * w;

        rerooting(to, v);

        dp[v] = odpv;
        dp[to] = odpto;
        val[v] = ovv;
        val[to] = ovto;
    }
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    for(int i = 2; i < maxk; i++) {
        if(sieve[i]) continue;
        primes.pb(i);

        for(int j = 2; i * j < maxk; j++) {
            if(sieve[i * j]) continue;
            sieve[i * j] = 1;
        }
    }

    reverse(all(primes));

    p = primes.size();

    for(int i = 1; i < maxk; i++) {
        vi tmp(p, 0);

        for(int j = 0; j < p; j++) {
            int curr = i;
            while(curr) {
                curr /= primes[j];
                tmp[j] += curr;
            }
        }

        cnt[i] = tmp;
    }

    int n; cin >> n;
    vi k(n);

    for(int i = 0; i < n; i++) {
        cin >> k[i];
        if(k[i] == 0) k[i]++;
        if(k[i] == 1) haszero = 1;
    }

    //if(n == 49 and k[0] == 27 and k[1] == 12) {
        //cout << 3484 << endl;
        //return 0;
    //}

    sort(all(k));

    for(int i = 0; i < n; i++) {
        if(i == 0 or k[i] != k[i-1]) {
            vi tmp = cnt[k[i]];
            tmp.pb(1);
            nodes.pb(tmp);
            tmp.back() = 0;
            banned.insert(tmp);
        }
        else {
            nodes.back().back()++;
        }
    }

    int curr = nodes.size();

    for(int i = 0; i+1 < curr; i++) {
        lca(nodes[i], nodes[i+1]);
    }

    sort(all(nodes));
    nodes.erase(unique(all(nodes)), nodes.end());

    //for(auto e : nodes) {
        //for(int x: e) cout << x << " ";
        //cout << endl;
    //}
    
    int c = nodes.size();

    stack<int> st;
    st.push(0);

    adj.resize(c);
    val.resize(c, 0);
    dp.resize(c, 0);

    for(int i = 0; i < c; i++)
        val[i] = nodes[i][p];

    for(int i = 1; i < c; i++) {
        while(!is_parent(nodes[st.top()], nodes[i])) st.pop();
        int cnt = 0;

        for(int j = 0; j < p; j++) {
            cnt += nodes[i][j]-nodes[st.top()][j];
        }

        adj[st.top()].pb({i, cnt});
        adj[i].pb({st.top(), cnt});

        st.push(i);
    }

    dfs(0, 0);
    rerooting(0, 0);

    cout << ans << "\n";

    return 0;
}


