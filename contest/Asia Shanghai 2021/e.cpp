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
    int a[n];
    for(int i =0 ; i < n; i++) cin >> a[i];

    if(k == 0) {
        cout << n << "\n";
        return 0;
    }

    sort(a, a+n);

    int ans[n];

    for(int i = 0; i < n; i++) {
        int x = a[i]-k;

        int l = 0, r = i-1;
        while(l < r) {
            int m = (l+r+1) >> 1;
            if(a[m] <= x) l = m;
            else r = m-1;
        }

        if(a[l] <= x) ans[i] = ans[l] + 1;
        else ans[i] = 1;
    }

    cout << ans[n-1] << "\n";
	
    return 0;
}


