// SOLVED

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

const int L = 16;
const int MASK = (1 << L) - 1;
const ll mod = 1e9+7;

int val(char x) {
    if(x >= '0' and x <= '9') return x-'0';
    return (x-'A')+10;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int n = s.size();
        ll T = (ll) n * (n+1) / 2;

        int last[n][L];
        memset(last, -1, sizeof(last));

        vector<ll> f(1 << L, 0);

        last[0][val(s[0])] = 0;
        f[1 << val(s[0])]++;

        for(int i = 1; i < n; i++) {
            int x = val(s[i]);

            for(int j = 0; j < L; j++) {
                if(x == j) last[i][j] = i;
                else last[i][j] = last[i-1][j];
            }

            vector<bool> vis(L, 0);
            vis[x] = 1;

            int mask = (1 << x);
            int pos = i;

            while(pos >= 0) {

                int nxt = -1;
                int c = 0;

                for(int j = 0; j < L; j++) {
                    if(not vis[j] and nxt < last[pos][j]) {
                        nxt = last[pos][j];
                        c = j;
                    }
                }

                f[mask] = (f[mask] + pos-nxt) % mod;

                pos = nxt;
                mask |= (1 << c);
                vis[c] = 1;
            }

        }


        // for(int i = 0; i < (1 << L); i++)
        //     cout << i << " " << f[i] << endl;

        vector<ll> g = f;

        for(int i = 0; i < L; i++) {
            for(int mask = 0; mask < (1 << L); mask++) {
                if(mask & (1 << i)) {
                    g[mask] = (g[mask] + g[mask ^ (1 << i)]) % mod;
                }
            }
        }

        for(int i = 0; i < (1 << L); i++) {
            g[i] = (T-g[i]) % mod;
            if(g[i] < 0) g[i] += mod;
        }

        ll ans = 0;
        for(int i = 0; i < (1 << L); i++)
            ans = (ans + (f[i] * g[MASK ^ i]) % mod) % mod;

        cout << ans << "\n";
    }
	
	return 0;
}

