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
    int n, m; cin >> n >> m;
    int a[n][m];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    int ul[n][m], ur[n][m], dl[n][m], dr[n][m];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            ul[i][j] = a[i][j];
            if(i) ul[i][j] = max(ul[i][j], ul[i-1][j]);
            if(j) ul[i][j] = max(ul[i][j], ul[i][j-1]);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = m-1; j >= 0; j--) {
            ur[i][j] = a[i][j];
            if(i) ur[i][j] = max(ur[i][j], ur[i-1][j]);
            if(j != m-1) ur[i][j] = max(ur[i][j], ur[i][j+1]);
        }
    }

    for(int i = n-1; i >= 0; i--) {
        for(int j = 0; j < m; j++) {
            dl[i][j] = a[i][j];
            if(i != n-1) dl[i][j] = max(dl[i][j], dl[i+1][j]);
            if(j) dl[i][j] = max(dl[i][j], dl[i][j-1]);
        }
    }

    for(int i = n-1; i >= 0; i--) {
        for(int j = m-1; j >= 0; j--) {
            dr[i][j] = a[i][j];
            if(i != n-1) dr[i][j] = max(dr[i][j], dr[i+1][j]);
            if(j != m-1) dr[i][j] = max(dr[i][j], dr[i][j+1]);
        }
    }

    int ans = -2e9;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i and j) ans = max(ans, a[i][j] + ul[i-1][j-1]);
            if(i and j != m-1) ans = max(ans, a[i][j] + ur[i-1][j+1]);
            if(i != n-1 and j) ans = max(ans, a[i][j] + dl[i+1][j-1]);
            if(i != n-1 and j != m-1) ans = max(ans, a[i][j] + dr[i+1][j+1]);
        }
    }

    cout << ans << "\n";
   
    return 0;
}


