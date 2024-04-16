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
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;

        int r;

        cout << "+ " << n+1 << endl;
        cin >> r;
        cout << "+ " << n << endl;
        cin >> r;

        vi adj[n+1];
        vi in(n+1, 0);

        for(int i = 1; i <= n; i++) {
            if(n+1-i > i) {
                adj[i].pb(n+1-i);
                adj[n+1-i].pb(i);

                in[i]++;
                in[n+1-i]++;
            }
            if(n-i > i) {
                adj[i].pb(n-i);
                adj[n-i].pb(i);

                in[i]++;
                in[n-i]++;
            }
        }

        int st = 0;

        for(int i = 1; i <= n; i++)
            if(in[i] == 1) st = i;

        int pos[n+1];
        vector<bool> used(n+1, 0);

        vi line;

        pos[st] = 0;
        used[st] = 1;
        line.pb(st);

        while(true) {
            int nxt = -1;

            for(int to : adj[st]) {
                if(!used[to]) {
                    nxt = to;
                }
            }

            if(nxt == -1) break;

            line.pb(nxt);

            pos[nxt] = pos[st] + 1;
            used[nxt] = 1;
            st = nxt;
        }

        //for(int i  =0 ; i < n; i++)
            //cout << line[i] << " ";

        int leaf = -1, mxd = 0;
        
        for(int i = 2; i <= n; i++) {
            cout << "? " << 1 << " " << i << endl;
            int x; cin >> x;

            if(x > mxd) {
                mxd = x;
                leaf = i;
            }
        }

        vi d(n+1, -1);

        d[leaf] = 0;

        for(int i = 1; i <= n; i++) {
            if(i == leaf) continue;
            cout << "? " << leaf << " " << i << endl;
            int x; cin >> x;
            d[i] = x;
        }

        //cout << leaf << endl;

        //for(int i = 1; i <= n; i++)
            //cout << d[i] << " ";

        //cout << endl;

        cout << "! ";

        for(int i = 1; i <= n; i++)
            cout << line[d[i]] << " ";

        reverse(all(line));

        for(int i = 1; i <= n; i++)
            cout << line[d[i]] << " ";

        cout << endl;

        cin >> r;
    }

	
    return 0;
}


