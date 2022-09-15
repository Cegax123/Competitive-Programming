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
    int r, c; cin >> r >> c;
    int b[15][15];

    for(int i = 0; i < 15; i++) {
        for(int j = i; j < 15-i; j++) {
            b[i][j] = i&1;
            b[14-i][j] = i&1;
            b[j][i] = i&1;
            b[j][14-i] = i&1;
        }

    }

    if(b[r-1][c-1] == 0) cout << "black\n";
    else cout << "white\n";

    return 0;
}


