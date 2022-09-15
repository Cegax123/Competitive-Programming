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

    	for(int i = 0; i < n; i++)
    		cin >> a[i];

    	ll sum[n];
    	sum[0] = a[0];

    	for(int i = 1; i < n; i++)
    		sum[i] = sum[i-1] + a[i];
    	
    	ll ans = sum[n-1];

    	for(int i = 0; i < n; i++) 
    		ans = min(ans, max(sum[i], sum[n-1]-sum[i]));

    	cout << ans << "\n";
    }

	
	
    return 0;
}
