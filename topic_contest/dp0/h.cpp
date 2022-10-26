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
	int n, w; cin >> n >> w;
    int v[n+1], c[n+1]; 

    for(int i = 1; i <= n; i++)
        cin >> v[i] >> c[i];

    int dp[w+1];
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= w; i++) {
        for(int j = 1; j <= n; j++) {
            if(c[j] <= i) dp[i] = max(dp[i], dp[i-c[j]]+v[j]);
        }
    }

    cout << dp[w] << "\n";
	
	return 0;
}

