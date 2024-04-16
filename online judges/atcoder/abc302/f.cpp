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
set<int> s[maxn];

int parent[maxn], sz[maxn];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if(s[a].size() < s[b].size()) {
            for(int x : s[a])
                s[b].insert(x);
            s[a].clear();
        }
        else {
            for(int x : s[b])
                s[a].insert(x);
            s[b].clear();
        }

        if (sz[a] < sz[b]) 
            swap(a, b);

        if(s[a].empty()) s[a].swap(s[b]);

        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m; cin >> n >> m;

    for(int i = 0; i < n; i++)
        make_set(i);

    vector<int> ch[m];

    for(int i = 0; i < n; i++) {
        int a; cin >> a;

        for(int j = 0; j < a; j++) {
            int x; cin >> x;
            x--;
            s[i].insert(x);
            ch[x].pb(i);
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 1; j < (int) ch[i].size(); j++) {
            union_sets(ch[i][0], ch[i][j]);
        }
    }

    bool ans = 0;
    for(int i = 0; i < n; i++) {
        if((int) s[i].size() == m)
            ans = 1;
    }
    cout << (ans ? "Yes\n" : "No\n");
	
    return 0;
}


