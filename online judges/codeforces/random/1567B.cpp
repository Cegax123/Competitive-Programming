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

const int maxa = 3e5+5;

int xo[maxa];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	xo[0] = 0;

	for(int i = 1; i < maxa; i++)
		xo[i] = i ^ xo[i-1];

	int t; cin >> t;
	while(t--) {
		int a, b; cin >> a >> b;
		if(xo[a-1] == b) cout << a << "\n";
		else if((xo[a-1]^b) != a) cout << a+1 << "\n";
		else cout << a+2 << "\n";
	}

	
	return 0;
}
