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
    int c[10];

    for(int i = 0; i < 10; i++) 
        cin >> c[i];

    ll ans = 0;
    for(int mask = 1; mask < (1 << 10); mask++) {
        ll local = 0;
        int cost = 0;
        for(int j = 8; j >= 0; j--) {
            if((mask >> j) & 1) {
                local = local * 10 + (j+1);
                cost += c[j];
            }
        }
        if(cost <= n) ans = max(ans, local);
    }

    cout << ans << "\n";
	
    return 0;
}


