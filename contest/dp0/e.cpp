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

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int l; cin >> l;
    int p[l];

    for(int i = 0; i < l; i++) 
        cin >> p[i];
	
    vector<ll> dp(l+1, -1e9);
    dp[0] = 0;

    for(int i = 1; i <= l; i++) {
        for(int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], dp[i-j]+p[j-1]);
        }
    }

    cout << dp[l] << "\n";
	
	return 0;
}

