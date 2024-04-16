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



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m; cin >> n >> m;

    vi adj[n];

    vector<vi> mat;

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    bool cmp = true;

    for(int i = 0; i < n; i++) {
        if(adj[i].empty()) {
            cmp = false;
            break;
        }
        
        vi tmp(n+1, 0);
        if((int) adj[i].size() & 1) {

            tmp[i] = 1;
            for(int x : adj[i]) tmp[x] = 1;

            tmp[n] = 0;
        }
        else {
            for(int x : adj[i]) tmp[x] = 1;
            tmp[n] = 1;
        }

        mat.pb(tmp);
    }

    if(!cmp) {
        cout << "N\n";
        return 0;
    }

    vector<bool> pivot(n, 0);

    for(int j = 0; j < n; j++) {
        int x = -1;
        for(int i = 0; i < n; i++) {
            if(!pivot[i] and mat[i][j] == 1) {
                x = i;
                break;
            }
        }

        if(x != -1) {
            for(int i = 0; i < n; i++) {
                if(i == x or mat[i][j] == 0) continue;
                for(int k = 0; k <= n; k++)
                    mat[i][k] ^= mat[x][k];
            }
            pivot[x] = 1;
        }
    }

    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < n; j++) {
            sum += mat[i][j];
        }
        if(sum == 0 and mat[i][n] == 1) cmp = false;
    }


    //for(int i = 0; i < n; i++) {
        //for(int j = 0; j <= n; j++) {
            //cout << mat[i][j] << " ";
        //}
        //cout << endl;
    //}

    cout << (cmp ? "Y\n" : "N\n");
	
    return 0;
}


