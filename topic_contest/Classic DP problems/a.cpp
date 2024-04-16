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
    int n; cin >> n;
    int q; cin >> q;
    ll a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i) a[i] += a[i-1];
    }
    while(q--) {
        int l, r; cin >> l >> r;
        r--;

        cout << a[r] - (l-1 >= 0 ? a[l-1] : 0) << "\n";
    }
	
    return 0;
}


