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

const int maxn = 2000;

 ll dp[maxn+5];
int p[maxn+5];
//

ll s, c;

ll f(ll x) {
    if(x <= 0) return 0;

    if(dp[x] >= 0) return dp[x];

    ll ans1 = x + f(x-1);
    ll ans2 = x * c + f(x-c-1);

    dp[x] = max(ans1, ans2);

    if(ans1 > ans2) p[x] = 0;
    else if(ans1 == ans2) p[x] = 1;
    else p[x] = 2;

    return dp[x];
}


ll nt(ll x) {
    return (x * (x+1)) / 2;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> s >> c;

        memset(dp, -1, sizeof(dp));

        for(int i = 1; i <= maxn; i++) 
            f(i);

        if(s <= maxn) cout << dp[s] << "\n";
        else {
			if(c==1){
				cout<<nt(s)<<endl;
				continue;
			}
			ll ans = s*c;
	          for(int i = 1; i <= maxn; i++) {
                ans = max(ans, nt(s)-nt(i) + dp[i]);
            }  
            cout << ans << "\n";
        }
    }
	
    return 0;
}



