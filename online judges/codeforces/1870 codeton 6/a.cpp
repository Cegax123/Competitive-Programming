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
        int n, k, x; cin >> n >> k >> x;
        if(k > n or k-1 > x) {
            cout << -1 << "\n";
            continue;
        }

        int sum = (k-1) * k / 2;

        int lmt = x;
        if(lmt == k) lmt --;

        sum += (n-k) * lmt;

        cout << sum << "\n";
    }

	
    return 0;
}


