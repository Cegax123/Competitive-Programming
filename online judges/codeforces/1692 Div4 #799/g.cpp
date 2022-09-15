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
        int a[n];

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < n; i++) {
            if(a[i] < 2 * a[i+1])
                a[i] = 1;
            else 
                a[i] = 0;
        }

        int ans = 0;
        int curr = 0;
        for(int i = 0; i < k; i++)
            curr += a[i];

        ans += curr == k;

        for(int i = k; i < n-1; i++) {
            curr += a[i];
            curr -= a[i-k];

            ans += curr == k;
        }

        cout << ans << "\n";
    }

	
    return 0;
}


