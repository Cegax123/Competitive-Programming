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

const int m = 40;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];

        int b[m][n];

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                b[i][j] = a[j]&1;
                a[j] >>= 1;
            }
        }

        bool found = 0;
        int win;
        for(int i = m-1; i >= 0; i--) {
            int sum = 0;
            for(int j = 0; j < n; j++)
                sum += b[i][j];
            if(sum%2 == 0) continue;
            else {
                found = 1;
                if(sum%4 == 1) win = 1;
                else {
                    if((n-sum)&1) win = 1;
                    else win = 0;
                }
                break;
            }
        }

        if(found) {
            if(win) cout << "WIN\n";
            else cout << "LOSE\n";
        }
        else cout << "DRAW\n";
    }
	
	
	return 0;
}