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
        int ans = n-1;
        for(int i = 1; i * i <= n; i++) {
            if(n % i == 0) {
                int d1 = i, d2 = n/i;
                int f1 = n-d1, f2 = n-d2;

                if(d1 <= f1) ans = min(ans, f1);
                if(d2 <= f2) ans = min(ans, f2);
            }
        }

        cout << n-ans << " " << ans << "\n";
    }

	
    return 0;
}


