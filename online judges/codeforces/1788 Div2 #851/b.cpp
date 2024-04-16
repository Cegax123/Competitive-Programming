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
        int a=0, b=0;

        int p10 = 1;
        int swap = 0;

        while(n) {
            int d = n % 10;

            if(d&1) {
                if(swap) {
                    a += p10 * (d/2);
                    b += p10 * ((d+1)/2);
                }
                else {
                    b += p10 * (d/2);
                    a += p10 * ((d+1)/2);
                }
                swap = 1-swap;
            }
            else {
                a += p10 * (d/2);
                b += p10 * (d/2);
            }

            n /= 10;
            p10 *= 10;
        }
        cout << a << " " << b << "\n";
    }

	
    return 0;
}


