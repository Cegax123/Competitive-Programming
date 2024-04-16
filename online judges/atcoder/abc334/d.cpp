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
    ll a[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a+n);
    
    for(int i = 1; i < n; i++)
        a[i] += a[i-1];

    while(q--) {
        ll x; cin >> x;
        int l = 0, r = n-1;

        while(l < r) {
            int m = (l+r+1) >> 1;
            if(a[m] <= x) l = m;
            else r = m-1;
        }

        if(a[l] <= x) cout << l+1 << "\n";
        else cout << 0 << "\n";
    }
	
    return 0;
}


