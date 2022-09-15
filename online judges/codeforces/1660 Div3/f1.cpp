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
		string s; cin >> s;

		vi cntP(n+1, 0), cntM(n+1, 0);

		for(int i = 0; i < n; i++) {
			if(i) {
				cntM[i] = cntM[i-1];
				cntP[i] = cntP[i-1];
			}

			if(s[i] == '-') cntM[i]++;
			else cntP[i]++;
		}

		int ans = 0;

		for(int i = 0; i < n; i++) {
			for(int j = i; j < n; j++) {
				int x = cntP[j] - (i == 0 ? 0 : cntP[i-1]);
				int y = cntM[j] - (i == 0 ? 0 : cntM[i-1]);

				if(y >= x and (y-x) % 3 == 0)
					ans++;
			}
		}

		cout << ans << "\n";
	}

	
    return 0;
}
