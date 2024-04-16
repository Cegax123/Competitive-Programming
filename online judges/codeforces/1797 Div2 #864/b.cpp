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
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        int b[n][n];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) cin >> b[i][j];
        }

        int c[n][n];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) c[i][j] = b[n-1-i][n-1-j];
        }

        int cnt = 0;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(b[i][j] == 0 and c[i][j] == 1) cnt++;

        string ans = "NO\n";

        if(cnt <= k) {
            if(n&1) ans = "YES\n";
            else {
                if(cnt % 2 == k % 2) ans = "YES\n";
            }
        }

        cout << ans;
    }

	
    return 0;
}


