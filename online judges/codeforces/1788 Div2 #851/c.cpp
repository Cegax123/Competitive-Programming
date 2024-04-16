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
        if(n % 2 == 0) {
            cout << "No\n";
            continue;
        }

        cout << "Yes\n";

        for(int i = 1; i <= (n+1) / 2; i++) {
            cout << 2 * i - 1 << " " << 2 * n + i - (2 * i - 1) << "\n";
        }
        for(int i = 0, k = n-1; i >= -((n)/2-1); i--, k-=2) {
            cout << k << " " << 2 * n + i - k << "\n";
        }
    }

	
    return 0;
}


