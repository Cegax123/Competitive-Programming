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

const int maxn = 2e5+5;
int n, t[maxn];
const int R = 40;
int p[maxn][R];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int q; cin >> n >> q;

	for(int i = 0; i < n; i++) {
		cin >> t[i];
		t[i]--;
	}

	for(int i = 0; i < n; i++) {
		p[i][0] = t[i];
	}

	for(int i = 1; i < R; i++) {
		for(int j = 0; j < n; j++) {
			p[j][i] = p[p[j][i-1]][i-1];
		}
	}


	while(q--) {
		int x; ll k; cin >> x >> k;
		x--;
		
		for(int bit = 0; bit < R; bit++) {
			if((k >> bit)&1ll) {
				x = p[x][bit];
			}
		}

		cout << x+1 << "\n";
	}
	
	return 0;
}