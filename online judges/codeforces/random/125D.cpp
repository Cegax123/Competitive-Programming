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

const int maxn = 3e4+5;

int n, a[maxn];

vi pos;
int marked[maxn];

bool cmp(int x, int y) {
	int r = a[y]-a[x];

	pos.clear();
	pos.pb(x); pos.pb(y);

	memset(marked, 0, sizeof(marked));

	marked[x] = marked[y] = 1;
	marked[3-x-y] = 2;

	int lst = y;

	for(int i = 0; i < n; i++) {
		if(i == x or i == y) continue;
		if(a[i]-a[lst] == r) {
			pos.pb(i);
			marked[i] = 1;

			lst = i;
		}
		else {
			marked[i] = 2;
		}
	}

	map<int, int> cnt;
	set<ii> s;
	int nxt[n];

	lst = -1;
	int sum = 0;

	for(int i = 0; i < n; i++) {
		if(marked[i] == 1) {
			nxt[i] = lst;
			sum++;
			continue;
		}

		if(lst == -1) {
			lst = i;
			continue;
		}

		int r = a[i]-a[lst];

		if(cnt[r]) s.erase({r, cnt[r]});

		cnt[r]++;
		s.insert({r, cnt[r]});

		lst = i;
	}

	if(sum == n) {
		marked[n-1] = 2;
		return 1;
	}

	if(sum == n-1) return 1;

	if((int) s.size() == 1) {
		return 1;
	}

	for(int i = n-1; i >= 0; i--) {
		if(marked[i] == 2) continue;

		int L = nxt[i];
		int R = i+1;

		marked[i] = 2;
		
		if(R < n and L >= 0) {
			int r = a[R] - a[L];
			
			s.erase({r, cnt[r]});
			cnt[r]--;

			if(cnt[r]) s.insert({r, cnt[r]});

			r = a[R]-a[i];
			if(cnt[r]) s.erase({r, cnt[r]});
			cnt[r]++;
			s.insert({r, cnt[r]});

			r = a[i]-a[L];
			if(cnt[r]) s.erase({r, cnt[r]});
			cnt[r]++;
			s.insert({r, cnt[r]});

			if((int) s.size() == 1) return 1;
		}
		else if(R < n) {
			return 0;
		}
		else {
			int r = a[i]-a[L];

			if(cnt[r]) s.erase({r, cnt[r]});
			cnt[r]++;
			s.insert({r, cnt[r]});
		}
	}

	return 0;
}

void print_seq() {
	for(int i = 0; i < n; i++)
		if(marked[i] == 1) cout << a[i] << " ";
	cout << "\n";
	for(int i = 0; i < n; i++)
		if(marked[i] == 2) cout << a[i] << " ";
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	if(n == 2) {
		cout << a[0] << "\n" << a[1];
		return 0;
	}

	if(cmp(0, 1)) print_seq();
	else if(cmp(1, 2)) print_seq();
	else if(cmp(0, 2)) print_seq();
	else cout << "No solution\n";
	
	return 0;
}

