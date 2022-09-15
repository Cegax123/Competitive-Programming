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
const int maxa = 1e6 + 5;
const int B = 500;

int a[maxn];
int cnt[maxa];

struct Query {
    int l, r, id;

    bool operator<(Query other) const {
        return make_pair(l / B, r) < make_pair(other.l / B, other.r);
    }
};

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q; cin >> n >> q;

    for(int i = 0; i < n; i++) 
        cin >> a[i];

    vector<Query> queries;

    for(int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        l--; r--;

        queries.pb({l, r, i});
    }

    sort(all(queries));

    ll res[q];
    ll ans = 0;
    int cur_l = 0, cur_r = -1;

    for(const Query& Q : queries) {


        while(cur_l > Q.l) {
            cur_l--;

            ans -= 1ll * a[cur_l] * cnt[a[cur_l]] * cnt[a[cur_l]];
            cnt[a[cur_l]]++;
            ans += 1ll * a[cur_l] * cnt[a[cur_l]] * cnt[a[cur_l]];
        }
        while(cur_r < Q.r) {
            cur_r++;

            ans -= 1ll * a[cur_r] * cnt[a[cur_r]] * cnt[a[cur_r]];
            cnt[a[cur_r]]++;
            ans += 1ll * a[cur_r] * cnt[a[cur_r]] * cnt[a[cur_r]];
        }

        while(cur_l < Q.l) {
            ans -= 1ll * a[cur_l] * cnt[a[cur_l]] * cnt[a[cur_l]];
            cnt[a[cur_l]]--;
            ans += 1ll * a[cur_l] * cnt[a[cur_l]] * cnt[a[cur_l]];

            cur_l++;
        }
        
        while(cur_r > Q.r) {
            ans -= 1ll * a[cur_r] * cnt[a[cur_r]] * cnt[a[cur_r]];
            cnt[a[cur_r]]--;
            ans += 1ll * a[cur_r] * cnt[a[cur_r]] * cnt[a[cur_r]];

            cur_r--;
        }

        
        res[Q.id] = ans;
    }

    for(int i = 0; i < q; i++)
        cout << res[i] << "\n";
	
    return 0;
}


