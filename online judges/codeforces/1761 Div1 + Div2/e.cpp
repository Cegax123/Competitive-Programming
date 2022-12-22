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

const int maxn = 5000;
int parent[maxn], sz[maxn];

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
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string b[n];
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }

        for(int i = 0; i < n; i++) 
            make_set(i);

        vector<vi> adj(n);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(b[i][j] == '1') {
                    adj[i].pb(j);
                    union_sets(i, j);
                }
            }
        }

        set<int> s;
        for(int i = 0; i < n; i++) {
            s.insert(find_set(i));
        }

        if(s.size() == 1) {
            cout << 0 << "\n";
            continue;
        }

        int ans = -1;

        for(int i = 0; i < n; i++) {
            int x = sz[find_set(i)];

            if(x == 1 or (int) adj[i].size()+1 < x) {
                ans = i;
            }
        }

        if(ans != -1) {
            cout << 1 << "\n";
            cout << ans+1 << "\n";
            continue;
        }

        if((int) s.size() == 2) {
            vector<int> a, c;
            for(int i = 0; i < n; i++) {
                if(find_set(i) == find_set(0)) a.pb(i);
                else c.pb(i);
            }

            assert(((int) a.size() > 1) and ((int) c.size() > 1));

            if(a.size() < c.size()) {
                cout << a.size() << "\n";
                for(int x : a)
                    cout << x+1 << " ";
                cout << "\n";
            }
            else {
                cout << c.size() << "\n";
                for(int x : c)
                    cout << x+1 << " ";
                cout << "\n";
            }
        }
        else {
            int x = -1;
            for(int i = 0; i < n; i++) {
                if(find_set(i) != find_set(0)) {
                    x = i;
                }
            }

            assert(find_set(0) != find_set(x));

            cout << 2 << "\n";
            cout << 1 << " " << x+1 << "\n";
        }
    }

	
    return 0;
}


