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
    int n; ll k; cin >> n >> k;

    for(int i = n; i >= 1; i--) {
        ll lmt = (1ll << (i-1));
        if(lmt == k) {
            cout << i << "\n";
            break;
        }
        else if(k > lmt) k -= lmt;
    }

	
    return 0;
}


