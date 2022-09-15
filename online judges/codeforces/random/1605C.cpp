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
		
		string ans = "-1";
		for(int i = 0; i+1 < n; i++) {
			if(s[i] == 'a' and s[i+1] == 'a') {
				ans = "aa";
			}
		}
		
		if(ans != "-1") {
			cout << ans.size() << "\n";
			continue;
		}

		for(int i = 0; i+2 < n; i++) {
			if(s[i] == 'a' and s[i+2] == 'a') {
				ans = s[i];
				ans += s[i+1];
				ans += s[i+2];
			}
		}
		
		if(ans != "-1") {
			cout << ans.size() << "\n";
			continue;
		}
		
		for(int i = 0; i+3 < n; i++) {
			if(s[i] == 'a' and s[i+3] == 'a' and s[i+1] != s[i+2]) {
				ans = s[i];
				ans += s[i+1];
				ans += s[i+2];
				ans += s[i+3];
			}
		}
				
		if(ans != "-1") {
			cout << ans.size() << "\n";
			continue;
		}
		
		for(int i = 0; i+6 < n; i++) {
			if(s[i] == 'a' and s[i+3] == 'a' and s[i+6] == 'a' and s[i+1] == s[i+2] and s[i+4] == s[i+5] and s[i+1] != s[i+4]) {
				ans = "";
				for(int j = i; j <= i+6; j++) 
					ans += s[j];
			}
		}
		
		if(ans != "-1") cout << ans.size() << "\n";
		else cout << "-1\n";
	}
	
	
	return 0;
}
