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

const int maxn = 505;

string b[maxn];

int col[maxn][maxn];
int id[maxn][maxn];
vector<vii> epts;

int dir(char x) {
    if(x == 'v') return 0;
    if(x == '^') return 1;
    if(x == '>') return 2;
    return 3;
}

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int T = 1;

int r, c;
vii curr;

bool is_valid(int x, int y) {
    return x >= 0 and x < r and y >= 0 and y < c;
}

void dfs(int x, int y) {
    curr.pb({x, y});
    col[x][y] = 1;

    int d = dir(b[x][y]);
    int nx = x + dx[d], ny = y + dy[d];

    if(!is_valid(nx, ny) or b[nx][ny] == '.' or b[nx][ny] == '#') {
        epts.pb(vii(1, {x, y}));
        id[x][y] = T++;
        col[x][y] = 2;
        return;
    }

    if(col[nx][ny] == 0) dfs(nx, ny);
    else if(col[nx][ny] == 1) {
        bool found = false;

        vii tmp;

        for(auto e : curr) {
            if(e == make_pair(nx, ny)) found = 1;
            if(found) tmp.pb(e);
        }

        for(auto e : tmp) id[e.first][e.second] = T;

        T++;

        epts.pb(tmp);
    }

    col[x][y] = 2;
}

int ans = 0;
int cnt[maxn][maxn];

void add(int x, int y) {
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(is_valid(nx, ny) and b[nx][ny] == '#') {
            if(cnt[nx][ny] == 0) ans++;
            cnt[nx][ny]++;
        }
    }
}

void dele(int x, int y) {
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(is_valid(nx, ny) and b[nx][ny] == '#') {
            cnt[nx][ny]--;
            if(cnt[nx][ny] == 0) ans--;
        }
    }
}

int global = 0;

//set<ii> s;
//bool cmp = true;

void tree(int x, int y) {
    global = max(global, ans);

    for(int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if(!is_valid(nx, ny) or b[nx][ny] == '.' or b[nx][ny] == '#') continue;
        if(id[x][y] and id[x][y] == id[nx][ny]) continue;
        int D = dir(b[nx][ny]);
        int nnx = nx + dx[D], nny = ny + dy[D];

        if(x == nnx and y == nny) {
            add(nx, ny);
            tree(nx, ny);
            dele(nx, ny);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> r >> c;

    for(int i = 0; i < r; i++)
        cin >> b[i];

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(b[i][j] == '.' or b[i][j] == '#') continue;
            if(col[i][j] == 0) {
                curr.clear();
                dfs(i, j);
            }
        }
    }

    //for(int i = 0; i < r; i++) {
        //for(int j = 0; j < c; j++)
            //cout << id[i][j] << " ";
        //cout << "\n";
    //}

    for(auto pts : epts) {
        for(auto e : pts) add(e.first, e.second);

        for(auto e : pts) tree(e.first, e.second);

        for(auto e : pts) dele(e.first, e.second);
    }

    cout << global << "\n";

    //cout << (cmp ? "YES\n" : "NO\n");

    return 0;
}


