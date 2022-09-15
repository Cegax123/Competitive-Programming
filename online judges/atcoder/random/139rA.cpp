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
    int t[n];

    for(int i = 0; i < n; i++) 
        cin >> t[i];

    ll ans = (1ll << t[0]);

    for(int i = 1; i < n; i++) {
        if(t[i] < t[i-1]) 
            ans |= (1ll << t[i]);
        else {
            bool add = ((ans >> t[i])&1) ? 1 : 0;
            ans &= -(1ll << t[i]);
            if(add) ans += (1ll << (t[i]+1));
            ans |= (1ll << t[i]);
        }
    }

    cout << ans << "\n";
	
    return 0;
}


