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

const int mod = 1e9 + 7;
const int maxn = 5005;

int ex(int a, int b, int c) {
    int ans = 1;
    while(b) {
        if(b&1) ans = ans * 1ll * a % c;
        a = a * 1ll * a % c;
        b >>= 1;
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int f[maxn];
    f[0] = 1;
    for(int i = 1; i < maxn; i++) f[i] = f[i-1] * 1ll * i % mod;

    int ivf[maxn];
    ivf[maxn-1] = ex(f[maxn-1], mod-2, mod);
    for(int i = maxn-2; i >= 0; i--) ivf[i] = ivf[i+1] * 1ll * (i+1) % mod;

    auto comb = [&](int n, int k) {
        return f[n] * 1ll * ivf[k] % mod * ivf[n-k] % mod;
    };

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        int c[n];
        vector<int> last(n, -1);
        vector<int> cnt(n, 0);

        for(int i = 0; i < n; i++) {
            cin >> c[i];
            c[i]--;

            if(last[c[i]] == -1) cnt[i] = 1;
            else cnt[i] = cnt[last[c[i]]] + 1;

            last[c[i]] = i;
        }

        if(k == 1) {
            cout << 1 << "\n";
            continue;
        }

        vector<pair<int, int>> bef, nxt;

        bef.push_back({-1, 1});

        int init = -1;
        for(int i = 0; i < n; i++) {
            if(cnt[i] == k) {
                nxt.push_back({i, 1});
                init = i;
                break;
            }
        }

        
        if(init == -1) {
            cout << 1 << "\n";
            continue;
        }

        //cout << init << ":\n";
        //for(auto e : bef) cout << e.first << " " << e.second << "\n";
        //cout << "---\n";
        //for(auto e : nxt) cout << e.first << " " << e.second << "\n";

        for(int i = init + 1; i < n; i++) {
            bool found_bef = 0, found_nxt = 0;
            int sum_bef = 0, sum_nxt = 0;
            int ind_bef = (int) bef.size()-1, ind_nxt = (int) nxt.size()-1;

            for(int j = i-1; j >= 0; j--) {
                if(c[i] != c[j]) continue;

                int curr = cnt[i] - cnt[j] + 1;
                
                if(curr >= k) {
                    while(ind_nxt >= 0 and nxt[ind_nxt].first >= j) {
                        ind_nxt--;
                    }

                    if(ind_nxt >= 0) {
                        found_nxt = 1;
                        sum_nxt = (sum_nxt + nxt[ind_nxt].second * comb(curr-2, k-2) % mod) % mod;
                    }

                    while(ind_bef >= 0 and bef[ind_bef].first >= j) {
                        ind_bef--;
                    }

                    if(ind_bef >= 0) {
                        found_bef = 1;
                        sum_bef = (sum_bef + bef[ind_bef].second * comb(curr-2, k-2) % mod) % mod;
                    }
                }
            }

            if(found_nxt) {
                bef = nxt;
                nxt.clear();
                nxt.push_back({i, sum_nxt});
            }
            else if(found_bef) {
                nxt.push_back({i, (nxt.back().second + sum_bef) % mod});
            }

            //cout << i << ":\n";
            //for(auto e : bef) cout << e.first << " " << e.second << "\n";
            //cout << "---\n";
            //for(auto e : nxt) cout << e.first << " " << e.second << "\n";
        }

        int ans = nxt.back().second;

        cout << ans << "\n";
    }

	
    return 0;
}


