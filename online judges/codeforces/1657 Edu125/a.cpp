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
        int x, y; cin >> x >> y;
        if(x == 0 and y == 0) {
            cout << 0 << "\n";
            continue;
        }

        bool cmp = 0;
        for(int i = 0; i <= 1000; i++) {
            if(i * i == x * x + y * y) cmp = 1;
        }

        if(cmp) cout << "1\n";
        else cout << "2\n";
    }
	
    return 0;
}


