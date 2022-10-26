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
    vi a, b;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(x&1) b.pb(x);
        else a.pb(x);
    }

    sort(all(a));
    sort(all(b));

    reverse(all(a));
    reverse(all(b));

    int ans = -1;
    if(a.size() >= 2) ans = max(ans, a[0] + a[1]);
    if(b.size() >= 2) ans = max(ans, b[0] + b[1]);

    cout << ans << "\n";
	
    return 0;
}


