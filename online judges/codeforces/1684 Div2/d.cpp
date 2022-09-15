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
        int n, k; cin >> n >> k;
        int a[n];
        
        ll ans = 0;
        vi b;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            ans += a[i];
            b.pb(-a[i]+(n-1-i));
        }

        sort(all(b));
        ll global = ans;

        for(int i = 0; i < k; i++) {
            ans += b[i];
            ans -= i;

            global = min(global, ans);
        }

        

        cout << global << "\n";
    }

   
    return 0;
}


