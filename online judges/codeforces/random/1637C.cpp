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

        int a[n+1];
        bool all_one = 1;

        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            if(i >= 2 and i < n and a[i] > 1) all_one = 0;
        }

        if(all_one) cout << "-1\n";
        else if(n == 3) {
            if(a[2]&1) cout << "-1\n";
            else cout << a[2]/2 << "\n";
        }

        else {
            ll ans = 0;

            for(int i = 2; i < n; i++)
                ans += (a[i]+1)/2;

            cout << ans << "\n";
        }
    }
	
	return 0;
}

