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

int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, 1, -1};

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int a, b; cin >> a >> b;
        int xk, yk, xq, yq; cin >> xk >> yk >> xq >> yq;

        set<pair<int, int>> poss;

        for(int i = 0; i < 4; i++) {
            int nx = xk + dx[i] * a;
            int ny = yk + dy[i] * b;

            int diffx = abs(xq-nx), diffy = abs(yq-ny);

            if((diffx == a and diffy == b) or (diffx == b and diffy == a)) poss.insert({nx, ny});

            nx = xk + dx[i] * b;
            ny = yk + dy[i] * a;

            diffx = abs(xq-nx), diffy = abs(yq-ny);

            if((diffx == a and diffy == b) or (diffx == b and diffy == a)) poss.insert({nx, ny});
        }

        cout << poss.size() << "\n";
    }

	
    return 0;
}


