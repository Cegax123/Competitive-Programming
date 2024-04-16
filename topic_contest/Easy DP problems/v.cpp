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
    const int maxn = 5005;
    int a[maxn], b[maxn];
    int sum[n], l[n], r[n], kad[n];

    for(int i = 0; i < n; i++) {
        int k; cin >> k;

        for(int j = 0; j < k; j++)
            cin >> a[j];

        sum[i] = accumulate(a, a + k, 0);

        int local = a[0]; kad[i] = a[0];

        for(int j = 1; j < k; j++) {
            local = max(a[j], a[j] + local);
            kad[i] = max(kad[i], local);
        }

        b[0] = a[0];

        for(int j = 1; j < k; j++)
            b[j] = b[j-1] + a[j];

        l[i] = *max_element(b, b+k);

        b[k-1] = a[k-1];

        for(int j = k-2; j >= 0;j --)
            b[j] = b[j+1] + a[j];

        r[i] = *max_element(b, b+k);
    }

    int idx[m];
    for(int i = 0; i < m; i++) {
        cin >> idx[i];
        idx[i]--;
    }
    
    ll R = r[idx[0]];
    ll ans = kad[idx[0]];

    for(int tt = 1; tt < m; tt++) {
        ans = max(ans, (ll) kad[idx[tt]]);
        ans = max(ans, R + l[idx[tt]]);

        R = max(R + sum[idx[tt]], (ll) r[idx[tt]]);
        
        ans = max(ans, R);
    }

    cout << ans << "\n";
	
    return 0;
}


