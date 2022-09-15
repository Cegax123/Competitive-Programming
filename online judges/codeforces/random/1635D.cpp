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

const int maxn = 2e5+5;
const ll mod = 1e9+7;

ll sum(ll a, ll b) {return (a+b)%mod;}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int dp[maxn];
    dp[0] = dp[1] = 1;

    for(int i = 2; i < maxn; i++)
        dp[i] = sum(dp[i-1], dp[i-2]);

    for(int i = 1; i < maxn; i++)
        dp[i] = sum(dp[i], dp[i-1]);

    int n, p; cin >> n >> p;

    set<int> s;
    vi a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(all(a));

    for(int i = 0; i < n; i++) {
        int x = a[i];

        if(s.count(x)) continue;

        bool found = 0;
        while(x) {
            if(x&1) {
                x >>= 1;
            }
            else if((x&1) == 0 and ((x >> 1)&1) == 0) {
                x >>= 2;
            }
            else break;

            if(s.count(x)) 
                found = 1;
        }

        if(!found) s.insert(a[i]);
    }

    ll ans = 0;

    for(int x : s) {
        int cnt = 0;

        while(x) {
            cnt++; 
            x >>= 1;
        }

        if(p-cnt >= 0) ans = sum(ans, dp[p-cnt]);
    }

    cout << ans << "\n";

	return 0;
}

