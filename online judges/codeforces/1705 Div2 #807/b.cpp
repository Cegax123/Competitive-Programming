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
        int a[n];

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int ind = 0;
        ll ans = 0;

        while(ind < n) {
            if(a[ind] == 0) {
                ind++;
                continue;
            }
            
            int r = ind + a[ind];
            int tmp = ind+1;

            while(tmp < n and tmp < r) {
                r = max(r, r + a[i]);
            }

            if(r > n) {

            }
            else {
            }
        }
    }

	
    return 0;
}


