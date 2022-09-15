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

int n, q;
string s;

bool comp(int a, int b, int c) {
	if(a >= 0 and c < n) {
		if(s[a] == 'a' and s[b] == 'b' and s[c] == 'c')
			return 1;
		return 0;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> q;
	cin >> s;

	int cnt = 0;

	for(int i = 0; i < n; i++) 
		cnt += comp(i, i+1, i+2);

	while(q--) {
		int pos; char c; cin >> pos >> c;
		pos--;

		cnt -= comp(pos-2, pos-1, pos);
		cnt -= comp(pos-1, pos, pos+1);
		cnt -= comp(pos, pos+1, pos+2);

		s[pos] = c;

		cnt += comp(pos-2, pos-1, pos);
		cnt += comp(pos-1, pos, pos+1);
		cnt += comp(pos, pos+1, pos+2);

		cout << cnt << "\n";
	}
	
	
	return 0;
}
