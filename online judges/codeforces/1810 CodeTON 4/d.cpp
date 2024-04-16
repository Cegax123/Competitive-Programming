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

pair<ll, ll> find(ll a, ll b, ll n) {
    if(n == 1) return {1, a};
    ll L = a-b;
    ll currL = a + L * (n-2) + 1, currR = a + L * (n-1);
    return {currL, currR};
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int q; cin >> q;
        ll L = 1, R = (ll) 1e18;
        while(q--) {
            int op; cin >> op;
            if(op == 1) {
                ll a, b, n; cin >> a >> b >> n;

                ll currL, currR;

                tie(currL, currR) = find(a, b, n);

                if(currR < L or R < currL) {
                    cout << 0 << " ";
                    continue;
                }
                cout << 1 << " ";
                R = min(currR, R);
                L = max(currL, L);

                //cout << currR << " " << currL << endl;

                //cout << L << " " << R << endl;
            }
            else {
                ll a, b; cin >> a >> b;

                ll l = 1, r = R / (a-b) + 10;

                //cout << L << " " << R << endl;

                while(l < r) {
                    ll m = (l+r) >> 1;
                    if(find(a, b, m).second >= L) r = m;
                    else l = m+1;
                }


                
                if(find(a, b, l+1).first <= R) cout << -1 << " ";
                else cout << l << " ";
            }
        }
        cout << "\n";
    }

	
    return 0;
}


