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
		int n, m; cin >> n >> m;
		string s; cin >> s;

		int cnt[30][n];
		memset(cnt, 0, sizeof(cnt));

		for(char c = 'a'; c <= 'z'; c++) {
			if(s[0] == c) cnt[c-'a'][0]++;
			for(int i = 1; i < n; i++) {
				cnt[c-'a'][i] = cnt[c-'a'][i-1];
				if(s[i] == c) cnt[c-'a'][i]++;
			}
		} 

		int ans[30];
		memset(ans, 0, sizeof(ans));

		for(int i = 0; i < m; i++) {
			int p; cin >> p;

			for(int j = 0; j < 30; j++) 
				ans[j] += cnt[j][p-1];
		}

		for(int j = 0; j < 30; j++)
			ans[j] += cnt[j][n-1];

		for(int i = 0; i < 26; i++)
			cout << ans[i] << " ";
		cout << "\n";
	}

	
	return 0;
}