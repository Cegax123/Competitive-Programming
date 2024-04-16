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
    int x0, y0, x1, y1; cin >> x0 >> y0 >> x1 >> y1;
    int n; cin >> n;

    map<ll, bool> poss;
    map<ll, int> dis;

    const int L = 1e9;

    auto to_number = [](int x, int y) {
        return (x-1) * 1ll * L + y;
    };

    auto to_coord = [](ll n) {
        ll x = n / L + 1, y = n % L;
        if(y == 0) y += L;
        
        return make_pair(x, y);
    };

    for(int i = 0; i < n; i++) {
        int r, a, b; cin >> r >> a >> b;
        for(int j = a; j <= b; j++) {
            poss[to_number(r, j)] = 1;
        }
    }

    queue<ll> q;
    q.push(to_number(x0, y0));
    dis[to_number(x0, y0)] = 0;
    

    int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
    int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

    while(!q.empty()) {
        ll u = q.front(); q.pop();
        int x = to_coord(u).first, y = to_coord(u).second;

        for(int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            ll v = to_number(nx, ny);

            if(poss[v] and dis[v] == 0 and v != to_number(x0, y0)) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }

    int ans = dis[to_number(x1, y1)];

    cout << (ans == 0 ? -1 : ans) << "\n";
	
    return 0;
}



