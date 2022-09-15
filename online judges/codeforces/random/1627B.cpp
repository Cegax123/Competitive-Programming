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

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, m;
bool isValid(int x, int y) {
    if(x >= 0 and x < n and y >= 0 and y < m) return true;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        int b[n][m];
        memset(b, 0, sizeof(b));

        int val = n/2 + m/2;
        if(n&1) {
            if(m&1) {
                b[n/2][m/2] = val;
            }
            else {
                b[n/2][m/2] = b[n/2][m/2-1] = val;
            }
        }
        else {
            if(m&1) b[n/2-1][m/2] = b[n/2][m/2] = val;
            else b[n/2-1][m/2-1] = b[n/2][m/2-1] = b[n/2-1][m/2] = b[n/2][m/2] = val;
        }

        vi ans;

        queue<ii> q;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(b[i][j]) {
                    q.push({i, j});
                    ans.pb(b[i][j]);
                }
            }
        }

        while(!q.empty()) {
            ii c = q.front(); q.pop();

            for(int d = 0; d < 4; d++) {
                int nx = c.first + dx[d], ny = c.second + dy[d];
                if(isValid(nx, ny) and b[nx][ny] == 0) {
                    b[nx][ny] = b[c.first][c.second]+1;
                    ans.pb(b[nx][ny]);
                    q.push({nx, ny});
                }
            }
        }

        sort(all(ans));

        for(int x : ans) 
            cout << x << " ";
        cout << "\n";
    }
	
	
	return 0;
}

