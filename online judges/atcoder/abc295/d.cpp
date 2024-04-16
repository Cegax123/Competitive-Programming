#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define pb push_back
#define all(c) (c).begin(), (c).end()

int main() {
    string s; cin >> s;
    int n = s.size();
    int mask = (1 << 10);

    vector<ll> dp(mask, 0);

    dp[0] = 0;

    ll ans = 0;

    for(int i = 1; i <= n; i++) {
        vector<ll> ndp(mask, 0);
        int dig = s[i-1] - '0';
        ndp[1 << dig] = 1;
        for(int j = 0; j < mask; j++) {
            ndp[j ^ (1 << dig)] += dp[j];
        }

        //for(int j = 0; j < mask; j++) {
            //cout << ndp[j] << " ";
        //}
        //cout << endl;
        ans += ndp[0];
        dp = ndp;
    }

    cout << ans << "\n";

    return 0;
}
