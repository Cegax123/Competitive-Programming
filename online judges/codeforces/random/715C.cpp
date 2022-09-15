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

ll inv(ll a, ll b) {
    return 1 < a ? b-inv(b%a, a)*b/a : 1;
}

ll mul(ll a, ll b, ll c) {
    return (a*b)%c;
}

ll add(ll a, ll b, ll c) {
    return (a+b)%c;
}

ll subs(ll a, ll b, ll c) {
    ll x = (a-b)%c;
    return (x+c)%c;
}

int n, m;
int p[2*maxn+10], ip[2*maxn+10];

void init() {
    p[0] = 1;
    
    for(int i = 1; i < 2*maxn+10; i++) {
        p[i] = mul(p[i-1], 10, m);
    }

    ip[0] = 1;
    ip[1] = inv(10, m);

    for(int i = 2; i < 2*maxn+10; i++) {
        ip[i] = mul(ip[i-1], ip[1], m);
    }
}

vii adj[maxn];
int L[maxn], R[maxn], d[maxn];
int sz[maxn], st[maxn], ft[maxn], ver[maxn], h[maxn];
int T = 0;

void assign_d(int v, int par) {
    for(auto e : adj[v]) {
        int to = e.first;
        if(to == par) continue;
        
        d[to] = e.second;
        assign_d(to, v);
    }
}

void calc_sz(int v, int par) {
    sz[v] = 1, st[v] = T++, ver[st[v]] = v;

    if(par != -1) {
        h[v] = h[par]+1;
        L[v] = add(L[par], mul(d[v], p[maxn+h[v]], m), m);
        R[v] = add(R[par], mul(d[v], p[maxn-1-h[v]], m), m);
    }

    for(auto e : adj[v]) {
        int to = e.first;
        if(to == par) continue;

        calc_sz(to, v);
        sz[v] += sz[to];
    }

    ft[v] = T;
}

ll ans = 0;
map<int, int> cntL, cntR;

void dfs(int v, int par, int keep) {
    int mx = -1, bigChild = -1;
    for(auto e : adj[v]) {
        int to = e.first;
        if(to == par) continue;

        if(sz[to] > mx) {
            mx = sz[to];
            bigChild = to;
        }
    }

    for(auto e : adj[v]) {
        int to = e.first;
        if(to == par or to == bigChild) continue;

        dfs(to, v, 0);
    }

    if(bigChild != -1) 
        dfs(bigChild, v, 1);

    for(auto e : adj[v]) {
        int to = e.first;
        if(to == par or to == bigChild) continue;

        for(int i = st[to]; i < ft[to]; i++) {
            int x = ver[i];

            int valR = mul(subs(R[x], R[v], m), p[h[v]+1], m);
            int needed = (m-valR)%m;

            ans += cntL[add(L[v], mul(needed, p[h[v]+1], m), m)];

            int valL = mul(subs(L[x], L[v], m), ip[h[v]+1], m);
            needed = (m-valL)%m;

            ans += cntR[add(R[v], mul(needed, ip[h[v]+1], m), m)];
        }

        for(int i = st[to]; i < ft[to]; i++) {
            cntL[L[ver[i]]]++;
            cntR[R[ver[i]]]++;
        }
    }

    ans += cntL[L[v]] + cntR[R[v]];

    cntL[L[v]]++;
    cntR[R[v]]++;
    
    if(keep == 0) {
        for(int i = st[v]; i < ft[v]; i++) {
            cntL[L[ver[i]]]--;
            cntR[R[ver[i]]]--;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;

    init();

    for(int i = 0; i < n-1; i++) {
        int u, v, dig; cin >> u >> v >> dig;
        adj[u].pb({v, dig});
        adj[v].pb({u, dig});
    }
		
    d[0] = 0;
    assign_d(0, -1);

    calc_sz(0, -1);
    dfs(0, -1, 0);


    cout << ans << "\n";

	return 0;
}

