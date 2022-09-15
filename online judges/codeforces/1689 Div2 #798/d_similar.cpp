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

// Link: https://atcoder.jp/contests/abc178/tasks/abc178_e

ii T(int x, int y) {
    return {x+y, y-x};
}

const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin >> n;
    int minX = INF, maxX = -INF, minY = INF, maxY = -INF;

    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        ii p = T(x, y);

        minX = min(minX, p.first);
        maxX = max(maxX, p.first);


        minY = min(minY, p.second);
        maxY = max(maxY, p.second);
    }
	
    cout << max(maxX-minX, maxY-minY) << "\n";
	
    return 0;
}


