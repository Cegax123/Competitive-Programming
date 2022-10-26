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

const int maxn = 1005;
const int INF = 1e9;

int n;
int a[maxn][maxn];
int dp2[maxn][maxn], dp5[maxn][maxn];
char p2[maxn][maxn], p5[maxn][maxn];

void solve() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] == 0) {
                dp2[i][j] = 1e5;
                dp5[i][j] = 1e5;

                continue;
            }

            int cnt2 = 0;
            int tmp = a[i][j];

            while(tmp % 2 == 0) {
                tmp /= 2;
                cnt2++;
            }

            int cnt5 = 0;
            
            while(tmp % 5 == 0) {
                tmp /= 5;
                cnt5++;
            }

            if(i == 0 and j == 0) {
                dp2[i][j] = cnt2;
                dp5[i][j] = cnt5;
            }

            else if(j == 0) {
                dp2[i][j] = dp2[i-1][j] + cnt2;
                p2[i][j] = 'D';

                dp5[i][j] = dp5[i-1][j] + cnt5;
                p5[i][j] = 'D';
            }
            else if(i == 0) {
                dp2[i][j] = dp2[i][j-1] + cnt2;
                p2[i][j] = 'R';

                dp5[i][j] = dp5[i][j-1] + cnt5;
                p5[i][j] = 'R';
            }
            else {
                if(dp2[i-1][j] < dp2[i][j-1]) {
                    dp2[i][j] = dp2[i-1][j] + cnt2;
                    p2[i][j] = 'D';
                }
                else {
                    dp2[i][j] = dp2[i][j-1] + cnt2;
                    p2[i][j] = 'R';
                }

                if(dp5[i-1][j] < dp5[i][j-1]) {
                    dp5[i][j] = dp5[i-1][j] + cnt5;
                    p5[i][j] = 'D';
                }
                else {
                    dp5[i][j] = dp5[i][j-1] + cnt5;
                    p5[i][j] = 'R';
                }

            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;

    bool cmp = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 0) cmp = 1;
        }
    }
	
    solve();

    int ans2 = dp2[n-1][n-1], ans5 = dp5[n-1][n-1];

    if(cmp and ans2 and ans5) {
        int x, y;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(a[i][j] == 0) x = i, y = j;
            }
        }

        string path = "";

        for(int i = 0; i < x; i++)
            path.pb('D');
        for(int j = 0; j < y; j++)
            path.pb('R');

        for(int i = x; i < n-1; i++)
            path.pb('D');
        for(int j = y; j < n-1; j++)
            path.pb('R');

        cout << 1 << "\n" << path << "\n";
        return 0;
    }

    int ans;
    string path;

    if(ans2 < ans5) {
        ans = ans2;
        int x = n-1, y = n-1;
        
        while(x or y) {
            int nx, ny;

            if(p2[x][y] == 'R') nx = x, ny = y-1;
            else nx = x-1, ny = y;

            path.pb(p2[x][y]);

            x = nx;
            y = ny;
        }   
    }
    else {
        ans = ans5;
        int x = n-1, y = n-1;
        
        while(x or y) {
            int nx, ny;

            if(p5[x][y] == 'R') nx = x, ny = y-1;
            else nx = x-1, ny = y;

            path.pb(p5[x][y]);

            x = nx;
            y = ny;
        }   
    }

    reverse(all(path));
    cout << ans << "\n" << path << "\n";
	
	return 0;
}

