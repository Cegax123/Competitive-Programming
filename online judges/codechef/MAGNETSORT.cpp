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

const int maxn = 2e5+5;

int n;
string pol;

bool isSorted(int i, int j, const vector<int>& a) {
	if(i > j) return 1;
	for(int k = i+1; k <= j; k++) {
		if(a[k] < a[k-1]) return 0;
	}
	return 1;
}

bool comp1(int i, int j, const vector<int>& a) {
	vi M, b;

	for(int k = i; k <= j; k++)
		M.pb(a[k]);

	sort(all(M));

	for(int k = 0; k < i; k++)
		b.pb(a[k]);

	for(int k = 0; k < (int) M.size(); k++)
		b.pb(M[k]);

	for(int k = j+1; k < n; k++)
		b.pb(a[k]);


	return isSorted(0, n-1, b);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while(t--) {
		cin >> n;

		vi a(n);
		for(int i = 0; i < n; i++)
			cin >> a[i];
		
		cin >> pol;

		if(isSorted(0, n-1, a)) {
			cout << "0\n";
			continue;
		}

		if(pol == string(n, 'N') or pol == string(n, 'S')) {
			cout << "-1\n";
			continue;
		}

		bool cmp = 0;

		if(pol[0] != pol[n-1]) cmp = 1;

		int fs = -1, fn = -1, ls, ln;

		for(int i = 0; i < n; i++) {
			if(pol[i] == 'S') {
				if(fs == -1) fs = i;
				ls = i;
			}
			else {
				if(fn == -1) fn = i;
				ln = i;
			}
		}

		if(comp1(fs, ln, a) or comp1(fn, ls, a)) cmp = 1;

		cout << (cmp ? 1 : 2) << "\n";
	}
	
	
    return 0;
}
