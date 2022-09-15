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

const int E = 26;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while(t--) {
		string s; cin >> s;
		int n = s.size();
		string sgm;

		bool all_equal = true;
		for(int i = 0; i < n-1; i++) 
			if(s[i] != s[i+1]) all_equal = false;

		if(all_equal) {
			cout << s << "\n";
			continue;
		}

		vi cnt(E, 0);

		for(int i = 0; i < n; i++) {
			cnt[s[i]-'a'] ++;
		}

		bool found = 0;
		for(int i = 0; i < E; i++) {
			if(cnt[i]) sgm += 'a'+i;

			if(cnt[i] == 1) {
				string ans = "";
				ans += 'a'+i;
				
				for(int j = 0; j < E; j++) {
					if(i == j) continue;
					ans += string(cnt[j], 'a'+j);
				}

				cout << ans << "\n";
				found = 1;
				break;
			}
		}

		if(found) continue;
		
		int cntA = cnt[sgm[0]-'a'];
		
		if(cntA-2 <= (n-2)/2) {
			cout << string(2, sgm[0]);

			cntA -= 2;

			for(int j = 0; j < E; j++) {
				if(j == sgm[0]-'a') continue;

				for(int k = 0; k < cnt[j]; k++) {
					cout << char('a'+j);

					if(cntA) {
						cout << char(sgm[0]);
						cntA--;
					}
				}
			}
			cout << "\n";
		}
		else {
			if(sgm.size() >= 3) {
				cout << sgm[0] << sgm[1];
				cout << string(cnt[sgm[0]-'a']-1, sgm[0]);
				cout << sgm[2];
				cout << string(cnt[sgm[1]-'a']-1, sgm[1]);
				cout << string(cnt[sgm[2]-'a']-1, sgm[2]);

				for(int i = 0; i < E; i++) {
					if(i == sgm[0]-'a' or i == sgm[1]-'a' or i == sgm[2]-'a') continue;

					cout << string(cnt[i], 'a'+i);
				}
				cout << "\n";
			}
			else {
				cout << sgm[0];
				cout << string(cnt[sgm[1]-'a'], sgm[1]);
				cout << string(cnt[sgm[0]-'a']-1, sgm[0]);
				cout << "\n";
			}
		}
	}
	
	return 0;
}

