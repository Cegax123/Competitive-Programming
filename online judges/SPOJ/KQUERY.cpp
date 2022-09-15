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

struct Qu {
	int i,j,k;
	int ind;
};

const int maxn = 3e4+5;
vi ft(maxn, 0);
int n;

bool cmp(const Qu& a, const Qu& b) {
	return a.k > b.k;
}

int LSO(int pos) {
	return pos - (pos & (pos-1));
}

int getPrefix(int pos) {
	int res = 0;
	while(pos > 0) {
		res = ft[pos] + res;
		pos -= LSO(pos); // pos = pos & (pos-1)
	}
	return res;
}

void update(int pos, int val) {
	while(pos <= n) {
		ft[pos] = ft[pos] + val;
		pos += LSO(pos);
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	int a[n];
	vii b(n);

	for(int i = 0; i < n; i++) {
		cin >> a[i];
		b[i].first = a[i];
		b[i].second = i;
	}

	sort(all(b));

	vector<Qu> arrQu;

	int q; cin >> q;
	for(int t = 0; t < q; t++) {
		int i, j, k; cin >> i >> j >> k;
		Qu x;
		x.i = i;
		x.j = j;
		x.k = k;
		x.ind = t;

		arrQu.pb(x);
	}

	int ind = n-1;
	sort(all(arrQu), cmp);
	vi ans(q);

	for(auto& x : arrQu) {
		while(ind >= 0 and b[ind].first > x.k) {
			update(b[ind].second+1, 1);
			ind--;
		}
		ans[x.ind] = getPrefix(x.j)-getPrefix(x.i-1); 
	}

	for(int i = 0; i < q; i++)
		cout << ans[i] << "\n";

	return 0;
}

