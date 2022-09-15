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

const int maxn = 1e5;
const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin >> n;
    vi x(1, 0);

	for(int i = 0; i < n; i++) {
        int a; cin >> a;
        x.pb(a);
    }

    sort(all(x));

    vi dp(maxn+1, INF);

    dp[0] = 0;
    vi ans;

    for(int i = 1; i <= maxn; i++) {
        for(int j = 1; j <= n; j++) {
            if(x[j] <= i and dp[i-x[j]] < j) {
                dp[i] = j;
                break;
            }
        }

        if(dp[i] != INF) 
            ans.pb(i);
    }

    cout << ans.size() << "\n";

    for(int a : ans) {
        cout << a << " ";
    }
	
	return 0;
}

