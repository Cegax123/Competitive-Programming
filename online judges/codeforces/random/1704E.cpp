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

const ll mod = 998244353;
const ll INF = (ll) 1e18;
 
int main() {
	int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
 
        vector<ll> a(n);
        vi in(n, 0);
 
        for(int i = 0; i < n; i++) cin >> a[i];
 
        vector<vector<int>> adj(n);
        for(int i = 0; i < m; i++) {
            int x, y; cin >> x >> y;
            x--; y--;
 
            adj[x].push_back(y);
            in[y]++;
        }
 
        auto print_seq = [&]() {
            cout << "[";
            for(int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << "]\n";
        };
 
        auto check_graph = [&] () {
            for(int i = 0; i < n; i++) {
                if(a[i]) {
                    for(int to : adj[i]) {
                        if(a[to] == 0)
                            return false;
                    }
                }
            }
            return true;
        };
 
        auto go_nxt_iteration = [&] () {
            vector<ll> nxt = a;
            for(int i = 0; i < n; i++) {
                if(a[i]) {
                    nxt[i]--;
                    for(int to : adj[i])
                        nxt[to]++;
                }
            }
            a = nxt;
        };
 
        bool erased[n];
        memset(erased, 0, sizeof(erased));
 
        auto sum = [&](ll a, ll b) {
            return (a+b) % mod;
        };
 
        auto mul = [&](ll a, ll b) {
            return (a*b) % mod;
        };
 
        auto go_nxt_iteration_complete = [&] (ll steps) {
            for(int i = 0; i < n; i++) {
                if(erased[i]) continue;
                a[i] = sum(a[i], mul(steps, in[i]-1));
            }
        };
        int cnt = n;
        ll ans = 0;
 
        auto erase_vertex = [&] (int v) {
            erased[v] = 1;
            a[v] = 0;
            cnt--;
            for(int to : adj[v]) {
                in[to]--;
            }
        };

        auto clean_graph = [&]() {
            for(int i = 0; i < n; i++) {
                if(a[i] == 0 and !erased[i]) {
                    erase_vertex(i);
                }
            }
        };
 
        while(!check_graph()) {
            ans++;
            go_nxt_iteration();
        }
 
        ans %= mod;

        clean_graph();
 
        while(cnt) {
            int v = -1; ll av = INF;
 
            for(int i = 0; i < n; i++) {
                if(!erased[i] and a[i] < av and in[i] == 0) {
                    v = i;
                    av = a[i];
                }
            }
 
            ans = sum(ans, a[v]);
            go_nxt_iteration_complete(a[v]);
 
            for(int i = 0; i < n; i++)
                if(!erased[i] and a[i] == 0 and in[i] == 0) erase_vertex(i);
 
            // print_seq();
 
        }
 
        cout << ans << "\n";
    }
 
    return 0;
}
