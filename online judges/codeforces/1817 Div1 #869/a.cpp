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
    int n, q; cin >> n >> q;
    int a[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vi dp(n);

    int ind = 0;

    while(ind < n) {
        int r = ind;
        while(r-1 >= 0 and r < n and a[r] > a[r-1]) {
            r++;
        }

        if(r == ind) {
            dp[ind] = (ind-1 >= 0 ? dp[ind-1] : 0);
            ind++;
            continue;
        }

        r--;
        int len = r-ind+2;

        //cout << ind << " " << r << " " << len << endl;

        for(int i = r; len > 0; i--, len--) {
            dp[i] = (ind-1 >= 0 ? dp[ind-1] : 0) + len;
        }

        ind = r+1;
    }

    while(q--) {
        int l, r; cin >> l >> r;
        l--; r--;

        if(r-l+1 <= 2) {
            cout << r-l+1 << "\n";
            continue;
        }

        int ans = dp[r]-(l-1 >= 0 ? dp[l-1] : 0);

        if(a[r] <= a[r-1] and !(r+1 < n and a[r] < a[r+1])) ans++;
        if(a[l] >= a[l+1] and !(l-1 >= 0 and a[l] > a[l-1])) ans++;
        
        cout << ans << "\n";
    }

    return 0;
}


