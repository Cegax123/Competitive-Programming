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
        vi a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        sort(all(a));

        int r = 0;
        int sum = 0;

        for(int i = 0; i < n; i++) {
            if(sum + a[i] >= n) break;
            sum += a[i];
            r = i;
        }

        cout << r+1 << "\n";
    }

	
    return 0;
}


