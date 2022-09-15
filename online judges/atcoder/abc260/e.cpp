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

const int maxn = 2e5 + 5;
int n, m;

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
    cin >> n >> m;
    BIT ft(n+1);

    int a[n], b[n];
    vi pos[m+1];

    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        pos[a[i]].pb(i);
        pos[b[i]].pb(i);
    }

    int r = 0;
    int ans[maxn];
    memset(ans, 0, sizeof(ans));
    
    for(int i = 1; i <= m; i++) {
        while(r <= m and ft.sum(n-1) < n) {
            for(int x : pos[r]) {
                if(ft.sum(x, x) == 0)
                    ft.add(x, 1);
            }
            
            r++;
        }

        if(ft.sum(n-1) != n) break;
        //cout << i << " " << r << endl;

        int L = r-i;
        int R = m-r+1+L;

        ans[L]++;
        ans[R+1]--;

        for(int x : pos[i]) {
            if((a[x] > i and a[x] < r) or (b[x] > i and b[x] < r)) continue;
            ft.add(x, -1);
        }
    }

    for(int i = 1; i <= m; i++) {
        ans[i] += ans[i-1];
        cout << ans[i] << " ";
    }
	
    return 0;
}


