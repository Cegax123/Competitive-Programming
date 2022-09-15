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
		int n = s.size();

		vector<pair<char, int> > st;
		int r[n];
		memset(r, -1, sizeof(r));

		for(int i = 0; i < (int) s.size(); i++) {
			if(s[i] == '(') {
				st.pb({s[i], i});
			}
			else {
				if(!st.empty() and st.back().first == '(') {
					r[st.back().second] = i;
					st.pop_back();
				}
				else 
					st.pb({s[i], i});
			}
		}

		cout << st.size() << " ";

		int moves = 0;
		int ind = 0;
		while(ind < n) {
			if(r[ind] == -1) {
				ind++;
				continue;
			}

			moves++;
			while(ind < n and r[ind] != -1) 
				ind = r[ind] + 1;
			
		}

		cout << moves << "\n";
	}	
	
	
    return 0;
}

