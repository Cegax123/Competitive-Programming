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
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    const int LOGN = 30;
    const int mod = 998244353;

    int ans = 0;

    for(int b = 0; b < LOGN; b++) {
        int sum0 = 0, sum1 = 0;
        int cnt0 = 1, cnt1 = 0;

        int curr = 0;

        for(int i = 0; i < n; i++) {
            sum0 += cnt0;
            sum1 += cnt1;

            sum0 %= mod;
            sum1 %= mod;

            curr ^= (a[i] >> b)&1;

            if(curr) {
                ans += (1 << b) * 1ll * sum0 % mod;
                ans %= mod;
                cnt1++;
            }
            else {
                ans += (1 << b) * 1ll * sum1 % mod;
                ans %= mod;
                cnt0++;
            }
        }
    }

    cout << ans << "\n";


    return 0;
}


