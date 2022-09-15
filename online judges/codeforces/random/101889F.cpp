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

const int maxn = 1e5+5;
int n;
ll ft[maxn];

struct P {
	int b,f,d;
};

bool cmp(const P& a, const P& b) {
	return a.f > b.f;
}

int LSO(int pos) {
	return pos - (pos & (pos-1));
}

ll get(int pos) {
	ll res = 0;
	while(pos > 0) {
		res = max(ft[pos], res);
		pos -= LSO(pos); // pos = pos & (pos-1);
	}
	return res;
}

void update(int pos, ll val) {
	while(pos <= n) {
		ft[pos] = max(ft[pos], val);
		pos += LSO(pos);
	}
}

int main() {
    int n; cin >> n;
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    memset(ft, 0, sizeof(ft));

	vector<P> people;

	vi B, F;

	for(int i = 0; i < n; i++) {
		int b,f,d; cin >> b >> f >> d;
		
		B.pb(b);
		F.pb(f);

		P a;
		a.b = b;
		a.f = f;
		a.d = d;

		people.pb(a);
	}

	map<int, int> mb, mf;

	sort(all(B));
	sort(all(F));

	int indb = 1, indf = 1;	

	for(int i = 0; i < n; i++) {
		if(!mb[B[i]]) mb[B[i]] = indb++;
		if(!mf[F[i]]) mf[F[i]] = indf++;
	}

	for(int i = 0; i < n; i++) {
		people[i].b = mb[people[i].b];
		people[i].f = mf[people[i].f];
	}

	vector<vector<P>> arr(n+1);

	for(int i = 0; i < n; i++) {
		arr[people[i].b].pb(people[i]);
	}

	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		sort(all(arr[i]), cmp);
		
		if(arr[i].empty()) continue;
		int ind = 0, k = arr[i].size();

		while(ind < k) {
			int cnt = 0;
			ll local = 0;
			int tmpf = arr[i][ind].f;

			while(ind < k and arr[i][ind].f == tmpf) {
				local += (ll) arr[i][ind].d;
				ind++;
			}

			local += get(tmpf-1);
			ans = max(ans, local);

			update(tmpf, local);
		}
	}

	cout << ans << "\n";

	return 0;
}
