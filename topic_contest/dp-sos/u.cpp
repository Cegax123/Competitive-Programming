// SOLVED

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
    ii dp[1 << n];

    for(int i = 0; i < (1 << n); i++) {
        int a; cin >> a;
        dp[i] = {a, -1};
    }

    for(int i = 0; i < n; i++) {
        for(int mask = 0; mask < (1 << n); mask++) {
            if(mask & (1 << i)) {
                int x = mask^(1 << i);
                vi tmp;

                tmp.pb(dp[mask].first);
                tmp.pb(dp[mask].second);
                tmp.pb(dp[x].first);
                tmp.pb(dp[x].second);

                sort(all(tmp));

                dp[mask] = {tmp[3], tmp[2]};
            }
        }
    }

    int globalmax = dp[0].first + dp[0].second;
    for(int i = 1; i < (1 << n); i++) {
        int local = dp[i].first+dp[i].second;

        globalmax = max(globalmax, local);
        
        cout << globalmax << "\n";
    }


	return 0;
}


