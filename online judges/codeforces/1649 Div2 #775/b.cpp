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
        ll sum = 0;
        vector<ll> a(n);

        for(int i = 0; i < n; i++) {
             cin >> a[i];
             sum += a[i];
        }

        sort(all(a));

        if(a.back() == 0) {
            cout << 0 << "\n";
            continue;
        }

        if(a.back() <= (sum + 1) / 2) {
            cout << 1 << "\n";
        }
        else {
            cout << 1 + (a.back() - (sum-a.back()+1)) << "\n";
        }
    }

	
    return 0;
}


