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
        int cnt = 0;
        int a[n];

        for(int i = 0; i < n; i++) {
            cin >> a[i];
            cnt += a[i] == 2;
        }

        if(cnt & 1) {
            cout << -1 << "\n";
            continue;
        }

        int ans = 0;
        int curr = 0;
        for(int i = 0; i < n; i++) {
            curr += a[i] == 2;
            if(curr * 2 == cnt) {
                ans = i;
                break;
            }
        }
        cout << ans+1 << "\n";
    }

	
    return 0;
}


