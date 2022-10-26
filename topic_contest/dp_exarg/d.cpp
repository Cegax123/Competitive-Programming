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
        int n, k; cin >> n >> k;
        vi a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < n; i++) {
            int y; cin >> y;
        }
        
        sort(all(a));

        int R[n];

        for(int i = 0; i < n; i++) {
            int l = i, r = n-1;

            while(l < r) {
                int m = (l+r+1) >> 1;

                if(a[m] <= a[i] + k) l = m;
                else r = m-1;
            }

            R[i] = l;
        }

        int mx[n];
        mx[n-1] = R[n-1] - (n-1) + 1;

        for(int i = n-2; i >= 0; i--)
            mx[i] = max(R[i]-i+1, mx[i+1]);

        int ans = 0;
        for(int i = 0; i < n; i++) {
            int cntL = R[i]-i+1;
            int cntR = (R[i] == n-1 ? 0 : mx[R[i]+1]);

            ans = max(ans, cntL + cntR);
        }

        cout << ans << "\n";
    }
	
    return 0;
}


