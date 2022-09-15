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

        for(int i = 0; i < 2 * n; i++)
            make_set(i);

        string s; cin >> s;
        vector<int> tmp;

        int r[2 * n];
        memset(r, -1, sizeof(r));

        for(int i = 0; i < 2 * n; i++) {
            if(s[i] == '(') {
                tmp.pb(i);
            }
            else {
                r[tmp.back()] = i;
                tmp.pop_back();
            }
        }

        for(int i = 0; i < 2 * n; i++) {
            if(r[i] != -1) {
                union_sets(i, r[i]);
            }
        }
        
        for(int i = 2 * n-1; i >= 0; i--) {
            if(r[i] == -1) continue;
            if(r[i] + 1 >= 2 * n) continue;
            else {
                int j = r[i] + 1;
                if(r[j] != -1) {
                    union_sets(i, j);
                }
            }
        }

        set<int> st;
        for(int i = 0; i < 2 * n; i++)
            st.insert(find_set(i));

        cout << st.size() << "\n";
    }

	
    return 0;
}


