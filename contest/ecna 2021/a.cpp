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
    const int maxn = 100000;

    int f[maxn+1];

    for(int i = 1; i <= maxn; i++) f[i] = (int) 1e9;

    f[1] = 1;

    for(int i = 2; i <= maxn; i++) {
        for(int j = 2; j * j <= i; j++) {
            if(i % j  == 0 and i / j < i) {
                f[i] = min(f[i], f[j] + f[i/j]);
            }
        }

        f[i] = min(f[i], f[i-1] + 1);
        
        for(int j = 1; j < i; j++) {
            f[i] = min(f[i], f[j] + f[i-j]);
        }

        int p = 1;
        int ind = 0;

        while(true) {
            int l = i / p, r = i % p;
            p *= 10;

            if(l == i) {
                ind++;
                continue;
            }
            if(l == 0) break;

            int cd = 0;

            int x = r;

            while(x) {
                x/= 10;
                cd++;
            }

            if(cd == ind) f[i] = min(f[i], f[l] + f[r]);

            ind++;
        }
    }

    int n; cin >> n;
    cout << f[n] << "\n";
	
    return 0;
}


