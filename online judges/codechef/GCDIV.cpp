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
        int k; cin >> k;
        int g = 0;
        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            g = __gcd(g, a);
        }

        for(int i = 2; i <= min(k, (int) 1e5); i++) {
            while(g%i == 0) g /= i;
        }

        if(g > k) cout << "NO\n";
        else cout << "YES\n";
    }

	
    return 0;
}


