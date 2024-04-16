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

ii solve() {
    int wl, dl, wr, dr; cin >> wl >> dl >> wr >> dr;
    int poss = 1;

    if(wl == 0) {
        ii result = solve();
        wl = result.first;
        if(!result.second) poss = 0;
    }

    if(wr == 0) {
        ii result = solve();
        wr = result.first;
        if(!result.second) poss = 0;
    }

    int wt = wl + wr;
    if(wl * dl != wr * dr) poss = 0;

    return {wt, poss};
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        ii result = solve();
        cout << (result.second ? "YES\n" : "NO\n");
    }
	
    return 0;
}


