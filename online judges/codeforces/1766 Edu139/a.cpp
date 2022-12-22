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

    const int maxn = 999999;
    int ans[maxn+1];
    ans[0] = 0;

    for(int i = 1; i <= maxn; i++) {
        int x = i;
        int cnt = 0;

        while(x) {
            int d = x % 10;
            if(d) cnt++;
            x /= 10;
        }

        if(cnt == 1) ans[i] = 1;
        else ans[i] = 0;

        ans[i] += ans[i-1];
    }

    int t; cin >> t;
    while(t--) {
        int x; cin >> x;
        cout << ans[x] << "\n";
    }

	
    return 0;
}


