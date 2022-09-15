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

const int maxn = 3e5+5;

const ll b = 41;
const ll mod = 1e9+7;

int l[maxn];
vi adj[maxn];

ll needed = 0;

ll mul(ll a, ll b, ll c) {
    return (a*b)%c;
}

ll add(ll a, ll b, ll c) {
    return (a+b)%c;
}

int sz[maxn], h[maxn], hv[maxn], ver[maxn];
int st[maxn], ft[maxn];

int T = 0, hmax = 0;

void calc_sz(int v, int par) {
    sz[v] = 1, st[v] = T++, ver[st[v]] = v;

    if(par != -1) {
        h[v] = h[par] + 1;
        hv[v] = add(mul(hv[par], b, mod), l[v]-'a'+1, mod);
    }

    hmax = max(hmax, h[v]);

    for(auto to : adj[v]) {
        if(to == par) continue;
        calc_sz(to, v);
        sz[v] += sz[to];
    }

    ft[v] = T;
}

map<int, int> cnt[maxn];
string t;
ll ans = 0;
ll pb;

void dfs(int v, int par, bool keep) {
    int mx = -1, bigChild = -1;

    for(auto to : adj[v]) { 
        if(to == par) continue;
        if(sz[to] > mx) {
            mx = sz[to];
            bigChild = to;
        }
    }

    for(auto to : adj[v]) {
        if(to == par or to == bigChild) continue;
        dfs(to, v, 0);
    }

    if(bigChild != -1)
        dfs(bigChild, v, 1);

    cnt[h[v]][hv[v]]++;

    for(auto to : adj[v]) {
        if(to == par or to == bigChild) continue;
        for(int i = st[to]; i < ft[to]; i++) {
            int x = ver[i];
            cnt[h[x]][hv[x]]++;
        }
    }

    

    if(l[v] == t[0] and h[v] + (int)t.size()-1 <= hmax) {
        ans += cnt[h[v]+t.size()-1][add(mul(hv[v],pb, mod), needed, mod)];
    }

    if(!keep) {
        for(int i = st[v]; i < ft[v]; i++) {
            int x = ver[i];
            cnt[h[x]][hv[x]]--;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    int ind = n;
    
    l[0] = '.';
    for(int i = 1; i < n; i++) {
        int p; cin >> p;
        p--;
        
        string s; cin >> s;
        for(int j = 0; j < (int) s.size()-1; j++) {
            l[ind] = s[j];
            
            adj[p].pb(ind);
            adj[ind].pb(p);
            
            p = ind;
            ind++;
        }
            
        adj[p].pb(i);
        adj[i].pb(p);

        l[i] = s.back();
    }

    cin >> t;

    pb = 1;
    for(int i = 1; i < (int) t.size(); i++) {
        needed = add(mul(needed, b, mod), t[i]-'a'+1, mod);
        pb = mul(pb, b, mod);
    }


    h[0] = 0;
    hv[0] = 0;

    calc_sz(0, -1);
    dfs(0, -1, 0);

    cout << ans << "\n";
    
	return 0;
}

