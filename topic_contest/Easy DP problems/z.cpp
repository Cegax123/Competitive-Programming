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
	
    memset(ul, 0, sizeof(ul));
    memset(ur, 0, sizeof(ur));
    memset(dl, 0, sizeof(dl));
    memset(dr, 0, sizeof(dr));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 and j == 0) ul[i][j] = a[i][j];
            if(i) ul[i][j] = max(ul[i][j], ul[i-1][j] + a[i][j]);
            if(j) ul[i][j] = max(ul[i][j], ul[i][j-1] + a[i][j]);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = m-1; j >= 0; j--) {
            if(i == 0 and j == m-1) ur[i][j] = a[i][j];
            if(i) ur[i][j] = max(ur[i][j], ur[i-1][j] + a[i][j]);
            if(j != m-1) ur[i][j] = max(ur[i][j], ur[i][j+1] + a[i][j]);
        }
    }

    for(int i = n-1; i >= 0; i--) {
        for(int j = 0; j < m; j++) {
            if(i == n-1 and j == 0) dl[i][j] = a[i][j];
            if(i != n-1) dl[i][j] = max(dl[i][j], dl[i+1][j] + a[i][j]);
            if(j) dl[i][j] = max(dl[i][j], dl[i][j-1] + a[i][j]);
        }
    }

    for(int i = n-1; i >= 0; i--) {
        for(int j = m-1; j >= 0; j--) {
            if(i == n-1 and j == m-1) dr[i][j] = a[i][j];
            if(i != n-1) dr[i][j] = max(dr[i][j], dr[i+1][j] + a[i][j]);
            if(j != m-1) dr[i][j] = max(dr[i][j], dr[i][j+1] + a[i][j]);
        }
    }

    int ans = 0;
    for(int i = 1; i+1 < n; i++) {
        for(int j = 1; j+1 < m; j++) {
            ans = max({ans, ul[i-1][j] + dr[i+1][j] + dl[i][j-1] + ur[i][j+1], ul[i][j-1] + dr[i][j+1] + dl[i+1][j] + ur[i-1][j]});
        }
    }

    cout << ans << "\n";

    return 0;
}


