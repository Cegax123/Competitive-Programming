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

const int maxn = 3e4 + 5;
const int maxa = 1e6+1;
const int B = 250;

int a[maxn];
int cnt[maxa];

struct Query {
    int l, r, id;

    bool operator < (Query other) const {
        return make_pair(l / B, r) < make_pair(other.l / B, other.r);
    }
};

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<Query> queries;

    int q; cin >> q;
    for(int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        l--; r--;

        queries.pb({l, r, i});
    }

    
    sort(all(queries));

    int l = 0, r = -1;
    int ans = 0;
    int res[q];

    for(Query Q : queries) {
        while(l > Q.l) {
            l--;

            if(cnt[a[l]] == 0) ans++;
            cnt[a[l]]++;
        }
        while(r < Q.r) {
            r++;

            if(cnt[a[r]] == 0) ans++;
            cnt[a[r]]++;
        }
        while(l < Q.l) {
            cnt[a[l]]--;
            if(cnt[a[l]] == 0) ans--;

            l++;
        }
        while(r > Q.r) {
            cnt[a[r]]--;
            if(cnt[a[r]] == 0) ans--;

            r--;
        }

        res[Q.id] = ans;
    }

    for(int i = 0; i < q; i++)
        cout << res[i] << "\n";
	
    return 0;
}


