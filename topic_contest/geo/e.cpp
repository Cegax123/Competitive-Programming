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
        int s, h; cin >> s >> h;
        vector<vector<bool>> b(s+1, vector<bool>(s+1, false));
        vector<pair<int, int>> p(h);
        for(int i = 0; i < h; i++) {
            int x, y; cin >> x >> y;
            p[i] = {x, y};
            b[x][y] = 1;
        }

        int x=-1, y=-1;
        for(int i = s; i >= 0; i--) {
            for(int j = s; j >= 0; j--) {
                if(b[i][j]) continue;
                
                int r = min({i, j, s-i, s-j});
                
                bool cmp = true;
                for(auto e : p) {
                    int dis = (i-e.first)*(i-e.first) + (j-e.second)*(j-e.second);
                    if(dis > r*r) cmp = false;
                }

                if(cmp) x = i, y = j;
            }
        }

        cout << x << " " << y << "\n";
    }

	
    return 0;
}


