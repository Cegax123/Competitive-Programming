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
		vi a(2*n);
		
		for(int i = 0; i < 2*n; i++)
			cin >> a[i];
			
		sort(all(a));
		
		vi b(2*n);
		
		for(int i = 0; i < n; i++) 
			b[2*i] = a[i];
			
		for(int i = 0; i < n; i++)
			b[2*i+1] = a[n+i];
			
		for(int i = 0; i < 2*n; i++)
			cout << b[i] << " ";
		
		cout << "\n";
	}
	

	return 0;
}
