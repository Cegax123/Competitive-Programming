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

string s;
int n;

void solve(int l = 0, int r = n) {
	if(l == r) return;
	if(r-l <= 3) {
		cout << s[l];
		return;
	}
	char x;

	if(s[l] == s[r-1] or s[l] == s[r-2]) x = s[l];
	if(s[l+1] == s[r-1] or s[l+1] == s[r-2]) x = s[l+1];

	cout << x;
	solve(l+2, r-2);
	cout << x;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> s;
	n = s.size();

	solve();
	
	return 0;
}
