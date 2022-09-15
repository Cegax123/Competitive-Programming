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



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while(t--) {
		int n, k; cin >> n >> k;

		int poss = (n+1)/2;

		if(k > poss) {
			cout << "-1\n";
			continue;
		}

		char ans[n][n];

		for(int i = 0; i < n; i++) 
			for(int j = 0; j < n; j++)
				ans[i][j] = '.';

		for(int i = 0; i < k; i++) 
			ans[2*i][2*i] = 'R';

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++)
				cout << ans[i][j];
			cout << "\n";
		}
	}
	
	
	return 0;
}

