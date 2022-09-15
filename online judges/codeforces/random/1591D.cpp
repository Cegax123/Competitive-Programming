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
		vi cnt(n, 0);

		for(int i = 0; i < n; i++) {
			cin >> a[i];
			a[i]--;
			cnt[a[i]]++;
		}

		bool found = 0;
		for(int i = 0; i < n; i++) {
			if(cnt[i] >= 2) {
				found = 1;
			}
		}

		if(found) {
			cout << "YES\n";
			continue;		
		}

		vector<bool> used(n, 0);

		int cnt_even = 0;
		for(int i = 0; i < n; i++) {
			
			int len_cycle = 0;
			int j = i;

			while(!used[j]) {
				used[j] = 1;
				len_cycle++;
				j = a[j];
			}

			if(len_cycle and len_cycle % 2 == 0) {

				cnt_even++;
			}
		}


		if(cnt_even% 2 == 0) cout << "YES\n";
		else cout << "NO\n";
	}
	
	
	return 0;
}
