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
    string rows, cols; cin >> rows >> cols;

    vector<vi> adj(n * m);

    auto connect = [&](int x, int y, int a, int b) {
        adj[x * m + y].pb(a * m + b);
    };

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(rows[i] == '>' and j+1 < m) connect(i, j, i, j+1);
            else if(rows[i] == '<' and j-1 >= 0) connect(i, j, i, j-1);
        }
    }

    for(int j = 0; j < m; j++) {
        for(int i = 0; i < n; i++) {
            if(cols[j] == 'v' and i+1 < n) connect(i, j, i+1, j);
            else if(cols[j] == '^' and i-1 >= 0) connect(i, j, i-1, j);
        }
    }

    for(int i = 0; i < n * m; i++) {
        vector<bool> used(n * m, 0);
        used[i] = 1;

        queue<int> q;
        q.push(i);

        int cnt = 1;

        while(!q.empty()) {
            int v = q.front(); q.pop();

            for(int to : adj[v]) {
                if(!used[to]) {
                    q.push(to);
                    used[to] = 1;
                    cnt++;
                }
            }
        }

        if(cnt != n * m) {
            cout << "NO\n";
            return 0;
        }
    }
	
    cout << "YES\n";
    return 0;
}


