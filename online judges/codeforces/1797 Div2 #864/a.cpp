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
        int n, m; cin >> n >> m;
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

        auto find = [&](int a, int b) {
            int cnt = 0;

            if(a == 1 or a == n) cnt++;
            if(b == 1 or b == m) cnt++;

            return 4-cnt;
        };

        cout << min(find(x1, y1), find(x2, y2)) << "\n";
    }

	
    return 0;
}


