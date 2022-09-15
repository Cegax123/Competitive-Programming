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

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, m; 

bool isValid(int x, int y) {
	if(x >= 0 and x < n and y >= 0 and y < m) return 1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while(t--) {
		cin >> n >> m;
		char board[n+5][m+5];

		for(int i = 0; i < n; i++)
			cin >> board[i];

		int x=0, y=0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(board[i][j] == 'L') {
					x = i; y = j;
				}
			}
		}

		queue<ii> q;
		q.push({x, y});

		while(!q.empty()) {
			auto v = q.front(); q.pop();
			int cx = v.first, cy = v.second;

			for(int d = 0; d < 4; d++) {
				int tox = cx+dx[d], toy = cy+dy[d];

				if(!isValid(tox, toy)) continue;
				if(board[tox][toy] != '.') continue;

				int cnt = 0;

				for(int i = 0; i < 4; i++) {
					int ntox = tox+dx[i], ntoy = toy+dy[i];
					if(!isValid(ntox, ntoy)) continue;
					if(board[ntox][ntoy] == '.') cnt++;
				}

				if(cnt <= 1) {
					q.push({tox, toy});
					board[tox][toy] = '+';
				}
			}
		}

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cout << board[i][j];
			}
			cout << "\n";
		}
	}
	
	
	return 0;
}
