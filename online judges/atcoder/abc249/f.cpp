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

const ll INF = (ll) 1e18;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n, k; cin >> n >> k;
    n++;

    ll t[n], y[n];
    t[0] = 1; y[0] = 0;
   
    for(int i = 1; i < n; i++) 
        cin >> t[i] >> y[i];

    ll ans = -INF;
    ll sum = 0;
    ll accum = 0;
    int lmt = k;
    multiset<ll> s;

    for(int i = n-1; i >= 0; i--) {
        if(t[i] == 1) {
            ans = max(ans, y[i] + accum - sum);
            lmt--;

            if(lmt < 0) break; 
        }
        else {
            accum += y[i];

            if(y[i] < 0) {
                s.insert(y[i]);
                sum += y[i];
            }
        }

        if((int) s.size() > lmt) {
            ll x = *s.rbegin();
            sum -= x;
            s.erase(s.find(x));
        }
    }

    cout << ans << "\n";
   
    return 0;
}


