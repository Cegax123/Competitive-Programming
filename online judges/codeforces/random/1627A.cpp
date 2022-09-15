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
        int n, m, r, c; cin >> n >> m >> r >> c;

        char b[n+5][m+5];
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }

        bool found = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(b[i][j] == 'B') found = 1;
            }
        }

        if(found == 0) {
            cout << "-1\n";
            continue;
        }

        r--; c--;

        if(b[r][c] == 'B') {
            cout << "0\n";
            continue;
        }

        found = 0;
        for(int i = 0; i < n; i++)
            if(b[i][c] == 'B') found = 1;
        for(int i = 0; i < m; i++)
            if(b[r][i] == 'B') found = 1;

        if(found) cout << "1\n";
        else cout << "2\n";
    }
	
	
	return 0;
}

