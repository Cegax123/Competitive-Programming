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
    int c[m+2];
    int pos[n+2];

    for(int i = 1; i <= m; i++) {
        cin >> c[i];
        pos[c[i]] = i;
    }

    const int mod = 998244353;

    c[0] = 0;
    c[n+1] = 0;

    vi L(m+2, 0), R(m+2, 0);

    L[0] = 1; R[m+1] = 1;
    ll ans = 0;
    
    for(int i = n; i >= 1; i--) {
        vi pL(m+2, 0), pR(m+2, 0);
        vi nL(m+2, 0), nR(m+2, 0);

        pL[0] = L[0], pR[m+1] = R[m+1];

        for(int j = 1; j <= m+1; j++)
            pL[j] = (L[j] + pL[j-1]) % mod;

        for(int j = m; j >= 0; j--)
            pR[j] = (R[j] + pR[j+1]) % mod;

        int x = pos[i], y = pos[i];

        for(int j = pos[i]; j >= 0; j--) {
            if(c[j] >= i) x = j;
            else break;
        }

        for(int j = pos[i]; j <= m+1; j++) {
            if(c[j] >= i) y = j;
            else break;
        }

        ans = 0;

        for(int a = x; a <= pos[i]; a++) {
            for(int b = pos[i]; b <= y; b++) {
                nL[b] = (nL[b] + pL[a-1]) % mod;
                nR[a] = (nR[a] + pR[b+1]) % mod;

                ans = ((pL[a-1] * 1ll * pR[b+1]) % mod + ans) % mod;
            }
        }
        
        nL[0] = 1;
        nR[m+1] = 1;

        L = nL;
        R = nR;

        for(int j = 1; j <= m; j++) {
            cout << L[j] << " ";
        }

        cout << "\n";

        for(int j = 1; j <= m; j++) {
            cout << R[j] << " ";
        }

        cout << "\n\n";
    }

    cout << ans << "\n";
	
    return 0;
}


