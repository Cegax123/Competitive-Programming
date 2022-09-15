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
        int n, l; cin >> n >> l;

        int a[n];

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int ans = 0;

        for(int i = 29; i >= 0; i--) {
            int cnt = 0;

            for(int j = 0; j < n; j++) 
                if((a[j] >> i)&1) cnt++;

            if(cnt >= (n+1)/2) ans |= (1 << i);
        }

        cout << ans << "\n";
    }
	
	
	return 0;
}

