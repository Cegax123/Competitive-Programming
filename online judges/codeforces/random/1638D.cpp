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

int n, m; 
int b[maxn][maxn];

bool comp(int x, int y) {
    int curr = 0;
    
    if(b[x][y]) {
        if(curr and b[x][y] != curr) return 0;
        else if(curr == 0) curr = b[x][y];
    }

    if(b[x+1][y]) {
        if(curr and b[x+1][y] != curr) return 0;
        else if(curr == 0) curr = b[x+1][y];
    }

    if(b[x][y+1]) {
        if(curr and b[x][y+1] != curr) return 0;
        else if(curr == 0) curr = b[x][y+1];
    }

    if(b[x+1][y+1]) {
        if(curr and b[x+1][y+1] != curr) return 0;
        else if(curr == 0) curr = b[x+1][y+1];
    }
    
    return true;
}

int get_color(int x, int y) {
    int curr = 0;

    curr = max({b[x][y], b[x+1][y], b[x+1][y+1], b[x][y+1]});

    return curr;
}

bool valid(int x, int y) {
    if(x >= 0 and x < n-1 and y >= 0 and y < m-1) return 1;
    return 0;
}

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct Move {
    int x, y, k;
};

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }
	
    queue<ii> q;
    vector<Move> ans;
    bool used[n][m];
    memset(used, 0, sizeof(used));

    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < m-1; j++) {
            if(comp(i, j)) {
                q.push({i, j});
                used[i][j] = 1;
            }
        }
    }


    while(!q.empty()) {
        ii p = q.front(); q.pop();
        int x = p.first, y = p.second;

        int col = get_color(x, y);
        if(col) ans.pb({x, y, get_color(x, y)});

        b[x][y] = b[x+1][y] = b[x][y+1] = b[x+1][y+1] = 0;

        for(int i = 0; i < 8; i++) {
            int nx = x+dx[i], ny = y+dy[i];
            
            if(valid(nx, ny) and !used[nx][ny] and comp(nx, ny)) {
                used[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }

    bool cmp = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(b[i][j]) cmp = 0;
            // cout << b[i][j] << " ";
        }
        // cout << "\n";
    }

    if(cmp == 0) {
        cout << "-1\n";
        return 0;
    }

    reverse(all(ans));

    cout << ans.size() << "\n";
    for(int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i].x+1 << " " << ans[i].y+1 << " " << ans[i].k << "\n";
    }
	
	return 0;
}

