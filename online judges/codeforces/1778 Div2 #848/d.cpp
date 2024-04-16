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

    const ll mod = (ll) 1e9 + 7;
    const int maxn = 3005;

    ll p2[maxn];

    p2[0] = 1;

    for(int i = 1; i < maxn; i++)
        p2[i] = (p2[i-1] * 2) % mod;

    int n; cin >> n;
    int a[n+1];

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll ans = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            int l = 1, r = n;
            int curr = 0;

            while(l < r) {
                int m = (l+r+1) >> 1;
                if(a[m] < 2 * a[i] - a[j]) l = m;
                else r = m-1;
            }

            if(a[l] < 2 * a[i] - a[j]) curr += l;
            
            l = 1, r = n;

            while(l < r) {
                int m = (l+r) >> 1;

                if(a[m] >= 2 * a[j] - a[i]) r = m;
                else l = m+1;
            }

            if(a[l] >= 2 * a[j] - a[i]) curr += n-l+1;

            ans = (ans + p2[curr]) % mod;
        }
    }

    cout << ans << "\n";
	
    return 0;
}


