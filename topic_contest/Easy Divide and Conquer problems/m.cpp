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
    int n, d; cin >> n >> d;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int l = i, r = n-1;
        while(l < r) {
            int m = (l+r+1) >> 1;
            if(a[m] <= a[i] + d) l = m;
            else r = m-1;
        }
        int cnt = l-i+1;

        ans += (cnt-1) * 1ll * (cnt-2) / 2;
    }

    cout << ans << "\n";
	
    return 0;
}


