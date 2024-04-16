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
        int n, m; cin >> n >> m;
        int a[n], b[m];
        int xa = 0;
        int ob = 0;

        for(int i = 0; i < n; i++) {
            cin >> a[i];
            xa ^= a[i];
        }
        for(int j = 0; j < m; j++) {
            cin >> b[j];
            ob |= b[j];
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            a[i] |= ob;
            ans ^= a[i];
        }

        cout << min(xa, ans) << " " << max(xa, ans) << "\n";

    }

	
    return 0;
}


