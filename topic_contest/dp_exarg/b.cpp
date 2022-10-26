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

const int maxn = 1e3+5;
const int maxw = 2e4+5;

int w[maxn], s[maxn], v[maxn];

bool cmp(int i, int j) {
    return w[i] + s[i] < w[j] + s[j];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin >> n;

    for(int i = 0; i < n; i++) 
        cin >> w[i] >> s[i] >> v[i];

    vi a(n);
    iota(all(a), 0);
    sort(all(a), cmp);

    ll ans = 0;

    vector<ll> dp(maxw, -1);
    dp[0] = 0;

    for(int i : a) {
        for(int c = maxw - 1; c >= 0; c--) {
            if(c <= s[i] and c + w[i] < maxw and dp[c] >= 0) {
                dp[c+w[i]] = max(dp[c+w[i]], dp[c] + v[i]);
            }
        }

    }

    for(int i = 0; i < maxw; i++)
        ans = max(ans, dp[i]);

    cout << ans << "\n";

    return 0;
}


