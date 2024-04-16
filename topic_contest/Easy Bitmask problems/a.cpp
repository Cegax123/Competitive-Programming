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

void bin_rep(unsigned int x, bool rev=false) {
    for(int i = 31; i >= 0; i--) {
        int dig = (x >> i)&1;
        if(rev) dig ^= 1;
        
        cout << dig;
    }

    cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    unsigned int x; cin >> x;

    bin_rep(x);
    bin_rep(x, 1);

    unsigned l = x << 1;
    bin_rep(l);

    unsigned r = x >> 1;
    bin_rep(r);
   
    return 0;
}


