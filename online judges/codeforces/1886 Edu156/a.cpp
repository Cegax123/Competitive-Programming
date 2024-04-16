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
        int n; cin >> n;
        int x = -1;
        if(n%3 == 0) {
            x -= 3;
            if(x == 1 or x == 2 or x <= 0) {
                cout << "NO\n";
                continue;
            }
            cout << 1 << " " << 2 << " " << x << "\n";
        }
        else {
            x -= 4;
            if(x == 1 or x == 3 or x <= 0) {
                cout << "NO\n";
                continue;
            }
            cout << 1 << " " << 3 << " " << x << "\n";
        }



    }

	
    return 0;
}


