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

int n;
const int maxn = 2050;
char b[maxn+5][maxn+5];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void fill(int stx, int sty, int len, int r, int c) {
    if(len == 1) {
        return;
    }

    int cx[] = {stx, stx, stx + len/2, stx + len/2};
    int cy[] = {sty, sty + len/2, sty, sty + len/2};

    int posx[4], posy[4];

    posx[0] = stx + len/2 - 1;
    posy[0] = sty + len/2 - 1;

    posx[1] = posx[0];
    posy[1] = posy[0] + 1;

    posx[2] = posx[0] + 1;
    posy[2] = posy[0];

    posx[3] = posx[0] + 1;
    posy[3] = posy[0] + 1;

    auto cmp = [](int x, int y, int len, int r, int c) {
        return r >= x and r < x + len and c >= y and c < y + len;
    };

    int banned = -1;
    for(int i = 0; i < 4; i++) {
        if(cmp(cx[i], cy[i], len/2, r, c)) banned = i;
    }

    for(int i = 0; i < 4; i++) {
        if(banned == i) fill(cx[i], cy[i], len/2, r, c);
        else fill(cx[i], cy[i], len/2, posx[i], posy[i]);
    }

    vector<bool> used(26, 0);

    auto isValid = [&](int x, int y) {
        return x >= 0 and x < n and y >= 0 and y < n;
    };

    for(int i = 0; i < 4; i++) {
        if(banned == i) continue;
        for(int d = 0; d < 4; d++) {
            int nx = posx[i] + dx[d], ny = posy[i] + dy[d];
            if(isValid(nx, ny)) {
                if(b[nx][ny] >= 'A' and b[nx][ny] <= 'Z')
                    used[b[nx][ny]-'A']=1;
            }
        }
    }

    for(int i = 0; i < 26; i++) {
        if(!used[i]) {
            for(int j = 0; j < 4; j++) {
                if(banned == j) continue;
                b[posx[j]][posy[j]] = 'A' + i;
            }
            break;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int r, c; cin >> n >> r >> c;

    r--; c--;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            b[i][j] = '.';

    fill(0, 0, n, r, c);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << b[i][j];
        }
	    cout << "\n";
    }
    return 0;
}


