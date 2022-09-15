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
    vector<ll> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    ll l = 0, r = (ll) 1e18 / k;

    while(l < r) {
        ll m = (l+r+1) / 2;
        
        ll sum = 0;
        for(ll x : a) sum += min(x, m);

        if(sum >= k * m) l = m;
        else r = m-1;
    }
    
    cout << l << "\n";
	
    return 0;
}


