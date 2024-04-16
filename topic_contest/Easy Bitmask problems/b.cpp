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

void bin_rep(unsigned int x) {
    for(int i = 31; i >= 0; i--) {
        cout << ((x >> i)&1);
    }

    cout << "\n";
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    unsigned int a, b; cin >> a >> b;

    bin_rep(a & b);
    bin_rep(a | b);
    bin_rep(a ^ b);
	
    return 0;
}


