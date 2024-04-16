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
    int n, m; cin >> n >> m;

    int a[51][51];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    vi b;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] >= 0) b.pb(a[i][j]);
        
    sort(all(b));

    //for(int x : b) cout << x << " ";
    //cout << endl;

    map<int, int> pos;

    for(int i = 0; i < (int) b.size(); i++)
        pos[b[i]] = i;

    auto isvalid = [&](int x, int y) {
        return x >= 0 and x < n and y >= 0 and y < m;
    };

    auto get = [&](int stx, int sty, int dirx, int diry, int diagx, int diagy) {
        vector<vi> c;

        while(true) {
            vi here;
            int tempx = stx, tempy = sty;

            while(isvalid(tempx, tempy)) {
                if(a[tempx][tempy] >= 0) here.pb(a[tempx][tempy]);
                tempx += diagx;
                tempy += diagy;
            }

            c.pb(here);

            int nx = stx + dirx, ny = sty;

            if(isvalid(nx, ny)) {
                stx = nx;
                sty = ny;
            }
            else {
                nx = stx, ny = sty + diry;
                if(isvalid(nx, ny)) {
                    stx = nx;
                    sty = ny;
                }
                else break;
            }
        }

        int ans = 0;
        int l = 0;
        for(auto e : c) {
            for(int x : e) {
                if(!(pos[x] >= l and pos[x] < l + (int) e.size())) ans++;
            }
            l += e.size();
        }

        return ans;
    };

    int ans = n * m;

    ans = min(ans, get(0, 0, 1, 1, -1, 1));
    ans = min(ans, get(0, m-1, 1, -1, -1, -1));
    ans = min(ans, get(n-1, 0, -1, 1, 1, 1));
    ans = min(ans, get(n-1, m-1, -1, -1, 1, -1));

    cout << ans << "\n";
	
    return 0;
}


