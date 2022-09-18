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
		vi num;

		while(n) {
			num.pb(n%10);
			n /= 10;
		}

		reverse(all(num));
		
		int a = 0, b = 0;
		for(int i = 0; i < (int) num.size(); i++) {
			if(i&1) a = a * 10 + num[i];
			else b = b*10 + num[i];
		}

		cout << (ll) (a+1)*(b+1)-2 << "\n";
	}

	
	return 0;
}