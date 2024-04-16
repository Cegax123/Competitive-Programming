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
int nxt[maxn];

int col[maxn];
int h[maxn];
int cnt = 0;

void dfs(int u) {
    col[u] = 1;

    if(col[nxt[u]] == 0) {
        h[nxt[u]] = h[u] + 1;
        dfs(nxt[u]);
    }
    else if(col[nxt[u]] == 1) {
        cnt += h[u] - h[nxt[u]] + 1;
    }
    
    col[u] = 2;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;

    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        nxt[i] = x;
    }

    for(int i = 1; i <= n; i++) {
        if(col[i] == 0) {
            h[i] = 0;
            dfs(i);
        }
    }
	
    cout << cnt << "\n";
    return 0;
}


