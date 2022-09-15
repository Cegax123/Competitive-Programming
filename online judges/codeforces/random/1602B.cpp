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
		int n; cin >> n;
		int a[n][n+5];
		
		for(int i = 0; i < n; i++)
			cin >> a[i][0];
		
		for(int i = 1; i < n+5; i++) {
			map<int, int> cnt;
			for(int j = 0; j < n; j++) 
				cnt[a[j][i-1]]++;
			for(int j = 0; j < n; j++) 
				a[j][i] = cnt[a[j][i-1]];
		}
		
		int q; cin >> q;
		while(q--) {
			int x, k; cin >> x >> k;
		
			if(k <= n) 
				cout << a[x-1][k];
			else 
				cout << a[x-1][n+4];
			cout << "\n";
		}
	}

	return 0;
}
