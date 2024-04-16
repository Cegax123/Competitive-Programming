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

vector<vi> adj;

vi val, comp, z, cont;
int timer, ncomps;
int roots[maxn];

int ind = 1;

int tarjan(int j) {
    int low = val[j] = ++timer, x; z.pb(j);

    for(int to : adj[j]) {
        if(comp[to] < 0) {
            low = min(low, val[to] ?: tarjan(to));
        }
    }

    if(low == val[j]) {
        do {
            x = z.back(); z.pop_back();
            comp[x] = ncomps;
            cont.pb(x);
        } while(x != j);

        // Procesar scc
        
        for(int x : cont) {
            roots[x] = ind;
        }

        ind++;

        cont.clear();
        ncomps++;
    }

    return val[j] = low;
}



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m; cin >> n >> m;
    adj.resize(n);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
    }

    val.assign(n, 0); comp.assign(n, -1);
    for(int i = 0; i < n; i++) {
        if(comp[i] < 0) 
            tarjan(i);
    }

    cout << ncomps << "\n";
    for(int i = 0; i < n; i++) {
        cout << roots[i] << " ";
    }
	
    return 0;
}


