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
        int n, x; cin >> n >> x;
        vi a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        if(x <= n/2) {
            cout << "YES\n";
        }
        else {
            x = n-x;

            vi b(2 * x);

            for(int i = 0; i < x; i++) {
                b[i] = a[i];
                b[x + i] = a[n-1-i];
            }

            sort(all(b));

            for(int i = 0; i < x; i++) {
                a[i] = b[i];
                a[n-x+i] = b[i+x];
            }

            bool cmp = 1;
            for(int i = 1; i < n; i++)
                if(a[i] < a[i-1]) cmp = 0;

            cout << (cmp ? "YES\n" : "NO\n");
        }
    }

	
    return 0;
}


