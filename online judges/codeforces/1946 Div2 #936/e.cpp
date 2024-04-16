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
const int maxn = 2e5 + 5;
int f[maxn], ivf[maxn];

int ex(int a, int b, int c) {
    int ans = 1;
    while(b) {
        if(b&1) ans = ans * 1ll * a % c;
        a = a * 1ll * a % c;
        b >>= 1;
    }

    return ans;
}

void gen() {
    f[0] = 1;
    for(int i = 1; i < maxn; i++) {
        f[i] = f[i-1] * 1ll * i % mod;
    }

    ivf[maxn-1] = ex(f[maxn-1], mod-2, mod);
    for(int i = maxn-2; i >= 0; i--) {
        ivf[i] = ivf[i+1] * 1ll * (i+1) % mod;
    }
}

int comb(int n, int k) {
    return f[n] * 1ll * ivf[k] % mod * ivf[n-k] % mod;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    gen();
    int t; cin >> t;
    while(t--) {
        int n, m1, m2; cin >> n >> m1 >> m2;
        int l[m1], r[m2];
        for(int i = 0; i < m1; i++) cin >> l[i];
        for(int i = 0; i < m2; i++) cin >> r[i];

        if(l[m1-1] != r[0] or l[0] != 1 or r[m2-1] != n) {
            cout << 0 << "\n";
            continue;
        }

        vector<int> a, b;

        for(int i = 0; i + 1 < m1; i++) {
            a.push_back(l[i+1] - l[i]-1);
        }
        for(int i = 0; i + 1 < m2; i++) {
            b.push_back(r[i+1] - r[i]-1);
        }

        int mid = l[m1-1];
        int ans = comb(n-1, mid-1);

        int L = mid - 2;
        
        while(!a.empty()) {
            int x = a.back(); a.pop_back();

            ans = ans * 1ll * comb(L, x) % mod;
            ans = ans * 1ll * f[x] % mod;
            L -= x+1;
        }

        int R = n-mid-1;

        reverse(b.begin(), b.end());
        while(!b.empty()) {
            int x = b.back(); b.pop_back();

            ans = ans * 1ll * comb(R, x) % mod;
            ans = ans * 1ll * f[x] % mod;
            R -= x+1;
        }

        cout << ans << "\n";
    }

	
    return 0;
}


