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

const ll mod = (ll) 1e9+7;
const ll INF = 1e9+5;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    ll a[n+1];
    a[0] = - INF;

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    ll dp[n+1];
    memset(dp, 0, sizeof(dp));

    ll s[n+1];
    memset(s, 0, sizeof(s));

    dp[1] = s[1] = 0;
    dp[2] = s[2] = 1;

    for(int i = 3; i <= n; i++) {
        
    }
	
    return 0;
}


