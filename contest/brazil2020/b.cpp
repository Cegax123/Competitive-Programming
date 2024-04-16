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
    int b[10][10];
    memset(b, 0, sizeof(b));

    auto valid = [](int x, int y) {
        return x >= 0 and x < 10 and y >= 0 and y < 10;
    };

    int n; cin >> n;
    bool cmp = true;
    for(int i = 0; i < n; i++) {
        int d; cin >> d;
        int l, r, c; cin >> l >> r >> c;
        r--; c--;

        if(d == 0)
            for(int y = c; y < c+l; y++) {
                if(!valid(r, y)) cmp = false;
                else b[r][y]++;
            }


        else 
            for(int y = r; y < r + l; y++) {
                if(!valid(y, c)) cmp = false;
                else b[y][c]++;
            }
    }

    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            if(b[i][j] > 1) cmp = false;

    cout << (cmp ? "Y" : "N") << "\n";
	
    return 0;
}


