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
        if(l > r) return 0;
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int q; cin >> q;
        BIT bit(n);
        int a[n];
        int cnt1 = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            bit.add(i, a[i]);
            cnt1 += a[i] == 1;
        }

        while(q--) {
            int op; cin >> op;
            if(op == 1) {
                int x; cin >> x;

                if(x == 1) {
                    if(cnt1) {
                        cout << "YES\n";
                    }
                    else {
                        cout << "NO\n";
                    }
                    continue;
                }

                int l = 0, r = n-1;
                while(l < r) {
                    int m = (l+r+1) >> 1;
                    if(bit.sum(0, m) <= x) l = m;
                    else r = m-1;
                }

                int sum = bit.sum(0, l);
                if(sum == x) {
                    cout << "YES\n";
                    continue;
                }
                if(sum != x-1) {
                    cout << "NO\n";
                    continue;
                }

                int lmt = l;
                
                if(lmt == n-1) {
                    cout << "NO\n";
                    continue;
                }

                if(bit.sum(lmt+1, lmt+1) == 1) {
                    cout << "YES\n";
                    continue;
                }

                l = lmt+1, r = n-1;
                while(l < r) {
                    int m = (l+r+1) >> 1;
                    if(bit.sum(lmt+1, m) == 2 * (m-lmt)) l = m;
                    else r = m-1;
                }

                int len = l-lmt;

                if(len <= lmt+1) {
                    if(bit.sum(0, len-1) < 2 * len) {
                        cout << "YES\n";
                    }
                    else {
                        if(l+1 < n) cout << "YES\n";
                        else cout << "NO\n";
                    }
                }
                else {
                    if(bit.sum(0, lmt) == 2 * len) {
                        if(l+1 < n) cout << "YES\n";
                        else cout << "NO\n";
                    }
                    else {
                        cout << "YES\n";
                    }
                }

            }
            else {
                int p, na; cin >> p >> na;
                p--;

                if(a[p] == 1) cnt1--;
                else cnt1++;

                int delta = na - a[p];
                a[p] = na;
                bit.add(p, delta);
            }
        }
    }

	
    return 0;
}


