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

const int N_ITER = 500 * 500 + 5;
const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, -1, 1, 0};

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;

        auto is_valid = [&](int x, int y) {
            return x >= 0 and x < n and y >=0 and y < m;
        };



        string b[n];

        queue<ii> ghosts;
        queue<ii> pacman;

        int t[n][m];
        memset(t, -1, sizeof(t));

        ii p[n][m];
        memset(p, -1, sizeof(p));

        for(int i = 0; i < n; i++) {
            cin >> b[i];

            for(int j = 0; j < m; j++) {
                if(b[i][j] == 'P') {
                    pacman.push({i, j});
                    t[i][j] = 0;
                }
                if(b[i][j] == 'G') ghosts.push({i, j});
            }
        }

        for(int tt = 0; tt < N_ITER; tt++) {
            vii tmp;
            while(!ghosts.empty()) {
                tmp.pb(ghosts.front());ghosts.pop();
            }

            for(ii v : tmp) {
                int x = v.first, y = v.second;
                for(int d = 0; d < 4; d++) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if(!is_valid(nx, ny)) continue;
                    if(b[nx][ny] == 'X' or b[nx][ny] == 'G') continue;
                    b[nx][ny] = 'G';
                    ghosts.push({nx, ny});
                }
            }

            tmp.clear();
            while(!pacman.empty()) {
                tmp.pb(pacman.front()); pacman.pop();
            }

            for(ii v : tmp) {
                int x = v.first, y = v.second;
                for(int d = 0; d < 4; d++) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if(!is_valid(nx, ny)) continue;
                    if(b[nx][ny] != '.') continue;
                    b[nx][ny] = 'P';
                    t[nx][ny] = t[x][y] + 1;
                    p[nx][ny] = {x, y};
                }
            }

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    cout << t[i][j] << " ";
                }
                cout << endl;
            }
        }
    }

	
    return 0;
}


