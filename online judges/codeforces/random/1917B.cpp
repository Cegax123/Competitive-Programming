#include<bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		string s; cin >> s;
		
		vector<int> cnt(26, 0);
		int ans = 0;

		for(int i = 0; i < n; i++) {
			cnt[s[i]-'a']++;
			
			for(int j = 0; j < 26; j++) {
				if(cnt[j]) ans++;
			}
		}

		cout << ans << "\n";
	}


	return 0;
}
