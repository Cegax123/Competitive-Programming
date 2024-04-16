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
        int n, m; cin >> n >> m;
        int k; cin >> k;
        string s; cin >> s;

        int u = 0, d = 0, l = 0, r = 0;
        int x = 0, y = 0;
        for(int i = 0; i < (int) s.size(); i++) {
            if(s[i] == 'U') x--;
            if(s[i] == 'D') x++;
            if(s[i] == 'L') y--;
            if(s[i] == 'R') y++;

            if(x < 0) u = max(u, -x);
            else d = max(d, x);

            if(y < 0) l = max(l, -y);
            else r = max(r, y);
        }

        if(u + d >= n or l + r >= m) {
            if(k == 0) cout << n * m << "\n";
            else cout << 0 << "\n";
            continue;
        }

        ii p[4];

        p[0] = {u, l};
        p[1] = {u, m-1-r};
        p[2] = {n-1-d, l};
        p[3] = {n-1-d, m-1-r};

        int d1 = p[1].second - p[0].second + 1;
        int d2 = p[2].first - p[0].first + 1;
        int lft = d1 * d2;

        if(lft < k) {
            cout << 0 << "\n";
            continue;
        }

        int N = 2 * n + 1, M = 2 * m + 1;
        vector<vi> b(N, vi(M, 0));

        x = N / 2, y = M / 2;
        b[x][y] = 1;

        for(int i = 0; i < (int) s.size(); i++) {
            if(s[i] == 'U') x++;
            if(s[i] == 'D') x--;
            if(s[i] == 'L') y++;
            if(s[i] == 'R') y--;

            b[x][y] = 1;
        }

        vector<vi> sum(N, vi(M, 0));


        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                sum[i][j] = b[i][j];
                if(i) sum[i][j] += sum[i-1][j];
                if(j) sum[i][j] += sum[i][j-1];
                if(i and j) sum[i][j] -= sum[i-1][j-1];
            }
        }

        //for(int i = 0; i < N; i++) {
            //for(int j = 0; j < M; j++) {
                //cout << b[i][j] << " ";
            //}
            //cout << endl;
        //}

        auto get_sum = [&](int a, int b, int c, int d) {
            //cout << a << " " << b << " " << c << " " << d << endl;
            if(a > c or b > d) return 0;
            //return 1;
            return sum[c][d] - (b ? sum[c][b-1] : 0) - (a ? sum[a-1][d] : 0) + (a and b ? sum[a-1][b-1] : 0);
        };

        //cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
        int need = lft-k;

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                //cout << i << " " << j << endl;
                int px = N/2 + (u-i), py = M/2 + (l-j);
                if(get_sum(px, py, min(N-1, px + d2-1), min(M-1, py + d1-1)) == need) {
                    //cout << i << " " << j << endl;
                    //cout << px << " " << py << endl;
                    ans++;
                }
            }
        }

        cout << ans << "\n";
    }

	
    return 0;
}


