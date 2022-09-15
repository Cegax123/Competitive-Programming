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
        int n, k, r, c; cin >> n >> k >> r >> c;
        char board[n+5][n+5];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                board[i][j] = '.';

        r--; c--;
        while(board[r][c] == '.') {
            for(int j = 0; j < n/k; j++) {
                board[r][(c + j * k) % n] = 'X';
            }
            r++; c++;
            r %= n;
            c %= n;
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
                cout << board[i][j];
            cout << "\n";
        }
    }

	
    return 0;
}


