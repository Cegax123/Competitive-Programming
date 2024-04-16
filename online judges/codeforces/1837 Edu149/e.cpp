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

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int k; cin >> k;
    vector<vi> a;

    for(int j = 0; j <= k; j++) {
        a.pb(vi(1 << (k-j), -1));
    }

    bool cmp = 1;

    for(int i = 0; i < (1 << k); i++) {
        cin >> a[0][i];

        int t = 20;
        for(int j = 20; j >= 0; j--)
            if(a[0][i] <= (1 << j)) t = j;

        if(a[0][i] != -1) {
            int pos = i;
            for(int j = 1; j <= k-t; j++) {
                pos >>= 1;

                if(a[j][pos] != -1) cmp = 0;
                a[j][pos] = a[0][i];
            }
        }
    }

    if(cmp == 0) {
        cout << 0 << "\n";
        return 0;
    }

    const int maxn = (1 << 20) + 1000;
    int f[maxn];

    f[0] = 1;

    for(int i = 1; i < maxn; i++) 
        f[i] = f[i-1] * 1ll * i % mod;

    a[k][0] = 1;
    int ans = 1;
    
    for(int i = k; i >= 1; i--) {
        int nxt = 0;
        int opt = 1;
        for(int j = 0; j < (1 << (k-i)); j++) {
            if(a[i][j] == -1) {
                int curr = 0;
                curr += a[i-1][2 * j] == -1;
                curr += a[i-1][2 * j + 1] == -1;

                opt = opt * 1ll * curr % mod;

                nxt += curr-1;
            }
            else {
                nxt += a[i-1][2 * j] == -1;
                nxt += a[i-1][2 * j + 1] == -1;
            }
        }

        ans = ans * 1ll * opt  % mod;
        ans = ans * 1ll * f[nxt] % mod;
    }

    cout << ans << "\n";
	
    return 0;
}


