#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k; cin >> n >> m >> k;
    set<int> rows, cols;

    int d[n][m];
    memset(d, 0, sizeof(d));

    string b[n];

    for(int i = 0; i < n; i++) cin >> b[i];

    for(int i = 0; i < n * m; i++) {
        rows.insert(i);
        cols.insert(i);
    }

    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    x1--; y1--; x2--; y2--;

    queue<pair<int, int>> q;
    q.push({x1, y1});



    while(!q.empty()) {
        int x = q.front().first, y = q.front().second; q.pop();
        //cout << x << " " << y << endl;

        int L = x * m + max(y-k, 0), R = x * m + min(y+k, m-1);

        rows.insert(x * m + y);
        auto it = rows.find(x * m + y);

        vector<pair<int, int>> to_delete;

        it = next(it);
        if(it != rows.end()) {

            while(true) {
                if((*it) > R) break;
                int nx = (*it)/m, ny = (*it)%m;
                if(b[nx][ny] == '#') break;

                to_delete.push_back({nx, ny});
                d[nx][ny] = d[x][y] + 1;
                q.push({nx, ny});
                it = next(it);

                if(it == rows.end()) break;
            }
        }

        it = rows.find(x * m + y);
        if(it != rows.begin()) {
            it = prev(it);

            while(true) {
                if((*it) < L) break;
                int nx = (*it)/m, ny = (*it)%m;
                if(b[nx][ny] == '#') break;

                to_delete.push_back({nx, ny});
                d[nx][ny] = d[x][y] + 1;
                q.push({nx, ny});

                if(it == rows.begin()) break;
                it = prev(it);
            }
        }

        rows.erase(x * m + y);

        L = max(x-k, 0) + n * y, R = min(x+k, n-1) + n * y;

        cols.insert(x + n * y);

        it = cols.find(x + n * y);
 
        it = next(it);
        if(it != cols.end()) {

            while(true) {
                if((*it) > R) break;
                int nx = (*it)%n, ny = (*it)/n;
                if(b[nx][ny] == '#') break;

                to_delete.push_back({nx, ny});
                d[nx][ny] = d[x][y] + 1;
                q.push({nx, ny});
                it = next(it);
                if(it == cols.end()) break;
            }
        }

        it = cols.find(x + n * y);
        if(it != cols.begin()) {
            it = prev(it);

            while(true) {
                if((*it) < L) break;
                int nx = (*it)%n, ny = (*it)/n;
                if(b[nx][ny] == '#') break;

                to_delete.push_back({nx, ny});
                d[nx][ny] = d[x][y] + 1;
                q.push({nx, ny});
                if(it == cols.begin()) break;
                it = prev(it);
            }
        }

        cols.erase(x + n * y);

        for(auto e : to_delete) {
            int a = e.first, b = e.second;
            //cout << x << " " << y << " " << a << " " << b << endl;
            rows.erase(a * m + b);
            cols.erase(a + n * b);
        }
    }

    if(x1 == x2 and y1 == y2) cout << 0 << "\n";
    else cout << (d[x2][y2] == 0 ? -1 : d[x2][y2]) << "\n";

    return 0;
}
