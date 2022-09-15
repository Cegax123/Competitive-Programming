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

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
const int INF = 1e9;
int n, m;

bool isvalid(int x, int y) {
	if(x >= 0 and x < n and y >= 0 and y < m)
		return 1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;

	char board[n+5][m+5];
	int dis[n+1][m+1];

	memset(dis, -1, sizeof(dis));

	for(int i = 0; i < n; i++)
		cin >> board[i];

	queue<pair<ii, int> > q;
	int sx, sy;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(board[i][j] == 'M') {
				q.push({{i,j},0});
				dis[i][j] = 0;
			}
			if(board[i][j] == 'A') {
				sx = i;
				sy = j;
			}
		}	
	}

	while(!q.empty()) {
		auto v = q.front(); q.pop();
		int x = v.first.first, y = v.first.second, d = v.second;

		for(int i = 0; i < 4; i++) {
			int nx = x+dx[i], ny = y+dy[i];
			if(!isvalid(nx, ny)) continue;
			if(board[nx][ny] == '#') continue;
			if(dis[nx][ny] != -1) continue;

			q.push({{nx,ny},d+1});
			dis[nx][ny] = d+1;
		}
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(dis[i][j] == -1) dis[i][j] = INF;

	q.push({{sx, sy}, 0});

	bool poss[n][m];
	bool vis[n][m];
	ii par[n][m];

	memset(vis, 0, sizeof(vis));
	memset(poss, 0, sizeof(poss));

	poss[sx][sy] = 1;
	par[sx][sy] = {-1, -1};

	while(!q.empty()) {
		auto v = q.front(); q.pop();
		
		int x = v.first.first, y = v.first.second, t = v.second;
		vis[x][y] = 1;

		for(int i = 0; i < 4; i++) {
			int nx = x+dx[i], ny = y+dy[i];
			if(!isvalid(nx, ny)) continue;
			if(vis[nx][ny] or board[nx][ny] == '#' or t+1 >= dis[nx][ny]) continue;

			q.push({{nx,ny},t+1});
			par[nx][ny] = {x, y};
			poss[nx][ny] = 1;
		}
	}

	bool ans = 0;
	int ex, ey;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(poss[i][j] and (i == n-1 or i == 0 or j == 0 or j == m-1)) {
				ans = 1;
				ex = i;
				ey = j;
			}
		}
	}

	if(!ans) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
		string path = "";

		while(true) {
			ii p = par[ex][ey];

			if(p.first == -1 and p.second == -1) break;

			if(ex+1 == p.first) path += "U";
			else if(ex-1 == p.first) path += "D";
			else if(ey+1 == p.second) path += "L";
			else path += "R";

			ex = p.first;
			ey = p.second;

		}

		reverse(all(path));

		cout << path.size() << "\n";
		cout << path << "\n";
	}
	
	return 0;
}