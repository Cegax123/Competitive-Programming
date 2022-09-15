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

const int maxn = 40;

int n;
char b[maxn][maxn];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isValid(int x, int y) {
    return 0 <= x and x <= n+1 and 0 <= y and y <= n+1;
}

void fill(int x, int y) {
    if(b[x][y] != '.') return;
    b[x][y] = '@';

    for(int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if(!isValid(nx, ny)) continue;

        fill(nx, ny);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;

    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) 
            cin >> b[i][j];

    for(int i = 0; i <= n+1; i++) {
        for(int j = 0; j <= n+1; j++) {
            if(i > 0 and j > 0 and i < n+1 and j < n+1) continue;

            if((i == 0 and j == 0) or (i == 1 and j == 0) or (i == 0 and j == 1) or 
                    (i == n+1 and j == n+1) or (i == n and j == n+1) or (i == n+1 and j == n)) 
                b[i][j] = ' ';
            else 
                b[i][j] = '#';
        }
    }
    
    fill(1, 1);
    fill(n, n);

    int ans = 0;
    
    for(int i = 0; i <= n+1; i++) {
        for(int j = 0; j <= n+1; j++) {
            if(b[i][j] != '#') continue;

            for(int d = 0; d < 4; d++) {
                int ni = i + dx[d], nj = j + dy[d];

                if(!isValid(ni, nj)) continue;

                if(b[ni][nj] == '@')
                    ans++;
            }
        }
    }

    

    //for(int i = 0; i <= n+1; i++) {
        //for(int j = 0; j <= n+1; j++) {
            //cout << b[i][j];
        //}
        //cout << "\n";
    //}

    cout << ans * 9 << "\n";
	
    return 0;
}


