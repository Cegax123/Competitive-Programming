// SOLVED

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

const int maxn = 5000+15;

int board[maxn][maxn];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(board, 0, sizeof(board));

	int n, m; cin >> n >> m;
	
	for(int i = 0; i < m; i++) {
		int a, b, x; cin >> a >> b >> x;
		a--; b--;
		
		board[a][b]++;
		board[a][b+1]--;
		
		board[a+x+1][b]--;
		board[a+x+2][b+1]++;
		
		board[a+x+1][b+x+2]++;
		board[a+x+2][b+x+2]--;
	}
	
	for(int i = 0; i < n; i++) 
		for(int j = 1; j <= i; j++) 
			board[i][j] += board[i][j-1];

	for(int i = 0; i < n; i++) {
		int x = i, nx = i+1;
		int y = i;
		while(nx < n) {
			board[nx][y] += board[x][y];
			x = nx;
			nx = x+1;
		}
	}
	
	for(int i = 0; i < n; i++) {
		int x = i, y = 0;
		int nx = x+1, ny = y+1;
		while(nx < n and ny < n) {
			board[nx][ny] += board[x][y];
			x = nx, y = ny;
			nx = x+1, ny = y+1;
		}
	}
	
	int cnt = 0;
	
	for(int i = 0; i < n; i++) 
		for(int j = 0; j <= i; j++) 
			cnt += 1 - (board[i][j] == 0);

	cout << cnt << "\n";

	return 0;
}


