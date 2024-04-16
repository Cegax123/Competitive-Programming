#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 1e5 + 5;
const ll INF = (ll) 4e18;

pair<ll, ll> p[maxn];

ll dis(pair<ll, ll> a, pair<ll, ll> b) {
	ll dx = a.first - b.first, dy = a.second - b.second;
	return dx * dx + dy * dy;
}

ll solve(int l, int r) {
	if(l == r) return INF;
	if(r-l+1 <= 3) {
		sort(p + l, p + r + 1, [](pair<ll, ll> a, pair<ll, ll> b) {
			return a.second < b.second;
		});

		ll ans = INF;
		for(int i = l; i <= r; i++) {
			for(int j = i+1; j <= r; j++) {
				ans = min(ans, dis(p[i], p[j]));
			}
		}
		return ans;
	}
	
	int m = (l+r) >> 1;
	ll d2 = min(solve(l, m), solve(m+1, r));
	
	vector<pair<ll, ll>> q;
	
	for(int i = l; i <= r; i++) {
        ll diff = p[m].first - p[i].first;
        if(diff * diff <= d2) q.push_back(p[i]);
		//if(abs(p[m].first-p[i].first) <= d) q.push_back(p[i]);
	}

	sort(q.begin(), q.end(), [](pair<ll, ll> a, pair<ll ,ll> b) {
			return a.second < b.second;
			});

	ll ans = d2;
	
	for(int i = 0; i < (int) q.size(); i++) {
		ll curr = INF;
		for(int j = i - 1; j >= 0; j--) {
			ll diff = q[i].second - q[j].second;
			if(diff * diff > d2) break;
			//if(q[i].second - q[j].second > d) break;
			curr = min(curr, dis(q[i], q[j]));
		}
		ans = min(ans, curr);
	}

	sort(p+l, p+r+1, [](pair<ll, ll> a, pair<ll, ll> b) {
			return a.second < b.second;
			});

	for(int i = l+1; i <= r; i++)
		assert(p[i].second >= p[i-1].second);
	
	//merge(p+l, p+m+1, p+m+1, p+r+1, tmp.begin(), [](pair<ll, ll> a, pair<ll, ll> b) {
		//return a.second < b.second;
	//});
	
	return ans;
}

int main() {
	int n; cin >> n;
	
	p[0] = {0, 0};
	
	for(int i = 1; i <= n; i++) {
		p[i].first = i;
		cin >> p[i].second;
		p[i].second += p[i-1].second;
	}
	
	cout << solve(1, n) << "\n";
	
	return 0;
}



