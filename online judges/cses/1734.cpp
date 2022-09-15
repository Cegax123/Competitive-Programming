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
const int B = 512;

int n, q;
int a[maxn];
int ans[maxn];

struct Query {
    int l, r, id;

    bool operator < (Query other) const {
        return make_pair(l / B, r) < make_pair(other.l / B, other.r);
    }
};

int curr_ans = 0;
int cnt[maxn];

void add(int x) {
    if(cnt[x] == 0) curr_ans++;
    cnt[x]++;
}

void remove(int x) {
    cnt[x]--;
    if(cnt[x] == 0) curr_ans--;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;

    int ind = 1;
    map<int, int> id;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(id[a[i]] == 0) id[a[i]] = ind++;
        a[i] = id[a[i]];
    }

    vector<Query> queries;

    for(int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        l--; r--;

        queries.pb({l, r, i});
    }

    sort(all(queries));
    int l = 0, r = -1;

    for(Query Q : queries) {
        while(l > Q.l) {
            l--;
            add(a[l]);
        }
        while(r < Q.r) {
            r++;
            add(a[r]);
        }
        while(l < Q.l) {
            remove(a[l]);
            l++;
        }
        while(r > Q.r) {
            remove(a[r]);
            r--;
        }

        ans[Q.id] = curr_ans;
    }

    for(int i = 0; i < q; i++)
        cout << ans[i] << "\n";
	
    return 0;
}


