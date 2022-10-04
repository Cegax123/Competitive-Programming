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
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n];

        int cnt0 = 0, cnt1 = 0;
        vector<ll> a0, a1;

        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) {
            ll b; cin >> b;

            if(a[i] == 0) {
                cnt0++;
                a0.pb(b);
            }
            else {
                cnt1++;
                a1.pb(b);
            }
        }
        
        sort(all(a0));
        reverse(all(a0));

        sort(all(a1));
        reverse(all(a1));

        if(cnt0 == cnt1) {
            ll sum = 0;
            for(ll x : a0) sum += 2 * x;
            for(ll x : a1) sum += 2 * x;

            sum -= min(a0[cnt0-1], a1[cnt1-1]);
            cout << sum << "\n";
            continue;
        }

        int k = min(cnt0, cnt1);

        ll ans = 0;
        for(int i = 0; i < k; i++) {
            ans += 2 * a0[i];
            ans += 2 * a1[i];
        }

        for(int i = k; i < a0.size(); i++)
            ans += a0[i];

        for(int i = k; i < a1.size(); i++)
            ans += a1[i];

        cout << ans << "\n";
    }

	
    return 0;
}


