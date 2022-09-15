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
        
        int a[n+1];
        vi cnt(n+1, 0);

        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            if(a[i] == 0) cnt[i]++;
        }

        for(int i = 2; i <= n; i++)
            cnt[i] += cnt[i-1];

        ll ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = i; j <= n; j++) {
                ans += (j-i+1) + cnt[j]-cnt[i-1];
            }
        }

        cout << ans << "\n";
    }
	
	
	return 0;
}

