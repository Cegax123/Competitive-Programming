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
	int n, k; cin >> n >> k;
    int a[n], b[n];

    for(int i = 0; i < n; i++)
        cin >> a[i];
	
    for(int i = 0; i < n; i++)
        cin >> b[i];
	
    bool dp[n][2];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = dp[0][1] = 1;

    for(int i = 1; i < n; i++) {
        if(dp[i-1][0]) {
            if(abs(a[i]-a[i-1]) <= k) dp[i][0] = 1;
            if(abs(b[i]-a[i-1]) <= k) dp[i][1] = 1;
        }
        if(dp[i-1][1]) {
            if(abs(a[i]-b[i-1]) <= k) dp[i][0] = 1;
            if(abs(b[i]-b[i-1]) <= k) dp[i][1] = 1;
        }
    }

    if(dp[n-1][0] or dp[n-1][1])
        cout << "Yes\n";
    else
        cout << "No\n";

	return 0;
}

