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
    ll x; cin >> x;

    ll a[n];

    for(int i = 0; i < n; i++)
        cin >> a[i];

    const ll INF = (ll) 1e18 + 100;

    ll d[n], lmt[n];

    for(int i = n-1; i >= 0; i--) {
        d[i] = x / a[i];
        x %= a[i];

        if(i == n-1) lmt[i] = INF;
        else lmt[i] = a[i+1] / a[i];
    }

    ll dp[n][n];

    for(int j = 0; j < n; j++) {
        for(int i = j; i < n; i++) {
            dp[j][i] = 0;
            for(int k = j; k <= i; k++)
                dp[j][i] += d[k];
        }
    }

    ll ans[n];



    for(int i = 0; i < n; i++) {
        ans[i] = 0;
        for(int j = 0; j <= i; j++) 
            ans[i] += d[j];

        if(d[i] == lmt[i]-1) continue;

        for(int j = 0; j <= i; j++) {
            int L = i-j+1;
            ll carry = 0;

            ll curr = 0;
            
            for(int k = 0; k < L; k++) {
                ll tmp = 0;
                if(k == L-1) tmp = d[i] + 1;

                ll sv = tmp;

                tmp -= carry;
                tmp -= d[k+i-L+1];
                
                carry = 0;
                while(tmp < 0) {
                    tmp += lmt[k+i-L+1];
                    carry++;
                }

                curr += sv + tmp;
            }

            dp[j][i] = min(dp[j][i], curr);
        }

        ans[i] = min(ans[i], dp[0][i]);

        for(int j = 1; j <= i; j++) {
            ans[i] = min(ans[i], ans[j-1] + dp[j][i]);
        }
    }

    cout << ans[n-1] << "\n";
	
    return 0;
}


