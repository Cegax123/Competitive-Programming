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
    int s, t, m; cin >> s >> t >> m;
    vi L[s];

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        L[a].pb(b-s);
    }

    int c[t][t];
    memset(c, -1, sizeof(c));

    for(int i = 0; i < s; i++) {
        for(int x : L[i]) {
            for(int y : L[i]) {
                if(x >= y) continue;

                if(c[x][y] == -1) {
                    c[x][y] = i;
                }
                else {
                    cout << x+s+1 << " " << y+s+1 << " " << c[x][y]+1 << " " << i+1 << "\n";
                    return 0;
                }
            }
        }
    }

    cout << "-1\n";
	
    return 0;
}


