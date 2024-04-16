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
    int rh, ch; cin >> rh >> ch;
    int rw, cw; cin >> rw >> cw;

    rh--; ch--; rw--; cw--;

    const int maxn = 105;
    int b[maxn][maxn];

    const int dx[] = {1, -1, 0, 0};
    const int dy[] = {0, 0, 1, -1};

    auto is_valid = [&](int x, int y) {
        return x >= 0 and x < n and y >= 0 and y < m;
    };

    bool used[maxn][maxn];
    auto is_possible = [&]() {
        if(b[rh][ch] or b[rw][cw]) return false;

        memset(used, 0, sizeof(used));

        queue<ii> q;
        q.push({rh, ch});
        used[rh][ch] = true;

        while(!q.empty()) {
            ii v = q.front(); q.pop();
            if(v == make_pair(rw, cw)) return true;
            for(int d = 0; d < 4; d++) {
                ii nv;
                nv.first = v.first + dx[d];
                nv.second = v.second + dy[d];
                if(is_valid(nv.first, nv.second) and b[nv.first][nv.second] == 0 and !used[nv.first][nv.second]) {
                    used[nv.first][nv.second] = true;
                    q.push(nv);
                }
            }
        }
        return false;
    };

    int M[n][m];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> M[i][j];
            M[i][j]--;
        }
    }

    int ans = 10;
    int num = 0;
    for(int i = 0; i < (1 << 10); i++) {
        int cnt = 0;

        bool cont = false;;

        for(int j = 0; j < 10; j++) {
            if((i >> j)&1) {
                cnt++;
            }
        }

        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {
                if((i >> M[r][c])&1) b[r][c] = 0;
                else b[r][c] = 1;
            }
        }

            
        if(is_possible()) {
            ans = min(ans, cnt);
        }
    }

    cout << ans << endl;
	
    return 0;
}


