// SOLVED

#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back 
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
typedef unsigned long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
//cout << setprecision(12) << fixed;

const int B = 450;
const int maxn = 1e5+5;

int id[maxn];
int L[maxn], R[maxn];
int lb[B], rb[B]; 
ll sum[B];
int cnt[B][maxn];

struct BIT {
    vector<ll> bit;  // binary indexed tree
    int n;

    BIT(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    BIT(vector<int> a) : BIT(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    ll sum(int r) {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    ll sum(int l, int r) {
        if(l > r) return 0;
        return sum(r) - sum(l - 1);
    }

    void add(int idx, ll delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    vi a(n);
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        id[i] = i / B;
    }

    for(int i = 0; i < B; i++) {
        lb[i] = i * B;
        rb[i] = min(n-1, lb[i] + B - 1);
    }

    for(int i = 0; i < n; i++) {
        cin >> L[i] >> R[i];
        L[i]--; R[i]--;
    }

    for(int i = 0; i < B; i++) {
        for(int j = lb[i]; j <= rb[i]; j++) {
            cnt[i][L[j]]++;
            cnt[i][R[j]+1]--;
        }

        for(int j = 1; j < n; j++)
            cnt[i][j] += cnt[i][j-1];

        for(int j = 0; j < n; j++)
            sum[i] += (ll) a[j] * cnt[i][j];
    }


    BIT ft(a);

    int q; cin >> q;
    while(q--) {
        int t; cin >> t;
        if(t == 1) {
            int x, y; cin >> x >> y;
            x--;

            int old_val = ft.sum(x, x);
            int delta = y-old_val;

            for(int i = 0; i < B; i++) 
                sum[i] += (ll) delta * cnt[i][x];

            ft.add(x, delta);
        }
        else {
            int l, r; cin >> l >> r;
            l--; r--;

            ll ans = 0;

            for(int i = id[l] + 1; i <= id[r]-1; i++) 
                ans += sum[i];

            if(id[l] == id[r]) {
                for(int i = l; i <= r; i++)
                    ans += ft.sum(L[i], R[i]);
            }
            else {
                for(int i = l; id[i] == id[l]; i++)
                    ans += ft.sum(L[i], R[i]);

                for(int i = r; id[i] == id[r]; i--)
                    ans += ft.sum(L[i], R[i]);
            }

            cout << ans << "\n";
        }
    }
	
    return 0;
}


