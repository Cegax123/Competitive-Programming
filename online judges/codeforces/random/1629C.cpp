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
		int a[n];

		for(int i = 0; i < n; i++)
			cin >> a[i];

		vi pos[n+1];

		for(int i = n-1; i >= 0; i--) {
			pos[a[i]].pb(i);
		}

		int r = -1;

		vi ans;
		
		while(1) {
			while(!pos[0].empty() and pos[0].back() <= r)
				pos[0].pop_back();

			if(pos[0].empty()) {
				for(int i = r+1; i < n; i++)
					ans.pb(0);
				break;
			}

			int tmp = r;
			int ind = 0;

			while(ind <= n and !pos[ind].empty()) {
				while(!pos[ind].empty() and pos[ind].back() <= r)
					pos[ind].pop_back();

				if(pos[ind].empty()) break;

				tmp = max(tmp, pos[ind].back());
				pos[ind].pop_back();

				ind++;
			}

			ans.pb(ind);
			r = tmp;
		}

		cout << ans.size() << "\n";

		for(int x : ans)
			cout << x << " ";

		cout << "\n";
	}
	
	
	return 0;
}
