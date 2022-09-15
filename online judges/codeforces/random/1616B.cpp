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

		if(n == 1) {
			cout << s << s << "\n";
			continue;
		}

		if(s[0] == s[1]) {
			cout << s[0] << s[0] << "\n";
			continue;
		}

		string ans;
		ans += s[0];

		for(int i = 1; i < n; i++) {
			if(s[i] <= s[i-1]) ans += s[i];
			else break;
		}

		int k = ans.size();

		cout << ans;

		for(int i = k-1; i >= 0; i--)
			cout << ans[i];

		cout << "\n";
	}
	
	
	return 0;
}

