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


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;

    const int maxn = 100;
    double dp[maxn+5];
    dp[1] = 21.0/6.0;

    for(int i = 2; i <= n; i++) {
        dp[i] = 0.0;
        double sum = 0.0;
        
        for(int d = 6; d >= 1; d--) {
            sum += d;
            double curr = sum / 6.0 + (double) (d-1) * dp[i-1] / 6.0;
            dp[i] = max(dp[i], curr);
        }
    }
	
    cout << setprecision(12) << fixed;
    cout << dp[n] << "\n";

    return 0;
}


