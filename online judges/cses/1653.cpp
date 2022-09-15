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

const int maxn = 21;

int n;
ll x;
int a[maxn];
ii ans[1 << maxn];


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	cin >> n >> x;

	for(int i = 0; i < n; i++) 
		cin >> a[i];

	ans[0] = {1, 0};

	for(int s = 1; s < (1 << n); s++) {
		ans[s] = {n+1, 0};
		for(int i = 0; i < n; i++) {
			if(s&(1 << i)) {
				auto opt = ans[s^(1 << i)];

				if(opt.second + a[i] <= x) {
					opt.second += a[i];
				}
				else {
					opt.first++;
					opt.second = a[i];
				}

				ans[s] = min(ans[s], opt);
			}
		}
	}

	cout << ans[(1 << n)-1].first << "\n";

	return 0;
}
