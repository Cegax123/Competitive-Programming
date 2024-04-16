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

const int maxn = 2005;

int c[maxn][maxn];
char t[maxn][maxn];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i = 0; i < maxn; i++)
        for(int j = 0; j < maxn; j++)
            t[i][j] = 'z'+1;


    int n, k; cin >> n >> k;
    string b[n];

    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    if(k) {
        t[0][0] = 'a';
        c[0][0] = k - (b[0][0] != 'a');
    }
    else {
        t[0][0] = b[0][0];
        c[0][0] = 0;
    }

    string ans = "";

    for(int i = 0; i < 2 * n - 2; i++) {
        int x = (i < n ? 0 : i-n+1), y = min(i, n-1);

        char tt = 'z';

        int tx = x, ty = y;

        while(tx < n and ty >= 0) {
            tt = min(tt, t[tx][ty]);

            tx++;
            ty--;
        }

        ans += tt;

        while(x < n and y >= 0) {
            if(t[x][y] == tt) {
                if(x + 1 < n) {
                    int ny = y;
                    int nx = x+1;
                    int nc = 0;
                    char nt;
                    if(c[x][y] == 0) {
                        nc = 0;
                        nt = b[nx][ny];
                    }
                    else {
                        nt = 'a';
                        if(b[nx][ny] == 'a') nc = c[x][y];
                        else nc = c[x][y]-1;
                    }

                    if(t[nx][ny] > nt) {
                        t[nx][ny] = nt;
                        c[nx][ny] = nc;
                    }
                    else if(t[nx][ny] == nt) {
                        c[nx][ny] = max(c[nx][ny], nc);
                    }
                }
                if(y + 1 < n) {
                    int ny = y+1;
                    int nx = x;
                    int nc = 0;
                    char nt;
                    if(c[x][y] == 0) {
                        nc = 0;
                        nt = b[nx][ny];
                    }
                    else {
                        nt = 'a';
                        if(b[nx][ny] == 'a') nc = c[x][y];
                        else nc = c[x][y]-1;
                    }

                    if(t[nx][ny] > nt) {
                        t[nx][ny] = nt;
                        c[nx][ny] = nc;
                    }
                    else if(t[nx][ny] == nt) {
                        c[nx][ny] = max(c[nx][ny], nc);
                    }
                }
            }

            x++;
            y--;
        }
    }

    ans += t[n-1][n-1];

    cout << ans << "\n";

    return 0;
}


