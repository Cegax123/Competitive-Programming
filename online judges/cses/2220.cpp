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

ll cnt[20];

void init() {
	cnt[0] = 1;
	for(int i = 1; i <= 18; i++) {
		cnt[i] = cnt[i-1] * 9;
	} 
}

ll dp[20][10][2];
vi num;

ll call(int pos = 0, int last = 0, int f = 0) {
	if(pos == num.size())
		return 1;

	if(dp[pos][last][f] != -1) return dp[pos][last][f];

	ll res = 0;
	int LMT;

	if(f == 0)
		LMT = num[pos];
	else 
		LMT = 9;

	for(int d = 0; d <= LMT; d++) {
		if(last == d) continue;

		int nf = f;
		if(f == 0 and d < LMT) nf = 1;

		res += call(pos+1, d, nf);
	}

	return dp[pos][last][f] = res;
}

int cd(ll n) {
	int ans = 0;
	while(n) {
		ans++;
		n /= 10;
	}
	return ans;
} 

ll solve(ll n) {
	if(n == -1) return 0;
	if(n == 0) return 1;

	num.clear();

	while(n) {
		num.pb(n%10);
		n /= 10;
	}

	reverse(all(num));
	memset(dp, -1, sizeof(dp));

	ll res = call(0, 0, 0);
	int cdn = num.size();

	for(int i = 0; i < cdn; i++) 
		res += cnt[i];

	return res;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	init();

	ll a, b; cin >> a >> b;

	cout << solve(b) - solve(a-1ll) << "\n";
	
	return 0;
}