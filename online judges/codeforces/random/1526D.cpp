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

const int E = 26;

struct BIT {
    vector<int> bit;  // binary indexed tree
    int n;

    BIT(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    BIT(vector<int> a) : BIT(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

ll find_inversion(const vi& a) {
	int n = a.size();

	BIT ft(n+1);
	ll ans = 0;

	for(int i = 0; i < n; i++) {
		ans += (ll) ft.sum(a[i]+1, n);
		ft.add(a[i], 1);
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while(t--) {
		string s; cin >> s;
		int n = s.size();

		vi pos[E];

		for(int i = 0; i < n; i++)
			pos[s[i]-'A'].pb(i);
		
		string ord = "ANOT";
		vi a(n);

		string t;
		ll ans = -1;

		do {
			int ind = 0;
			for(char c : ord) {
				for(int x : pos[c-'A']) { 
					a[ind++] = x;
				}
			}

			ll res = find_inversion(a);

			if(res > ans) {
				ans = res;
				t = "";

				for(char c : ord)
					t += string(pos[c-'A'].size(), c);
			}

		} while(next_permutation(all(ord)));

		cout << t << "\n";
	}

	return 0;
}
