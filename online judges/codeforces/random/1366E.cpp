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



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m; cin >> n >> m;
    int a[n], b[m];

    for(int i = 0; i < n; i++)
        cin >> a[i];

    map<int, int> ind;

    for(int i = 0; i < m; i++) {
        cin >> b[i];
        ind[b[i]] = i+1;
    }

    int c[n];
    c[n-1] = a[n-1];

    for(int i = n-2; i >= 0; i--)
        c[i] = min(a[i], c[i+1]);

    int f[m], e[m];

    memset(f, -1, sizeof(f));
    memset(e, -1, sizeof(e));

    for(int i = 0; i < n; i++) {
        int k = ind[c[i]];
        if(k) {
            if(f[k-1] == -1) f[k-1] = i;
            e[k-1] = i;
        }
    }

    bool cmp = 1;
    for(int i = 0; i < m; i++)
        if(f[i] == -1) cmp = 0;

    if(c[0] != b[0]) cmp = 0;

    if(cmp == false) {
        cout << 0 << "\n";
    }
    else {
        ll ans = 1;
        const ll mod = 998244353;

        for(int i = 1; i < m; i++) {
            ans = (ans * (ll) (e[i]-f[i]+1)) % mod;
        }
        
        cout << ans << "\n";
    }
	
    return 0;
}


