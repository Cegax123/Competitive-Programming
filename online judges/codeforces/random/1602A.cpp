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
		string s; cin >> s;
		vi cnt(30, 0);
		
		for(int i = 0; i < (int) s.size(); i++) {
			cnt[s[i]-'a']++;
		}
		
		char c;
		for(int i = 0; i < 30; i++) {
			if(cnt[i]) {
				c = (char) 'a'+i;
				break;
			}
		}
		
		bool found = 0;
		
		cout << c << " ";
		for(int i = 0; i < (int) s.size(); i++) {
			if(!found and c == s[i]) {
				found = 1;
				continue;
			}
			cout << s[i];
		}
		
		cout << "\n";
	}
				
	

	return 0;
}
