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

ll ex(ll a, ll b, ll c) {
	ll ans = 1;

	while(b > 0) {
		if(b&1) ans = (ans * a) % c;
		a = (a * a) % c;
		b >>= 1;
	}

	return ans;
}

ll mul(ll a, ll b, ll c) {
	return (a*b)%c;
}

ll sum(ll a, ll b, ll c) {
	ll ans = (a+b)%c;
	return (ans+c)%c;
}

ll f(ll m, ll p, ll t, ll z, ll x) {
	return (p-1) * (t + p * m) + z <= x;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	ll a, b, p, x; cin >> a >> b >> p >> x;

	ll inva[p];
	inva[0] = 1;
	inva[1] = ex(a, p-2, p);

	for(int i = 2; i < p; i++)
		inva[i] = mul(inva[1], inva[i-1], p);

	ll ans = 0;
	for(ll z = 0; z <= p-2; z++) {
		ll t = mul(b, inva[z], p);
		t = sum(z, -t, p);

		ll res = x-z-(p-1) * t;
		ll div = p * (p-1);

		if(res < 0) continue;
		
		ans += res/div + 1;
	}

	cout << ans << "\n";
	
	return 0;
}

