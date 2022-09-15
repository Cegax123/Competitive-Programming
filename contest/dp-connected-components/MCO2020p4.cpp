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
    string a; cin >> a;
    int n = a.size();

    a = " " + a;

    int s, e; cin >> s >> e;

    const ll mod = 1e9 + 7;

    auto sum = [&](ll& a, ll b) {
        if(b < 0) return;
        a = (a+b)%mod;
    };

    ll dp[n+5][n+5];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int comp = 1; comp <= i; comp++) {
            if(i == s) {
                if(a[i] != 'R') 
                    sum(dp[i][comp], dp[i-1][comp]);
                if(a[i] != 'L') 
                    sum(dp[i][comp], dp[i-1][comp-1]);
            }
            else if(i == e) {
                sum(dp[i][comp], dp[i-1][comp]);
                sum(dp[i][comp], dp[i-1][comp-1]);
            }
            else {
                if(a[i] == 'L') {
                    // merging
                    sum(dp[i][comp], dp[i-1][comp+1] * comp);

                    // start of component
                    sum(dp[i][comp], dp[i-1][comp] * (comp-(i > s)));
                }
                else if(a[i] == 'R') {
                    // new component
                    sum(dp[i][comp], dp[i-1][comp-1] * (comp - (i>e) - (i>s)));
                    
                    // end of component
                    sum(dp[i][comp], dp[i-1][comp] * (comp - (i>e)));
                }
                else {
                    int after_points = (i > e) + (i > s);
                    
                    // new component
                    sum(dp[i][comp], dp[i-1][comp-1] * (comp - after_points));

                    // merging
                    sum(dp[i][comp], dp[i-1][comp+1] * comp);

                    // add to component
                    sum(dp[i][comp], dp[i-1][comp] * (2 * comp - after_points));
                }
            }
        }
    }

    cout << dp[n][1] << "\n";
	
    return 0;
}


