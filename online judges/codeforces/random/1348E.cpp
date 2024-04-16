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
    int n, k; cin >> n >> k;

    int a[n], b[n];

    for(int i = 0; i < n; i++) 
        cin >> a[i] >> b[i];

    ll sumA = accumulate(a, a+n, 0ll), sumB = accumulate(b, b+n, 0ll);

    if(k == 1) {
        cout << sumA + sumB << "\n";
        return 0;
    }

    vi L(n, 0), R(n, 0);

    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= k; j++) {
            int other = k-j;

            if(a[i] >= j and b[i] >= other) {
                if(L[i] == 0) L[i] = j;
                R[i] = j;
            }
        }
    }

    ll ans = sumA / k + sumB / k;

    int l = k - (sumB % k), r = sumA % k;

    if(l > r) {
        cout << ans << "\n";
        return 0;
    }

    vi dp(k, 0);
    dp[0] = 1;
    
    for(int i = 0; i < n; i++) {
        vi ndp(k, 0);
        for(int j = 0; j < k; j++) {
            if(dp[j] == 0) continue;
            for(int t = L[i]; t <= R[i]; t++) {
                ndp[(j + t) % k] = 1;
            }
        }

        for(int i = 0; i < k; i++)
            if(ndp[i]) dp[i] = 1;
    }

    for(int i = l; i <= r; i++) {
        if(dp[i]) {
            ans++;
            break;
        }
    }

    cout << ans << "\n";

    return 0;
}


