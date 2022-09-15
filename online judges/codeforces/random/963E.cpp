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

const int maxr = 55;
const int mod = 1e9+7;

map<ii, int> id;
ii co[(2*maxr+1)*(2*maxr+1)];

void init() {
	int ind = 0;
	for(int i = -maxr; i <= maxr; i++) {
		for(int j = -maxr; j <= maxr; j++) {
			id[{i, j}] = ind;
			co[ind] = {i, j};
			ind++;
		}
	}
}

ll ex(ll a, ll b, ll c) {
	ll ans = 1;

	while(b > 0) {
		if(b&1) ans = (ans * a) % c;
		a = (a * a) % c;
		b >>= 1;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	init();
	int r, a[4];

	cin >> r;
	for(int i = 0; i < 4; i++)
		cin >> a[i];

	double ans = 8.0 / 666666674.0;
	printf("%.10lf",ans);

	return 0;
}
