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
		
		bool died = false;
		int sz = 1;
		int op[n];

		for(int i = 0; i < n; i++)
			cin >> op[i];
		
		if(op[0] == 1) sz++;

		for(int i = 1; i < n; i++) {
			if(op[i]) {
				if(op[i] and op[i-1]) sz += 5;
				else sz ++;
			}
			else {
				if(op[i-1] == 0) died = true;
			}
		}

		if(died) cout << "-1\n";
		else cout << sz << "\n";
	}
	
	
	return 0;
}
