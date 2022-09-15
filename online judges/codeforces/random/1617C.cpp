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

        vi cnt(2*n+3, 0);

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        
            if(a[i] <= 2*n+1) cnt[a[i]]++;
            else cnt[2*n+2]++;
        }

        int curr = 0;
        int ans = 0;
        bool comp = true;

        for(int i = n; i >= 1; i--) {
            curr += cnt[2*i+1] + cnt[2*i+2];
            if(cnt[i]) {
                cnt[i]--;
                continue;
            }
            if(curr) {
                curr--;
                ans++;
            }
            else {
                comp = false;
            }
        }

        if(comp) cout << ans << "\n";
        else cout << "-1\n";
    }
	
	
	return 0;
}

