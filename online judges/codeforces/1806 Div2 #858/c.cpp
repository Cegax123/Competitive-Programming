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
        int a[2 * n];

        for(int i = 0; i < 2 * n; i++)
            cin >> a[i];

        if(n == 1) {
            cout << abs(a[0]-a[1]) << "\n";
            continue;
        }

        ll ans = 0;
        for(int i = 0; i < 2 * n; i++)
            ans += abs(a[i]);

        if(n == 2) {
            ll curr = 0;
            for(int i = 0; i < 2 * n; i++) {
                curr += abs(a[i]-2);
            }

            ans = min(ans, curr);
        }
        if(n%2 == 0) {
            ll curr = 0;
            for(int i = 0; i < 2 * n; i++) {
                curr += abs(a[i]+1);
            }

            for(int i = 0; i < 2 * n; i++) {
                curr -= abs(a[i]+1);
                curr += abs(a[i]-n);

                ans=min(ans, curr);

                curr += abs(a[i]+1);
                curr -= abs(a[i]-n);
            }
        }

        cout << ans << "\n";

    }

	
    return 0;
}


