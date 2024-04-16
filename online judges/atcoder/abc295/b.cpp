#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define pb push_back
#define all(c) (c).begin(), (c).end()

int main() {
    int r, c; cin >> r >> c;
    string b[r];
    string ans[r];

    for(int i = 0; i < r; i++) {
        cin >> b[i];
        ans[i] = b[i];
    }


    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};

    auto is_valid = [&](int x, int y) {
        return x >= 0 and x < r and y >= 0 and y < c;
    };

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(b[i][j] >= '1' and b[i][j] <= '9') {
                int x = b[i][j] - '1' + 1;

                bool used[r][c];
                memset(used, 0, sizeof(used));

                queue<ii> q;
                q.push({i, j});
                used[i][j] = 1;
                ans[i][j] = '.';

                while(!q.empty()) {
                    ii v = q.front(); q.pop();
                    int a = v.first, c = v.second;
                    for(int d = 0; d < 4; d++) {
                        int ni = a + dx[d], nj = c + dy[d];
                        if(is_valid(ni, nj) and !used[ni][nj] and abs(ni-i) + abs(nj-j) <= x) {
                            q.push({ni, nj});
                            used[ni][nj]  = 1;
                            ans[ni][nj] = '.';
                        }
                    }
                }
            }
        }
    }

    for(int i = 0 ; i < r; i++)
        cout << ans[i] << "\n";

    return 0;
}
