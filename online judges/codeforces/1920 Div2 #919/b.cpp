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
        int n, k, x; cin >> n >> k >> x;
        int a[n+1];
        for(int i = 1; i <= n; i++) cin >> a[i];
        sort(a+1, a+n+1);

        int p[n+1];
        p[0] = 0;

        for(int i = 1; i <= n; i++)
            p[i] = p[i-1] + a[i];

        int ans = -1e9;

        for(int i = 0; i <= k; i++) {
            int r = n-i;
            int l = max(1, r-x+1);
            
            int curr = p[l-1] - (p[r]-p[l-1]);
            ans = max(ans, curr);
        }

        cout << ans << "\n";
    }

	
    return 0;
}


