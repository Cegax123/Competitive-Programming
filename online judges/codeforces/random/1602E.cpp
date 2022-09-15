#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int N = 2000010;
 
int f[2000100], cnt[1000100];
 
void add(int x, int d)
{
	for(; x <= N; x += x&-x)
		f[x] += d;
}
 
int query(int x)
{
	int res = 0;
	for(; x > 0; x &= x - 1)
		res += f[x];
	return res;
}
 
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int Q;
	cin >> Q;
	while(Q --> 0) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(m);
		for(int& i : a)
			cin >> i;
		vector<int> v(a);
		for(int& i : b)
			cin >> i, v.push_back(i);
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		for(int& i : a)
			i = lower_bound(v.begin(), v.end(), i) - v.begin() + 1;
		for(int& i : b)
			i = lower_bound(v.begin(), v.end(), i) - v.begin() + 1;
		vector<int> p(m);
 
		function<void(int, int, int, int)> solve = [&](int l, int r, int pl, int pr)
		{
			int mid = (l + r) >> 1, tot = 0;
			for(int i = pl; i <= pr; ++i) {
				cnt[i] = tot;
				if(i < n && a[i] > b[mid]) ++tot;
			}
			tot = 0;
			for(int i = min(pr, n - 1); i >= pl; --i) {
				if(i < n && a[i] < b[mid]) ++tot;
				cnt[i] += tot;
			}
			p[mid] = pl;
			for(int i = pl; i <= pr; ++i) {
				if(cnt[p[mid]] >= cnt[i]) 
					p[mid] = i;
			}
			if(l < mid) solve(l, mid - 1, pl, p[mid]);
			if(mid < r) solve(mid + 1, r, p[mid], pr);
		};
 
		sort(b.begin(), b.end());
		solve(0, m - 1, 0, n);
		int j = 0;
		vector<int> c;
		
		for(int i = 0; i < n; ++i) {
			for(; j < m && p[j] <= i; ++j) {
				c.push_back(b[j]);
			}
			c.push_back(a[i]);
		}
		for(; j < m; ++j) {
			c.push_back(b[j]);
		}
		ll res = 0;
		for(int i : c)
			res += query(N) - query(i), add(i, 1);
		for(int i : c)
			add(i, -1);
		cout << res << '\n';
	}
	return 0;
}
 
