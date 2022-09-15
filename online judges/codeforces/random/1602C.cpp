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

void print_binary(int x) {
	vi ans;
	while(x) {
		ans.pb(x&1);
		x >>=1;
	}
	
	reverse(all(ans));
	
	for(int b:ans)
		cout << b;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<ll> a(n);
		
		for(int i = 0; i < n; i++) 
			cin >> a[i];
			
		int g = 0;
		for(int i = 40; i >= 0; i--) {
			int cnt = 0;
			for(int j = 0; j < n; j++) {
				if((a[j]>>i)&1) cnt++;
			}
			g = __gcd(g, cnt);
		}
		
		if(g==0) {
			for(int i = 1; i <= n; i++)
				cout << i << " ";
		}
		else {
			for(int i = 1; i <= g; i++)
				if(g%i==0) cout << i << " ";
		}
		cout << "\n";
	}
	

	return 0;
}
