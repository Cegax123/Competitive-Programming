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
    vector<vector<int>> b(n, vector<int>(n, 0));

    int curr = 1;
    int x = -1, y = 0;
    int d = 0;

    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    auto is_valid = [&](int a, int b) {
        return a >= 0 and a < n and b >= 0 and b < n;
    };

    while(true) {
        int nx = x + dx[d], ny = y + dy[d];

        if(nx == n / 2 and ny == n / 2) {
            break;
        }

        if(!is_valid(nx, ny) or b[nx][ny] != 0) {
            d = (d+1) % 4;
            continue;
        }

        b[nx][ny] = curr++;

        x = nx;
        y = ny;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == (n)/2 and j == (n)/2) {
                cout << "T ";
            }
            else {
                cout << b[i][j] << " ";
            }
        }
        cout << "\n";
    }
	
    return 0;
}


