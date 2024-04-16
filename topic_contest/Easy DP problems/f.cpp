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
    int b[n][m];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> b[i][j];

    int ans = 0;

    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j < m; j++)
            cnt += b[i][j];

        if(cnt == 0) continue;

        for(int j = 0; j < m; j++) {
            if(b[i][j]) {
                ans += m-j-cnt;
                break;
            }
        }

        for(int j = m-1; j >= 0; j--) {
            if(b[i][j]) {
                ans += j+1-cnt;
                break;
            }
        }
    }

    for(int j = 0; j < m; j++) {
        int cnt = 0;
        for(int i = 0; i < n; i++)
            cnt += b[i][j];

        if(cnt == 0) continue;

        for(int i = 0; i < n; i++) {
            if(b[i][j]) {
                ans += n-i-cnt;
                break;
            }
        }

        for(int i = n-1; i >= 0; i--) {
            if(b[i][j]) {
                ans += i+1-cnt;
                break;
            }
        }
    }

    cout << ans << "\n";
	
    return 0;
}


