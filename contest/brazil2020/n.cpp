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

const int maxn = 4e7;

int sieve[maxn];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    sieve[1] = 0;

    vector<ll> pr;

    for(int i = 2; i < maxn; i++) {
        if(sieve[i]) continue;
        pr.pb(i);
        for(int j = 2; i * j < maxn; j++) {
            sieve[i * j] = 1;
        }
    }

    int m, n, k; cin >> m >> n >> k;
    ll c[n];

    for(int i = 0; i < n; i++)
        cin >> c[i];

    vii adj[m];
    for(int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        int x; cin >> x;
        a--; b--;
        adj[a].pb({b, x});
    }

    ll d[m];
    memset(d, 0, sizeof(d));

    int curr = 0;

    for(int i = 0; i < m; i++) {
        ll g = 0;

        for(auto e : adj[i]) {
            int to = e.first;
            g = __gcd(g, c[to]);
        }

        while(curr < (int) pr.size()) {
            if(g % pr[curr] == 0) {
                d[i] = pr[curr++];
                break;
            }
            else curr++;
        }

        if(d[i]) {
            for(auto e : adj[i]) {
                int to = e.first;
                while(c[to] % d[i] == 0)
                    c[to] /= d[i];
            }
        }
    }

    for(int i = 0; i < m; i++) {
        if(d[i] == 0) {
            for(auto e : adj[i]) {
                int to = e.first, x = e.second;
                if(x == 1) d[i] = c[to];
                else if(x == 2) {
                    ll l = 0, r = 1e8;

                    while(l < r) {
                        ll lm = (l+r) >> 1;
                        if(lm * lm >= c[to]) r = lm;
                        else l = lm+1;
                    }

                    d[i] = l;
                    assert(l * l == c[to]);
                }
            }
        }

        cout << d[i] << " ";
    }

	
    return 0;
}


