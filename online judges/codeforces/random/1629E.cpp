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
int n;

bool isValid(int x, int y) {
	if(x >= 0 and x < n and y >= 0 and y < n) 
		return 1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while(t--) {
		cin >> n;
		int a[n][n];

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}

		int ans = 0;
		for(int i = 0; i  < n; i+=2) {
			int x = i, y = i;
			while(isValid(x, y)) {
				x--;
				y++;
			}
			x++;
			y--;

			while(isValid(x, y)) {
				ans ^= a[x][y];
				x += 2;
				y -= 2;
			}
		}

		for(int i = n-1; i >= 0; i -= 2) {
			int x = i, y = n-1-i;

			while(isValid(x, y)) {
				x--;
				y--;
			}

			x++;
			y++;

			while(isValid(x, y)) {
				ans ^= a[x][y];
				x += 2;
				y += 2;
			}
		}

		cout << ans << "\n";
	}
	
	
	return 0;
}
