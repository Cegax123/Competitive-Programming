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
	int n, s; cin >> n >> s;
    int a[n];

    for(int i = 0; i < n; i++)
        cin >> a[i];

    vi G(s+1, 0);

    ll ans = 0;
	
    for(int i = 0; i < n; i++) {
        G[0] = (G[0]+1) % mod;
        vi nG = G;

        for(int j = a[i]; j <= s; j++) {
            nG[j] = (nG[j]+G[j-a[i]])%mod;
        }

        G = nG;

        ans = (ans + G[s]) % mod;
    }

    cout << ans << "\n";
	
	return 0;
}

