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
        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];

        long long ans = 0;
        for(int i = n-2; i >= 0; i--) {
            int l = 0, r = a[i]-1;

            while(l < r) {
                int m = (l+r) >> 1;

                int d = m+1;

                bool can = false;
                if(a[i] % d == 0) {
                    int k = a[i] / d;
                    if(k <= a[i+1]) can = true;
                }
                else {
                    int k = (a[i] + d - 1) / d;
                    if(k <= a[i+1]) can = true;
                }

                if(can) r = m;
                else l = m+1;
            }

            ans += l;

            a[i] /= (l+1);
        }

        cout << ans << "\n";
    }

	
    return 0;
}


