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

int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

    bool cmp = 0;

    for(int d = 0; d < 8; ++d) {
        ll nx = x1+dx[d], ny = y1+dy[d];
        ll dix = abs(nx-x2), diy = abs(ny-y2);

        if(dix * dix + diy * diy == 5) cmp = 1;
    }

    cout << (cmp ? "Yes\n" : "No\n");
	
	return 0;
}

