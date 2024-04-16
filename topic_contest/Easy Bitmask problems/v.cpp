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
    set<ll> s;

    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        s.insert(x);
    }

    vi ans;

    ans.pb(*s.begin());

    for(ll x : s) {
        for(int j = 0; j < 35; j++) {
            if(s.count(x + (1ll << j)) and s.count(x + (1ll << (j+1)))) {
                ans.clear();
                ans.pb(x);
                ans.pb(x + (1ll << j));
                ans.pb(x + (1ll << (j+1)));
            }
            else if(s.count(x + (1ll << j)) and (int) ans.size() == 1) {
                ans.clear();
                ans.pb(x);
                ans.pb(x + (1ll << j));
            }
        }
    }

    cout << ans.size() << "\n";

    for(ll x : ans) cout << x << " ";
	
    return 0;
}


