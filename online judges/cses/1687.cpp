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
const int LOGN = 20;

int p[maxn][LOGN+1];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, q; cin >> n >> q;

	for(int i = 1; i < n; i++) {
		int b; cin >> b;
		b--;
		p[i][0] = b;
	}

	p[0][0] = -1;

	for(int j = 1; j <= LOGN; j++) {
		for(int i = 0; i < n; i++) {
			if(p[i][j-1] != -1) p[i][j] = p[p[i][j-1]][j-1];
			else p[i][j] = -1;
		}
	}
	
	while(q--) {
		int v, k; cin >> v >> k;
		v--;

		for(int i = 0; i <= LOGN; i++) {
			if((k >> i)&1) {
				v = p[v][i];
				if(v == -1) break;
			}
		}

		if(v != -1) v++;

		cout << v << "\n";
	}
	
    return 0;
}
