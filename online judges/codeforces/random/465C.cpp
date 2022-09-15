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

char find(const vector<bool>& vis, char st, char end) {
	for(char c = st; c <= end; c++) {
		if(vis[c-'a'] == 0) return c;
	}
	return '#';
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, p; cin >> n >> p;
	string s; cin >> s;

	bool found = false;
	
	for(int i = n-1; i >= 0; i--) {
		vector<bool> vis(p, 0);
		
		if(i >= 1) vis[s[i-1]-'a'] = 1;
		if(i >= 2) vis[s[i-2]-'a'] = 1;

		char x = find(vis, s[i]+1, 'a'+p-1);
		if(x == '#') continue;

		string ans = "";

		for(int j = 0; j < i; j++) 
			ans += s[j];

		ans += x;
		
		bool comp = true;
		for(int j = i+1; j < n; j++) {
			int k = ans.size();
	
			vis[ans[k-1]-'a'] = 1;
			if(k >= 3) vis[ans[k-3]-'a'] = 0;

			char c = find(vis, 'a', 'a'+p-1);
			if(c == '#') comp = false;

			ans += c;
		}

		if(comp) {
			cout << ans;
			cout << "\n";
			found = true;
			break;
		}
	}

	if(!found) cout << "NO\n";
	
	return 0;
}

