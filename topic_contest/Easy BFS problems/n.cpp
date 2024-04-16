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
    int r, c; cin >> r >> c;
    string b[r];

    for(int i = 0; i < r; i++) cin >> b[i];

    int x = 0, y = 0;
    int xe = 0, ye = 0;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(b[i][j] == 'E') {
                x = i; y = j;
            }
            else if(b[i][j] == 'S') {
                xe = i; ye = j;
            }
        }
    }

    int d[r][c];

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            d[i][j] = 1e9;

    d[x][y] = 0;

    queue<pair<int, int>> q;
    q.push({x, y});
    
    const int dx[] = {-1, 1, 0, 0};
    const int dy[] = {0, 0, 1, -1};

    while(!q.empty()) {
        int x = q.front().first, y = q.front().second; q.pop();

        for(int j = 0; j < 4; j++) {
            int nx = x + dx[j], ny = y + dy[j];

            if(nx < 0 or nx >= r or ny < 0 or ny >= c or b[nx][ny] == 'T' or d[nx][ny] < 1e9) continue;

            d[nx][ny] = d[x][y] + 1;
            q.push({nx, ny});
        }
    }

    int ans = 0;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(b[i][j] >= '0' and b[i][j] <= '9' and d[i][j] <= d[xe][ye]) 
                ans += b[i][j] - '0';
        }
    }

    cout << ans << "\n";
	
    return 0;
}


