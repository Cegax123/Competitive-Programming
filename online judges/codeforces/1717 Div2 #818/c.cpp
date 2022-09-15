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
        int a[n], b[n];

        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        bool cmp = 1;

        for(int i = 0; i < n; i++) {
            if(a[i] > b[i]) cmp = 0;
            else if(a[i] < b[i]) {
                if(b[i]-b[(i+1)%n] > 1) cmp = 0;
            }
        }

        cout << (cmp ? "YES\n" : "NO\n");
    }

	
    return 0;
}


