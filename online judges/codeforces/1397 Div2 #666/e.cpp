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
    int n; ll r1, r2, r3, d; cin >> n >> r1 >> r2 >> r3 >> d;
    ll a[n];
    
    for(int i = 0; i < n; i++)
        cin >> a[i];

    ll c[n][2];

    for(int i = 0; i < n; i++) {
        c[i][0] = min(a[i] * r1 + 2 * r1, a[i] * r1 + r3);
    }

    ll dp[n][4];

    dp[0][0] = c[0][0]; // normal
    dp[0][1] = r2 + 2 * d + r1; // cerrado
    dp[0][2] = r2 + 2 * d + r1; // abierto
    dp[0][3] = r2 + 2 * d + r1; // no termina

    for(int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i-1][0] + c[i][0], 
    }
	
    return 0;
}


