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
        if(n%2 == 0) {
            cout << -1 << "\n";
            continue;
        }

        n = (n-1) / 2;

        vi moves;
        while(n) {
            int nxt = n/2;
            if(nxt * 2 == n) moves.pb(1);
            else moves.pb(2);
            n = nxt;
        }

        reverse(all(moves));

        cout << moves.size() << "\n";
        for(int x : moves) 
            cout << x << " ";
        cout << "\n";
    }

	
    return 0;
}


