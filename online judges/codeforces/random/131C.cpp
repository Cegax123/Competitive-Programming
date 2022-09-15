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

    const int maxn = 55;
	
    ll C[maxn+1][maxn+1];
	
    for(int i = 0; i <= maxn; i++) {
        for(int j = 0; j <= maxn; j++) {
            if(j > i) C[i][j] = 0;
            else if(i == j or j == 0) C[i][j] = 1;
            else C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }

    int n, m, t; cin >> n >> m >> t;

    ll ans = 0;

    for(int b = 4; b <= n; b++) {
        int g = t-b;
        if(g < 1 or g > m) continue;

        ans += C[n][b] * C[m][g];
    }

    cout << ans << "\n";

	
	return 0;
}

