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

const int maxn = 2005;

int p[maxn], np[maxn];
vi adj[maxn], from[maxn];
int n, m;

void recompute() {
    for(int i = 1; i <= n; i++)
        np[i] = p[i];

    queue<int> q;
    int out[n+1];
    for(int i = 1; i <= n; i++) {
        out[i] = adj[i].size();
        if(out[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int x = q.front(); q.pop();
        for(int y : from[x]) {
            np[y] = min(np[y], np[x]-1);
            out[y]--;
            if(out[y] == 0) q.push(y);
        }
    }
}

bool comp(int idx, int pos) {
    swap(pos, p[idx]);

    recompute();

    swap(p[idx], pos);

    sort(np+1, np+n+1);

    for(int i = 1; i <= n; i++) {
        if(i > np[i]) return false;
    }
    return true;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        cin >> p[i];

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        from[b].pb(a);
    }

    recompute();
    for(int i = 1; i <= n; i++)
        p[i] = np[i];

    //cout << comp(1, 1) << "\n";

    for(int i = 1; i <= n; i++) {
        int l = 1, r = p[i];

        while(l < r) {
            int m = (l+r) >> 1;
            if(comp(i, m)) r = m;
            else l = m + 1;
        }

        cout << l << " ";
    }

    return 0;
}


