#include <bits/stdc++.h>
#include <vector>
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
	
	int n; cin >> n;

    int a[n][n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) 
            for(int k = 0; k < n; k++)
                cin >> a[i][j][k];

    int ans = -INF;
    for(int l1 = 0; l1 < n; l1++) {
        for(int l2 = 0; l2 < n; l2++) {
            vector<vi> b(n, vi(n, 0));
            for(int r1 = l1; r1 < n; r1++) {
                vi d(n, 0);
                for(int r2 = l2; r2 < n; r2++) {
                    for(int i = 0; i < n; i++)
                        d[i] += a[r1][r2][i];

                    vi curr(n, 0);

                    for(int i = 0; i < n; i++)
                        curr[i] = d[i] + b[r2][i];
                    
                    int local = -INF;

                    for(int k = 0; k < n; k++) {
                        local = max(local+curr[k], curr[k]);
                        ans = max(ans, local);
                    }
                    
                    for(int i = 0; i < n; i++)
                        b[r2][i] += d[i];
                }
            }
        }
    }

    cout << ans << "\n";
	
	return 0;
}

