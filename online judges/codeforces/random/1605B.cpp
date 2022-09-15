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

		
		int l = 0, r = n-1;
		vector<vi> A;
		
		while(1) {
			if(l > r) break;
			while(l < n and s[l] == '0')
				l++;
			
			while(r >= 0 and s[r] == '1')
				r--;
			
			if(l > r) break;
			
			int nl = l, nr = r;
			
			l++;
			r--;
			
			vi L, R;
			
			while(1) {
				if(nl > r or nr < l or nl >= nr) break;
				
				while(nl <= r and s[nl] == '0')
					nl++;
				while(nr >= l and s[nr] == '1')
					nr--;
				
				if(nl <= r and nr >= l and nl < nr and s[nl] == '1' and s[nr] == '0') {
					L.pb(nl);
					R.pb(nr);
					nl++;
					nr--;
				}
				else break;
			}
			
			vi a;
			
			for(int i = 0; i < (int) L.size(); i++)
				swap(s[L[i]], s[R[R.size()-1-i]]);
			
			for(int i = 0; i < (int) L.size(); i++)
				a.pb(L[i]);
			for(int i = R.size()-1; i >= 0; i--)
				a.pb(R[i]);
				
			A.pb(a);
		}
		cout << A.size() << "\n";
		
		for(int i = 0; i < (int) A.size(); i++) {
			cout << A[i].size() << " ";
			for(int x : A[i])
				cout << x+1 << " ";
			cout << "\n";
		}
	}
	
	return 0;
}
