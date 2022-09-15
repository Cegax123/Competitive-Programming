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

const int E = 26;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
	string s; cin >> s;

	string t = s;
	reverse(all(t));

	int last[E];
	memset(last, -1, sizeof(last));

	int nxt[n];

	for(int i = n-1; i >= 0; i--) {
		nxt[i] = last[t[i]-'a'];
		last[t[i]-'a'] = i;
	}
    
    // for(int i = 0; i < n; i++)
    //     cout << nxt[i] << " ";
    //
    // cout << endl;

    int curr[E];

    for(int i = 0; i < E; i++)
        curr[i] = last[i];

    int a[n];

    for(int i = 0; i < n; i++) {
        a[i] = curr[s[i]-'a'];
        curr[s[i]-'a'] = nxt[curr[s[i]-'a']];
    }

    // for(int i = 0; i < n; i++)
    //     cout << a[i] << " ";
	
    BIT ft(n+1);
    ll ans = 0;

    for(int i = 0; i < n; i++) {
        ans += ft.sum(a[i]+1, n);
        ft.add(a[i], 1);
    }

    cout << ans << "\n";

    return 0;
}


