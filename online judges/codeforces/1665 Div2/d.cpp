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
    	int x = 0;

    	for(int i = 0; i <= 29; i++) {
    		int a = (1 << (i+1)) + (1 << i) - x;
    		int b = (1 << i) - x;

    		cout << "? " << a << " " << b << endl;

    		ll ans; cin >> ans;

    		if(ans == (1ll << (i+1)))
    			x |= (1 << i);
    	}

    	cout << "! " << x << endl;
    }
	
	
	return 0;
}

