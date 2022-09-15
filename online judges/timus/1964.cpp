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
	ll n, k; cin >> n >> k;
    vector<ll> a(k);

    for(int i = 0; i < k; i++) {
        cin >> a[i];
    }

    sort(all(a));
	
    int ans = max(a[0]+a[1]-n, 0ll); 
    for(int i = 2; i < k; i++) {
        ans = max(ans+a[i]-n, 0ll);
    }

    cout << ans << "\n";
	
	return 0;
}

