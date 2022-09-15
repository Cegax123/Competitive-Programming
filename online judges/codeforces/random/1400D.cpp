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
        int n; cin >> n;
        int a[n], cnt[n][n];

        for(int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
        } 

        for(int num = 0; num < n; num++) {
            cnt[num][0] = 0;
            if(a[0] == num) cnt[num][0]++;

            for(int i = 1; i < n; i++) {
                cnt[num][i] = cnt[num][i-1];
                if(a[i] == num) cnt[num][i]++;
            }
        }

        ll sum[n][n];

        for(int j = 0; j < n; j++)
            sum[0][j] = cnt[a[0]][j];

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                sum[i][j] = sum[i-1][j] + cnt[a[i]][j];
            }
        }

        ll f[n][n];
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                f[i][j] = sum[i][n-1]-sum[i][j];
            }
        }

        ll ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(a[i] == a[j]) {
                    ans += f[j-1][j]-f[i][j];
                }
            }
        }

        cout << ans << "\n";
    }

	
	return 0;
}