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

const int B = 375;
const int maxn = 2500000;

int cnt[maxn], tmp[maxn];
vi rcnt, rtmp;

struct Query {
    int l, r, id;

    bool operator < (Query other) const {
        return make_pair(l / B, r) < make_pair(other.l / B, other.r);
    }
};

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    int a[n], id[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        id[i] = i / B;
    }

    vector<Query> queries;

    for(int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        l--; r--;
        queries.pb({l, r, i});
    }

    sort(all(queries));

    int last_block = -1;
    int r = -1;

    int f;
    ll curr_ans = 0;
    ll ans[m];

    for(Query Q : queries) {
        if(last_block != id[Q.l]) {
            for(int x : rcnt)
                cnt[x] = 0;

            rcnt.clear();
                
            cnt[0]++;
            rcnt.pb(0);

            f = 0;
            curr_ans = 0;

            last_block = id[Q.l];
            r = B * (id[Q.l] + 1) - 1;
        }

        while(r < Q.r) {
            r++;

            f = f ^ a[r];

            curr_ans += cnt[k ^ f];
            cnt[f]++;

            rcnt.pb(f);
        }

        ll add = 0;
        int x = 0;

        tmp[0]++;
        rtmp.pb(0);

        if(id[Q.l] == id[Q.r]) {
            for(int i = Q.l; i <= Q.r; i++) {
                x = x ^ a[i];
                add += tmp[k ^ x];
                tmp[x]++;

                rtmp.pb(x);
            }

            ans[Q.id] = add;
        }
        else {
            cnt[0]--;
            for(int i = B * (id[Q.l] + 1) - 1; i >= Q.l; i--) {
                x = x ^ a[i];
                add += tmp[k ^ x];
                tmp[x]++;

                add += cnt[k ^ x];

                rtmp.pb(x);
            }
            cnt[0]++;
            ans[Q.id] = curr_ans + add;
        }

        for(int x : rtmp)
            tmp[x] = 0;

        rtmp.clear();
    }

    for(int i = 0; i < m; i++) 
        cout << ans[i] << "\n";
	
    return 0;
}


