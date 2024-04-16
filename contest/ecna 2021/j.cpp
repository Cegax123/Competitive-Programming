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

const int maxn = 1e5+5;

int parent[maxn], sz[maxn];
int l[maxn], r[maxn];

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
    l[v] = r[v] = v;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];

        l[a] = min(l[a], l[b]);
        r[a] = max(r[a], r[b]);

        l[b] = l[a];
        r[b] = r[a];
    }
}



struct cmp {
    bool operator() (int a, int b) const  {
        return sz[a] < sz[b];
    }
};

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    vector<pair<ll, int>> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(all(a));

    vector<bool> marked(n, 0);
    set<int, cmp> s;

    ll ans = -1;
    int L = -1, R = -1;
    int currsz = 0;

    for(int i = n-1; i >= 0; i--) {
        int pos = a[i].second; ll val = a[i].first;
        
        marked[pos] = 1;
        make_set(pos);

        if(pos + 1 < n and marked[pos+1]) union_sets(pos, pos+1);
        if(pos - 1 >= 0 and marked[pos-1]) union_sets(pos, pos-1);

        pos = find_set(pos);

        if(ans == val * 1ll * sz[pos]) {
            if(L > l[pos]) {
                L = l[pos];
                R = r[pos];
                currsz = sz[pos];
            }
            else if(L == l[pos] and currsz < sz[pos]) {
                L = l[pos];
                R = r[pos];
                currsz = sz[pos];
            }
        }
        else if(ans < val * 1ll * sz[pos]) {
            ans = val * 1ll * sz[pos];
            L = l[pos];
            R = r[pos];
            currsz = sz[pos];
        }
    }

    cout << L+1 << " " << R+1 << " " << ans << "\n";
	
    return 0;
}


