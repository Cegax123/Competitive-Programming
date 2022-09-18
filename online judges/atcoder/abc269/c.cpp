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
    ll x; cin >> x;
    vi pos;

    for(int i = 0; i < 60; i++) {
        if((x >> i)&1)
            pos.pb(i);
    }

    int k = pos.size();
    for(int i = 0; i < (1 << k); i++) {
        ll curr = 0;
        for(int j = 0; j < k; j++) {
            if((i >> j)&1) curr |= (1ll << pos[j]);
        }

        cout << curr << "\n";
    }
	
    return 0;
}


