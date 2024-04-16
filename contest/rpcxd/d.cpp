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
    int n, k; cin >> n >> k;

    int ans = 0;

    for(int i = 0; i < (1 << n); i++) {
        int ind = 0;
        bool cmp = true;
        while(ind < n) {
            int x = (i >> ind)&1;
            int cnt = 0;
            while(ind < n and x == ((i >> ind)&1)) {
                ind++;
                cnt++;
            }
            if(cnt > k) cmp = false;
        }

        ans += cmp;
    }

    cout << ans << "\n";
	
    return 0;
}


