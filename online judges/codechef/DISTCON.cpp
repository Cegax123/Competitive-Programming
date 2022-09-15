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
	int d; cin >> d;

	if(d&1) {
		cout << "-1\n";
		return 0;
	}
	
	cout << 0 << " " << d/2 << "\n";
	cout << 0 << " " << -d/2 << "\n";
	cout << d/2 << " " << 0 << "\n";
	cout << -d/2 << " " << 0 << "\n";

    return 0;
}
