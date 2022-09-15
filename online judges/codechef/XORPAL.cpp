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
		string s; cin >> s;

		int cnt0 = 0, cnt1 = 0;

		for(int i = 0; i < n; i++) {
			if(s[i] == '0') cnt0++;
			else cnt1++;
		}

		if(n&1) {
			if((cnt0%2 and cnt1%2 == 0) or (cnt0%2 == 0 and cnt1%2)) cout << "YES\n";
			else cout << "NO\n";
		}
		else {
			if((cnt0 == cnt1) or (cnt0%2 == 0 and cnt1%2 == 0)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	
	
    return 0;
}
