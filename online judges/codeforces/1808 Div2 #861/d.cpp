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

const int maxa = 2e5+5;
const int maxn = maxa;

vector<vi> even(maxa), odd(maxa);

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

BIT ft(maxn);
int n, k;
int a[maxn];

int get(int L, int x) {
    int R = L+k-1;

    if(x == (L+R) / 2) return x;
    
    int diff = min(x-L, R-x);

    if(x != L+diff) return L+diff;
    else return R-diff;
}

ll ans(const vector<vi>& pos) {

    ll tmp = 0;

    for(int i = 0; i < maxa; i++) {
        if(pos[i].empty()) continue;

        for(int x : pos[i])
            ft.add(x, 1);

        for(int x : pos[i]) {
            int L = max(0, x-k+1);
            int R = min(x, (n-1)-k+1);
            
            int posL = get(L, x);
            int posR = get(R, x);

            //cout << x << " " << posL << " " << posR << endl;

            tmp += ft.sum(posL, posR);
        }

        for(int x : pos[i])
            ft.add(x, -1);
    }

    return tmp;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i%2) odd[a[i]].pb(i);
        else even[a[i]].pb(i);
    }

    ll ans_total = (ll) k * (n-k+1);

    ll rans = ans_total - (ans(odd) + ans(even));
    cout << rans / 2 << "\n";


	
    return 0;
}


