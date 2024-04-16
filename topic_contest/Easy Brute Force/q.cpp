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
    string b[n];

    for(int i = 0; i < n; i++)
        cin >> b[i];

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(b[i][j] != '.') continue;

            queue<ii> q;
            q.push({i, j});
            b[i][j] = 'B';

            while(!q.empty()) {
                int x = q.front().first, y = q.front().second; q.pop();

                for(int d = 0; d < 4; d++) {
                    int nx = x + dx[d], ny = y + dy[d];

                    if(nx >= 0 and nx < n and ny >= 0 and ny < m and b[nx][ny] == '.') {
                        b[nx][ny] = (b[x][y] == 'B' ? 'W' : 'B');
                        q.push({nx, ny});
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; i++)
        cout << b[i] << "\n";
	
    return 0;
}


