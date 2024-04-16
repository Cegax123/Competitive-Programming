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
    int n; cin >> n;

    const int maxn = 1005;
    int c2[maxn][maxn], c5[maxn][maxn];
    memset(c2, 0, sizeof(c2));
    memset(c5, 0, sizeof(c5));
    int a[maxn][maxn];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];

            if(a[i][j] == 0) continue;

            int x = a[i][j];
            while(x % 2 == 0) {
                x /= 2;
                c2[i][j]++;
            }
            while(x % 5 == 0) {
                x /= 5;
                c5[i][j]++;
            }
        }
    }

    char p2[maxn][maxn], p5[maxn][maxn];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 and j == 0) continue;

            if(i == 0 and j) {
                p2[i][j] = p5[i][j] = 'R';

                c2[i][j] += c2[i][j-1];
                c5[i][j] += c5[i][j-1];
            }
            else if(i and j == 0) {
                p2[i][j] = p5[i][j] = 'D';

                c2[i][j] += c2[i-1][j];
                c5[i][j] += c5[i-1][j];
            }
            else {
                if(c2[i-1][j] < c2[i][j-1]) {
                    p2[i][j] = 'D';
                    c2[i][j] += c2[i-1][j];
                }
                else {
                    p2[i][j] = 'R';
                    c2[i][j] += c2[i][j-1];
                }

                if(c5[i-1][j] < c5[i][j-1]) {
                    p5[i][j] = 'D';
                    c5[i][j] += c5[i-1][j];
                }
                else {
                    p5[i][j] = 'R';
                    c5[i][j] += c5[i][j-1];
                }
            }
        }
    }

    int ans = min(c2[n-1][n-1], c5[n-1][n-1]);

    if(ans > 1) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(a[i][j] == 0) {
                    cout << 1 << "\n";
                    cout << string(i, 'D') << string(j, 'R') << string(n-1-i, 'D') << string(n-1-j, 'R') << "\n";
                    return 0;
                }
            }
        }
    }

    cout << ans << "\n";

    auto f = [&](int v[][maxn], char p[][maxn]) {
        int x = n-1; int y = n-1;

        string ans = "";
        while(x or y) {
            ans += p[x][y];
            if(p[x][y] == 'D') x--;
            else y--;
        }

        reverse(all(ans));
        cout << ans << "\n";
    };

    if(c2[n-1][n-1] < c5[n-1][n-1]) f(c2, p2);
    else f(c5, p5);

    return 0;
}


