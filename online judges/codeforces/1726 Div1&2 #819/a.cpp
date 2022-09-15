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
        vi a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        if(n == 1) {
            cout << 0 << "\n";
            continue;
        }

        const int INF = 1e9;
        int ans = -INF;

        int ml = INF;
        for(int i = 0; i < n-1; i++)
            ml = min(ml, a[i]);

        ans = max(ans, a[n-1]-ml);

        int mr = -INF;
        for(int i = 1; i < n; i++)
            mr = max(mr, a[i]);

        ans = max(ans, mr-a[0]);

        for(int i = 0; i < n; i++)
            ans = max(ans, a[i] - a[(i+1)%n]);

        cout << ans << "\n";
    }

	
    return 0;
}


