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

const int maxn = 1000+5;
const int maxk = 3;

const int d = 4;
const int dx[d] = {1,-1,0,0};
const int dy[d] = {0,0,1,-1};

bool reach[maxn][maxn][d][maxk];
int n, m;

struct Pos {
	int x,y,cd,ck;
};

bool valid(int x, int y) {
	return 0 <= x and x < n and 0 <= y and y < m;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;

	char board[maxn][maxn];
	memset(reach, 0, sizeof(reach));

	for(int i = 0; i < n; i++)
		cin >> board[i];

	int sx, sy;
	int ex, ey;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(board[i][j] == 'S') {
				sx = i;
				sy = j;
			}
			if(board[i][j] == 'T') {
				ex = i;
				ey = j;
			}
		}
	}

	queue<Pos> q;

	Pos init[4];
	for(int i = 0; i < d; i++) {
		reach[sx][sy][i][0] = 1;
		init[i] = {sx, sy, i, 0};
		q.push(init[i]);
	}

	while(!q.empty()) {
		Pos v = q.front(); q.pop();

		// cout << v.x << " " << v.y << " " << v.cd << " " << v.ck << endl;

		for(int i = 0; i < d; i++) {
			int nx = v.x + dx[i];
			int ny = v.y + dy[i];

			if(!valid(nx, ny)) continue;
			if(board[nx][ny] == '*') continue;

			if(i == v.cd) {
				if(!reach[nx][ny][i][v.ck]) {
					reach[nx][ny][i][v.ck]=1;
					q.push({nx,ny,i,v.ck});
				}
			}
			else {
				if(v.ck+1 < maxk and !reach[nx][ny][i][v.ck+1]) {
					reach[nx][ny][i][v.ck+1]=1;
					q.push({nx,ny,i,v.ck+1});
				}
			}
		}
	}

	bool ans = 0;

	for(int i = 0; i < d; i++) {
		for(int j = 0; j < maxk; j++) {
			ans |= reach[ex][ey][i][j];
		}
	}

	cout << (ans?"YES":"NO");
	
	return 0;
}