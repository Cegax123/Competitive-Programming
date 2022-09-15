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

const int maxn = 1000+5;

int parent[maxn];
int sz[maxn];

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
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
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, d; cin >> n >> d;

    for(int i = 0; i < n; i++)
        make_set(i);

    int left = 1;

    for(int i = 0; i < d; i++) {
        int x, y; cin >> x >> y;
        x--; y--;

        x = find_set(x);
        y = find_set(y);

        if(x == y) left++;
        else union_sets(x, y);

        vi tmp;

        for(int j = 0; j < n; j++) {
            if(j == find_set(j)) tmp.pb(sz[j]);
        }

        sort(all(tmp));
        int ans = 0;

        for(int j = (int) tmp.size()-1; j >= (int) tmp.size()-left; j--) {
            ans += tmp[j];
        }

        cout << ans-1 << "\n";
    }


    
    return 0;
}
