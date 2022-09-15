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

const int maxn = 3e5+5;

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

struct Query {
    int l, num;
};

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m; cin >> n >> m;
    int a[m+1];
    int L[n+1], R[n+1];
    vi pos[n+1];

    for(int i = 1; i <= n; i++)
        L[i] = R[i] = i;

    for(int i = 1; i <= m; i++) {
        cin >> a[i];
        pos[a[i]].pb(i);

        L[a[i]] = 1;
    }
	
    for(int i = 1; i <= n; i++) 
        pos[i].pb(m+1);

    BIT ft(m+1);

    for(int i = n; i >= 1; i--) {
        R[i] = max(R[i], i + ft.sum(1, pos[i][0]-1));
        if(pos[i][0] <= m) ft.add(pos[i][0], 1);
    }

    vector<Query> queries[m+1];

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < (int) pos[i].size(); j++) {
            if(pos[i][j]-1 >= pos[i][j-1]+1)
                queries[pos[i][j]-1].pb({pos[i][j-1]+1, i});
        }
    }

    vi last_pos(maxn, -1);

    ft = BIT(m+1);

    for(int i = 1; i <= m; i++) {
        if(last_pos[a[i]] != -1) {
            ft.add(last_pos[a[i]], -1);
        }
        last_pos[a[i]] = i;
        ft.add(last_pos[a[i]], 1);

        for(auto& q : queries[i]) {
            int l = q.l, num = q.num;

            R[num] = max(R[num], 1+ft.sum(l, i));
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << L[i] << " " << R[i] << "\n";
    }
	
	return 0;
}

