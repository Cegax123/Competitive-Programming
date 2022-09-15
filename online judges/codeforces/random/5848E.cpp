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

    int n; cin >> n;
    int p[n+1], s[n+1];

    for(int i = 1; i <= n; i++) 
        cin >> p[i];

    for(int i = 1; i <= n; i++) 
        cin >> s[i];

    int rs[n+1], g[n+1];

    for(int i = 1; i <= n; i++) 
        rs[s[i]] = i;

    for(int i = 1; i <= n; i++) 
        g[i] = rs[p[i]];

    int ans = 0;
    vii moves;

    for(int i = 1; i <= n; i++) {
        int pos = 1;
        for(int j = 1; j <= n; j++) {
            if(g[j] == i) {
                pos = j;
                break;
            }
        }

        while(pos != i) {
            int nxt = pos-1;

            while(g[nxt] < pos) 
                nxt--;

            swap(g[pos], g[nxt]);
            ans += pos-nxt;

            moves.pb({pos, nxt});
            pos = nxt;
        }
    }

    cout << ans << "\n";
    cout << moves.size() << "\n";

    for(auto x : moves)
        cout << x.first << " " << x.second << "\n";
	
    return 0;
}


