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
        string b[n];

        for(int i = 0; i < n; i++)
            cin >> b[i];

        vector<int> in(n, 0);
        vector<set<int>> pred(n);
        vector<vi> to(n);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(b[i][j] == '1') {
                    in[j]++;
                    pred[j].insert(i);
                    to[i].pb(j);
                }
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++)
            if(in[i] == 0) 
                q.push(i);

        vector<vi> a(n);
        while(!q.empty()) {
            int x = q.front(); q.pop();

            set<int> curr;
            for(int from : pred[x])
                for(int y : a[from])
                    curr.insert(y);

            for(int y : curr) a[x].pb(y);

            a[x].pb(x);

            for(int y : to[x]) {
                in[y]--;
                if(in[y] == 0) q.push(y);
            }
        }

        for(int i = 0; i < n; i++) {
            cout << a[i].size() << " ";
            for(int x : a[i]) cout << x+1 << " ";
            cout << "\n";
        }
    }

	
    return 0;
}


