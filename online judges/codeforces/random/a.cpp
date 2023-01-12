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
    const ll INF = (ll) 1e18;

    int n; cin >> n;

    ll a[n+1];
    a[0] = INF;

    for(int i = 1; i <= n; i++) cin >> a[i];

    ll dp[n+1][2];
    
    for(int i = 0; i <= n; i++) 
        dp[i][0] = dp[i][1] = INF;

    dp[0][0] = 0;

    ll ans[n+1];

    for(int i = 1; i <= n; i++) ans[i] = INF;

    for(int j = 1; j <= n; j++) {
        stack<pair<ll, ll> > st;
        st.push({INF, 0});

        for(int i = 0; i <= n; i++)
            dp[i][j&1] = INF;

        for(int i = 1; i <= n; i++) {
            ll v_i = dp[i-1][1-(j&1)];

            while(!st.empty() and a[st.top().second] <= a[i]) {
                v_i = min(v_i, st.top().first);
                st.pop();
            }

            dp[i][j&1] = min(v_i + a[i], dp[st.top().second][j&1]);
            st.push({v_i, i});

            if(i == n) ans[j] = min(ans[j], dp[i][j&1]);
        }
    }

    sort(a, a+n+1);
    reverse(a, a+n+1);

    ll sum = 0;

    for(int i = 1; i <= n; i++) {
        sum += a[i];
        cout << ans[i] << " " << sum << "\n";
    }

    return 0;
}


