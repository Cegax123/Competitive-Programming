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

const int LOGK = 62;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    ll k; cin >> k;
	
	int t[n][LOGK];
	for(int i = 0; i < n; i++) {
		cin >> t[i][0];
		t[i][0]--;
	}

	for(int j = 1; j < LOGK; j++) {
		for(int i = 0; i < n; i++) {
			t[i][j] = t[t[i][j-1]][j-1];
		}
	}

	int pos = 0;
	for(int j = 0; j < LOGK; j++) {
		if((k >> j)&1ll) {
			pos = t[pos][j];
		}
	}

	cout << pos+1 << "\n";
	
    return 0;
}
