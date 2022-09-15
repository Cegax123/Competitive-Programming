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

int val(string s) {
	int v = 0;

	for(int i = 0; i < (int) s.size(); i++) 
		v = 26 * v + (s[i]-'a');

	return v;
}

int rval(string s) {
	reverse(all(s));
	return val(s);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		string s[n];

		for(int i = 0; i < n; i++)
			cin >> s[i];

		bool comp = 0;

		for(int i = 0; i < n; i++) {
			if(s[i].size() == 1) comp = 1;
			else if(s[i].size() == 2 and s[i][0] == s[i][1]) comp = 1;
			else if(s[i][0] == s[i][2]) comp = 1;
		}

		vi cnt2(30*30, 0), cnt3(30*30*30, 0), cnt23(30*30, 0), cnt32(30*30, 0);

		for(int i = 0; i < n; i++) {
			if(s[i].size() == 2) {
				int v = val(s[i]);
				int rv = rval(s[i]);

				if(cnt2[rv]) comp = 1;
				if(cnt32[rv]) comp = 1;

				cnt2[v]++;
				cnt23[v]++;
			}
			else if(s[i].size() == 3) {
				int v = val(s[i]);
				int rv = rval(s[i]);

				int v2 = 26 * (s[i][0]-'a') + (s[i][1]-'a');
				int rv2 = 26 * (s[i][2]-'a') + (s[i][1]-'a');

				if(cnt3[rv]) comp = 1;
				if(cnt23[rv2]) comp = 1;
				
				cnt3[v]++;
				cnt32[v2]++;
			}
		}

		cout << (comp ? "YES\n" : "NO\n");
	}
	
	
	return 0;
}
