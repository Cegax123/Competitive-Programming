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
	int n; cin >> n;

    int a[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
	
    int ans = 0;
    for(int i = 0; i < n; i++) {
        vi b(n, 0);
        for(int j = i; j < n; j++) {
            for(int k = 0; k < n; k++)
                b[k] += a[j][k];
            
            int local = b[0];
            ans = max(ans, local);

            for(int k = 1; k < n; k++) {
                local = max(local + b[k], b[k]);
                ans = max(ans, local);
            }
        }
    }

    cout << ans << "\n";
	
	return 0;
}

