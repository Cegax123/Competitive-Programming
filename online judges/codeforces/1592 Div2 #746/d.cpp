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

const int maxn = 1e3+5;
vector<vi> adj(maxn);

int query(const vi& a) {
    cout << "? ";
    cout << a.size() << " ";
    for(int x : a) cout << x << " ";
    
    int w; cin >> w;
    return w;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
    }

    vi a(n);
    iota(all(a), 1);

    int w = query(a);

    
	
    return 0;
}


