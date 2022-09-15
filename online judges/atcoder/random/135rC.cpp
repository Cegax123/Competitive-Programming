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

const int L = 30;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    ll a[n];
    ll ans = 0;
    vi cnt(L, 0);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        ans += a[i];

        for(int j = 0; j < L; j++)
            if((a[i] >> j)&1)
                cnt[j]++;
    }
	
    for(int i = 0; i < n; i++) {
        ll local = 0;

        for(int j = 0; j < L; j++) {
            if((a[i] >> j) & 1) 
                local += (ll) (n-cnt[j]) * (1ll << j);
            else 
                local += (ll) cnt[j] * (1ll << j);
        }

        ans = max(ans, local);
    }

    cout << ans << "\n";

    return 0;
}


