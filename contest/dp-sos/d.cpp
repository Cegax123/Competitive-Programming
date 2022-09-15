// SOLVED

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
const int L = 22;


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin >> n;

	vi f((1 << L), -1);

	int a[n];

	for(int i = 0; i < n; i++) {
		cin >> a[i];
		f[a[i]] = a[i];
	}

	for(int i = 0; i < L; i++) {
		for(int mask = 0; mask < (1 << L); mask++) {
			if(mask & (1 << i)) {
				f[mask] = max(f[mask], f[mask^(1 << i)]);
			}
		}
	}

	for(int i = 0; i < n; i++) {
		int comp = ((1 << L) - 1) ^ a[i];

		cout << f[comp] << "\n";
	}
	
    return 0;
}
