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

int N = 8;

int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, 1, -1};

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        string board[N+1];

        for(int i = 0; i < N; i++)
            cin >> board[i];

        int x = -1, y = -1;

        for(int i = 1; i < N-1; i++) {
            for(int j = 1; j < N-1; j++) {
                bool check = 1;

                for(int d = 0; d < 4; d++) {
                    int ni = i + dx[d], nj = j + dy[d];
                    if(board[ni][nj] != '#') check = 0;
                }

                if(check) {
                    x = i + 1;
                    y = j + 1;
                }
            }
        }

        cout << x << " " << y << "\n";
    }

	
    return 0;
}


