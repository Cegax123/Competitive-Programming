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
        int n; ll x, y; cin >> n >> x >> y;
        int L = y/x;

        string a, b; cin >> a >> b;
        vi pos;

        for(int i = 0; i < n; i++) 
            if(a[i] != b[i]) pos.pb(i);

        int k = pos.size();
        if(k & 1) {
            cout << "-1\n";
            continue;
        }

        if(k == 0) {
            cout << "0\n";
            continue;
        }

        if(L == 0) {
            ll ans = 0;
            if(k == 2 and pos[0]+1 == pos[1]) {
                if(n <= 3 or (n == 4 and pos[0] == 1)) ans = x;
                else ans = min(x, 2 * y);
            }
            else 
                ans = k / 2 * y;

            cout << ans << "\n";
        }
        else {
            vector<vector<ll> > segments;

            segments.pb(vector<ll>(1, pos[0]));

            for(int i = 1; i < k; i++) {
                if(pos[i] - pos[i-1] <= L) {
                    segments.back().pb(pos[i]);
                }
                else {
                    segments.pb(vector<ll>(1, pos[i]));
                }
            }

            auto f = [](const vector<ll>& a, int l, int r, ll x) {
                int len = r-l+1;

                if(len < 0 or (len&1)) return 0ll;

                ll ans = 0;

                for(int i = l; i <= r; i+=2) {
                    ans += (a[i+1]-a[i]) * x;
                }

                return ans;
            };

            ll ans = 0;
            ll odd = 0;

            for(const vector<ll>& segm : segments) {
                int p = segm.size();
                odd += p & 1;
                
                if((p & 1) == 0) {
                    ans += f(segm, 0, segm.size()-1, x);
                }
                else {
                    ll curr = (ll) 1e18;
                    for(int j = 0; j < p; j+=2) {
                        curr = min(curr, f(segm, 0, j-1, x) + f(segm, j+1, p-1, x));
                    }
                    ans += curr;
                }
            }

            ans += odd/2 * y;
            cout << ans << "\n";
        }
    }

	
    return 0;
}



