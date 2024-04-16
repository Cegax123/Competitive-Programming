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

int h[maxn];
vi ug[maxn], dg[maxn], rg[maxn];
int in[maxn], out[maxn];
ll tim[maxn];
bool vis[maxn];
vi v;

void dfs(int x) {
    v.pb(x);
    vis[x] = 1;

    for(int to : ug[x]) {
        if(!vis[to]) dfs(to);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, m; ll k; cin >> n >> m >> k;
        for(int i = 0; i < n; i++)
            cin >> h[i];

        for(int i = 0; i < n; i++) {
            ug[i].clear();
            dg[i].clear();
            rg[i].clear();
            vis[i] = false;
        }

        for(int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            a--; b--;

            dg[a].pb(b);
            rg[b].pb(a);

            ug[a].pb(b);
            ug[b].pb(a);
        }

        for(int i = 0; i < n; i++) {
            in[i] = rg[i].size();
            out[i] = dg[i].size();
        }

        const ll INF = 1e18;

        vector<pair<ll, ll>> inter;

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                v.clear();
                dfs(i);

                ll L = INF;
                ll R = 0;

                queue<int> q;
                for(int x : v) {
                    if(in[x] == 0) {
                        q.push(x);
                        tim[x] = h[x];
                    }
                }

                while(!q.empty()) {
                    int x = q.front(); q.pop();
                    ll curr = 0;
                    
                    for(int to : rg[x]) {
                        curr = max(curr, tim[to]);
                    }

                    if(h[x] >= curr) tim[x] = h[x];
                    else {
                        tim[x] = ((curr-h[x]+k-1)/k) * k + h[x];
                    }

                    for(int to : dg[x]) {
                        in[to]--;
                        if(in[to] == 0) {
                            q.push(to);
                            v.pb(to);
                        }
                    }
                }

                for(int x : v) {
                    if(out[x] == 0) {
                        q.push(x);
                    }
                }

                while(!q.empty()) {
                    int x = q.front(); q.pop();

                    ll lmt = INF;

                    for(int to : dg[x]) {
                        lmt = min(lmt, tim[to]);
                    }

                    if(lmt != INF) {
                        tim[x] += (lmt-tim[x]) / k * k;
                    }

                    for(int to : rg[x]) {
                        out[to]--;
                        if(out[to] == 0) {
                            q.push(to);
                        }
                    }
                }

                for(int x : v) {
                    L = min(L, tim[x]);
                    R = max(R, tim[x]);
                }

                inter.pb({L, R});
            }
        }

        for(int i = 0; i < n; i++) {
            cout << tim[i] << " ";
        }

        cout << endl;

        sort(all(inter));

        multiset<ll> s;

        for(auto e : inter) {
            s.insert(e.second);
        }

        ll ans = INF;

        for(int i = 0; i < (int) inter.size(); i++) {
            ll mxR = *s.rbegin();

            ans = min(ans, mxR - inter[i].first);

            if(i+1 < (int) inter.size()) {
                s.erase(s.find(inter[i].second));

                ll add = (inter[i+1].first - inter[i].first + k-1) / k;

                s.insert(inter[i].second + add * k);
            }
        }

        cout << ans << "\n";
    }

	
    return 0;
}


