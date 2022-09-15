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

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int h, w;

bool valid(int x, int y) {
	if(x >= 0 and x < h and y >= 0 and y < w) return 1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> h >> w;
	char board[h][w];

	for(int i = 0; i < h; i++) 
		for(int j = 0; j < w; j++) 
			cin >> board[i][j];


	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			if(board[i][j] != '.') continue;
			
			vector<bool> vis(5, 0);

			for(int d = 0; d < 4; d++) {
				int nx = i + dx[d], ny = j + dy[d];
				if(valid(nx, ny) and board[nx][ny] != '.') {
					vis[board[nx][ny]-'1']=1;
				}
			}

			for(int k = 0; k < 5; k++) {
				if(!vis[k]) {
					board[i][j] = k+'1';
					break;
				} 
			}
		}
	}

	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			cout << board[i][j];
		}
		cout << "\n";
	}

	return 0;
}
