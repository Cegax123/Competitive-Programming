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
		int cnt[105];
		memset(cnt, 0, sizeof(cnt));

		for(int i = 0; i < n; i++) {
			int a; cin >> a;
			if(a < 0) a = -a;
			cnt[a]++;
		}

		int ans = 0;

		for(int i = 1; i < 105; i++) {
			ans += min(cnt[i], 2);
		}

		if(cnt[0]) ans++;

		cout << ans << "\n";
	}

	
	
	return 0;
}

