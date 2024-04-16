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

const int maxn = 2e5+5;
const int INF = 1e9;
const ll LLINF = (ll) 1e18;

int n, m, k, q;
ii pieces[maxn];
vi b;
ll L[maxn], R[maxn];

void init() {
    for(int i = 0; i < maxn; i++) {
        pieces[i] = {INF, -INF};
        L[i] = R[i] = LLINF;
    }

    b.resize(q);
}

ii find_ind(int x) {
    ii ans;

    int l = 0, r = q-1;
    
    while(l < r) {
        int m = (l+r+1) >> 1;
        if(b[m] <= x) l = m;
        else r = m-1;
    }

    if(b[l] <= x) ans.first = l;
    else ans.first = -1;

    l = 0, r = q-1;

    while(l < r) {
        int m = (l+r) >> 1;
        if(b[m] >= x) r = m;
        else l = m+1;
    }

    if(b[l] >= x) ans.second = l;
    else ans.second = -1;

    return ans;
}

ll get_moves(int pos, int row, int col, bool to_left) {
    ii ind = find_ind(col);
    ll res = LLINF;
    
    if(ind.first != -1) {
        int bl = b[ind.first];

        ll ans = (ll) abs(col-bl) + pos-row;

        if(to_left) ans += (ll) abs(pieces[pos].second-bl) + pieces[pos].second-pieces[pos].first;
        else ans += (ll) abs(pieces[pos].first-bl) + pieces[pos].second-pieces[pos].first;

        res = min(res, ans);
    }
    if(ind.second != -1) {
        int br = b[ind.second];

        ll ans = (ll) abs(col-br) + pos-row;

        if(to_left) ans += (ll) abs(pieces[pos].second-br) + pieces[pos].second-pieces[pos].first;
        else ans += (ll) abs(pieces[pos].first-br) + pieces[pos].second-pieces[pos].first;

        res = min(res, ans);
    }
    
    return res;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> k >> q;

    init();

    for(int i = 0; i < k; i++) {
        int x, y; cin >> x >> y;

        pieces[x].first = min(pieces[x].first, y);
        pieces[x].second = max(pieces[x].second, y);
    }

    for(int i = 0; i < q; i++) 
        cin >> b[i];

    sort(all(b));

    if(pieces[1].first == INF) {
        L[1] = R[1] = 0;
        pieces[1].first = pieces[1].second = 1;
    }
    else {
        L[1] = pieces[1].second-1 + pieces[1].second-pieces[1].first;
        R[1] = pieces[1].second-1;
    }

    int last = 1;
    ll global = min(L[1], R[1]);

    for(int i = 2; i < maxn; i++) {
        if(pieces[i].first == INF) continue;

        L[i] = min(L[i], L[last] + get_moves(i, last, pieces[last].first, 1));
        L[i] = min(L[i], R[last] + get_moves(i, last, pieces[last].second, 1));

        R[i] = min(R[i], L[last] + get_moves(i, last, pieces[last].first, 0));
        R[i] = min(R[i], R[last] + get_moves(i, last, pieces[last].second, 0));

        global = min(L[i], R[i]);
        last = i;
    }

    cout << global << "\n";
	
    return 0;
}



