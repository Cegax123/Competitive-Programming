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
        int n, x, y; cin >> n >> x >> y;
        int a[x];

        for(int i = 0; i < x; i++) {
            cin >> a[i];
            a[i]--;
        }

        sort(a, a+x);

        int ans = x-2;

        for(int i = 0; i < x; i++) {
            int nxt = (a[i] + 2) % n;
            if(nxt == a[(i+1)%x]) ans++;
        }

        cout << ans << "\n";
    }

	
    return 0;
}


